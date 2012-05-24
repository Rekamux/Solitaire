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
*	CLASSE RECEVEUR DONNE GRAPHIQUE
*	L'emplacement où se trouvent les cartes retournées de la donne
*
*	Hérite de LieuG
*/

#ifndef RECEVEURDONNEG_H
#define RECEVEURDONNEG_H

#include "LieuG.h"

#include <QGraphicsRectItem>
#include <QGraphicsWidget>

class ReceveurDonneG : public LieuG
{
	public:
	//Constructeurs
		ReceveurDonneG();					//Tas vide
	//Destructeurs
		~ReceveurDonneG();
		
	//Modificateurs
		bool ajouterCarte(CarteG *carte, int pos = 0);	//Ajoute une carte décalée de pos
		bool ajouterCartes(Cartes &tas);	//Ajoute un tas de cartes
		CarteG *retirerCarte();
};

#endif
