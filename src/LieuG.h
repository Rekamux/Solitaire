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
*	CLASSE LIEU GRAPHIQUE (PSEUDO ABSTRAITE)
*	Tout ce qui peut stocker graphiquement des carteG
*
*	Hérite de Cartes et de QGraphicsWidget
*/

#ifndef LIEUG_H
#define LIEUG_H

#include "Cartes.h"

#include <QGraphicsRectItem>
#include <QGraphicsWidget>

class LieuG : public QGraphicsWidget, public Cartes
{
	protected:
		CarteG *supportDessin;					//Dessin représentant le widget (une carte en fait)
		
	public:
	//Constructeurs
		LieuG();											//Tas vide
		LieuG(QPixmap dessin);								//Tas vide
		LieuG(const Cartes &cartes, QPixmap dessin);		//A partir de ces éléments
		LieuG(const Cartes &cartes);						//A partir de ces éléments
	//Destructeurs
		virtual ~LieuG();
		
	//Modificateurs
		virtual bool ajouterCarte(CarteG *carte);					//Ajoute une carte
		virtual bool ajouterCartes(Cartes &tas);					//Ajoute un tas de cartes
		virtual bool retournerCarteCachee();						//Retourne la carte du dessus s'il y lieu (booléen retourné)
		virtual CarteG *getSupportDessin();				//Le rectangle représentant le widget
};

#endif
