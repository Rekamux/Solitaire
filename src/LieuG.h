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
*	CLASSE LIEU GRAPHIQUE (PSEUDO ABSTRAITE)
*	Tout ce qui peut stocker graphiquement des carteG
*
*	H�rite de Cartes et de QGraphicsWidget
*/

#ifndef LIEUG_H
#define LIEUG_H

#include "Cartes.h"

#include <QGraphicsRectItem>
#include <QGraphicsWidget>

class LieuG : public QGraphicsWidget, public Cartes
{
	protected:
		CarteG *supportDessin;					//Dessin repr�sentant le widget (une carte en fait)
		
	public:
	//Constructeurs
		LieuG();											//Tas vide
		LieuG(QPixmap dessin);								//Tas vide
		LieuG(const Cartes &cartes, QPixmap dessin);		//A partir de ces �l�ments
		LieuG(const Cartes &cartes);						//A partir de ces �l�ments
	//Destructeurs
		virtual ~LieuG();
		
	//Modificateurs
		virtual bool ajouterCarte(CarteG *carte);					//Ajoute une carte
		virtual bool ajouterCartes(Cartes &tas);					//Ajoute un tas de cartes
		virtual bool retournerCarteCachee();						//Retourne la carte du dessus s'il y lieu (bool�en retourn�)
		virtual CarteG *getSupportDessin();				//Le rectangle repr�sentant le widget
};

#endif
