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
*	CLASSE BASE DE DONNE
*	Gestion de fichiers de configuration
*
*	Constitu� d'un pseudo arbre dom avec un systeme de balises
*	Peut lire � partir d'un fichier texte sa structure et l'enregistrer.
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
