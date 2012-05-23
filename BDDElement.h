/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

/*
*	CLASSE BASE DE DONNEE ELEMENT
*	Un element de la base de donnee
*
*	Constitu� d'une liste d'attributs et d'un nom d'�l�ment
*/

#ifndef BDDELEMENT_H
#define BDDELEMENT_H

#include <QStringList>
#include <QString>

class BDDElement : public QStringList
{
	public:
		//Constructeur
		BDDElement(QString nom);
		
		//Destructeur
		virtual ~BDDElement();
		
		//Ajouter un attribut
		virtual void ajouterAttribut(QString attribut);
		
		//Retirer un attribut renvoie le r�sultat
		virtual bool retirerAttribut(QString attribut);
		
		//Recuperer le nom
		virtual QString getNom() const;
		
		//Changer le nom
		virtual void setNom(QString);
		
	protected:
		QString nom;
};

#endif
