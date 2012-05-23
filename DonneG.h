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
*	CLASSE DONNE GRAPHIQUE
*	La donne
*
*	Hérite de LieuG
*/

#ifndef DONNEG_H
#define DONNEG_H

#include "LieuG.h"

#include <QGraphicsRectItem>
#include <QGraphicsWidget>
#include <QPixmap>

class DonneG : public LieuG
{
	public:
	//Constructeurs
		DonneG(QPixmap dessin);						//Tas vide
		DonneG(const Cartes &cartes, QPixmap dessin=QPixmap());//A partir de ces éléments
	//Destructeurs
		~DonneG();
		
	//Modificateurs
		bool ajouterCarte(CarteG *carte);					//Ajoute une carte
		bool ajouterCartes(Cartes &tas);					//Ajoute un tas de cartes
};

#endif
