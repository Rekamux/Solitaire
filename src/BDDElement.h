/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

/*
*	CLASSE BASE DE DONNEE ELEMENT
*	Un element de la base de donnee
*
*	Constitué d'une liste d'attributs et d'un nom d'élément
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
		
		//Retirer un attribut renvoie le résultat
		virtual bool retirerAttribut(QString attribut);
		
		//Recuperer le nom
		virtual QString getNom() const;
		
		//Changer le nom
		virtual void setNom(QString);
		
	protected:
		QString nom;
};

#endif
