/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

#include "BDD.h"

#include <QMessageBox>
#include <iostream>

using namespace std;

/****************************
*	CONSTRUCTEURS		*
****************************/

BDD::BDD() : QList<BDDElement*>()
{}

BDD::BDD(QString chemin) : QList<BDDElement*>()
{
	if (!QFile::exists(chemin))
		return;
	QFile fichier(chemin);
	if(!fichier.open(QIODevice::ReadOnly))
	{
		cerr<<"Droits incorrects : "<<chemin.toStdString();
		return;
	}
	QTextStream stream(&fichier);
	QString ligne = stream.readLine();
	if (!ligne.contains("<BDD_par_Ax>"))
	{
		cerr<<"Fichier non valide : premi�re ligne: "<<ligne.toStdString()<<endl;
		return;
	}
	ligne = stream.readLine();
	bool termine = false;
	BDDElement *element = NULL;
	while (!termine)
	{
		if (ligne.contains("</BDD_par_Ax>"))
			termine = true;
		else
		{
			if (ligne.startsWith("</") && ligne.endsWith(">"))
			{
				ligne.remove("</");
				ligne.remove(">");
				if (element == NULL)
				{
					cerr<<"Fin d'�l�ment sans commencement "<<ligne.toStdString()<<endl;
					return;
				}	
				if (ligne != element->getNom())
				{
					cerr<<"Changement de cat�gorie non autoris�e "<<ligne.toStdString()<<"!="<<element->getNom().toStdString()<<endl;
					return;
				}
				else
					element = NULL;
			}
			else if (ligne.startsWith("<") && ligne.endsWith(">"))
			{
				ligne.remove("<");
				ligne.remove(">");
				element = new BDDElement(ligne);
				push_back(element);
			}
			else
			{
				if (element == NULL)
				{
					cerr<<"Attributs hors �l�ment "<<ligne.toStdString()<<endl;
					return;
				}
				element->ajouterAttribut(ligne);
			}	
			if (stream.atEnd() && !termine)
			{
				cerr<<"Fin pr�matur�e dans le fichier "<<chemin.toStdString()<<", </BDD_par_Ax> attendu"<<endl;
				return;
			}
		}
		ligne = stream.readLine();
	}
}

/***********************
*	DESTRUCTEUR	*
***********************/

BDD::~BDD()
{
	for (int i=0; i<size(); i++)
		if (this->operator[](i)!=NULL)
			delete this->operator[](i);
}

/****************************
*	AJOUTER ELEMENT	*
****************************/

void BDD::ajouterElement(BDDElement *element)
{
	push_front(element);
}

/*****************************
*	RETIRER ELEMENT	*
*****************************/

bool BDD::retirerElement(QString element)
{
	int i=0;
	while (i<size())
	{
		if (at(i)->getNom() == element)
		{
			delete this->operator[](i);
			this->operator[](i) = NULL;
			removeAt(i);
			i=size()+1;
		}
		i++;
	}
	return (i==size()+1);
}

/****************************
*	ENREGISTRER SOUS	*
****************************/

bool BDD::enregistrerSous(QString chemin)
{
	QFile fichier(chemin);
	if(!fichier.open(QIODevice::WriteOnly | QIODevice::Truncate))
		return false;
	else
	{
		QTextStream stream(&fichier);
		stream << "<BDD_par_Ax>\n";
		for (int i=0; i<size(); i++)
		{
			stream << "<" << at(i)->getNom() << ">\n";
			for (int j=0; j<at(i)->size(); j++)
				stream << at(i)->at(j) << "\n";
			stream << "</" << at(i)->getNom() << ">\n";
		}
		stream << "</BDD_par_Ax>\n";
	}
		
	fichier.close();
	return true;
}

