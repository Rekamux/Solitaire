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
*	CLASSE BASE DE DONNE
*	Gestion de fichiers de configuration
*
*	Constitué d'un pseudo arbre dom avec un systeme de balises
*	Peut lire à partir d'un fichier texte sa structure et l'enregistrer.
*/

#ifndef BDD_H
#define BDD_H

#include "BDDElement.h"

#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QObject>

class BDD : public QList<BDDElement*>
{
	public:
	
		//Constructeurs
		BDD();
		BDD(QString Fichier);
		
		//Destructeur
		virtual ~BDD();
		
		//Ajouter un element
		virtual void ajouterElement(BDDElement *);
		//Retirer une element
		virtual bool retirerElement(QString element);
		
		//Enregistrer sous
		virtual bool enregistrerSous(QString Fichier);
};

#endif
