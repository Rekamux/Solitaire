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
*	CLASSE DONNE GRAPHIQUE
*	La donne
*
*	H�rite de LieuG
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
		DonneG(const Cartes &cartes, QPixmap dessin=QPixmap());//A partir de ces �l�ments
	//Destructeurs
		~DonneG();
		
	//Modificateurs
		bool ajouterCarte(CarteG *carte);					//Ajoute une carte
		bool ajouterCartes(Cartes &tas);					//Ajoute un tas de cartes
};

#endif
