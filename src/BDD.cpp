/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "BDD.h"

#include <QMessageBox>

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
		QMessageBox::critical(0, QObject::tr("Droits incorrects"), chemin);
		return;
	}
	QTextStream stream(&fichier);
	QString ligne = stream.readLine();
	if (!ligne.contains("<BDD_par_Ax>"))
	{
		QMessageBox::critical(0, QObject::tr("Fichier non valide"), QObject::tr("Première ligne:")+ligne);
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
					QMessageBox::critical(0, QObject::tr("Fin d'élément sans commencement"), ligne);
					return;
				}	
				if (ligne != element->getNom())
				{
					QMessageBox::critical(0, QObject::tr("Changement de catégorie non autorisée"), ligne+"!="+element->getNom());
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
					QMessageBox::critical(0, QObject::tr("Attributs hors élément"), ligne);
					return;
				}
				element->ajouterAttribut(ligne);
			}	
			if (stream.atEnd() && !termine)
			{
				QMessageBox::critical(0, QObject::tr("Fin prématurée dans le fichier ")+chemin, QObject::tr("</BDD_par_Ax> attendu"));
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

