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
*	CLASSE RECEVEUR DONNE GRAPHIQUE
*	L'emplacement o� se trouvent les cartes retourn�es de la donne
*
*	H�rite de LieuG
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
		bool ajouterCarte(CarteG *carte, int pos = 0);	//Ajoute une carte d�cal�e de pos
		bool ajouterCartes(Cartes &tas);	//Ajoute un tas de cartes
		CarteG *retirerCarte();
};

#endif
