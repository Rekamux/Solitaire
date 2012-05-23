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
*	CLASSE ANIMATIONS PLACER TAS
*	Animation d'une tas de cartes qui vient se d�poser � l'emplacement pr�vu
*/

#ifndef ANIMATIONSPLACERTAS_H
#define ANIMATIONSPLACERTAS_H

#include "Animations.h"
#include "AnimationTranslation.h"
#include "Quinconce.h"

class AnimationsPlacerTas : public Animations
{
	Q_OBJECT
		
	public:
	//Constructeur
		AnimationsPlacerTas(int duree, CarteG *dessus, QPointF posDessusDepart, QPointF posDessusArrivee, Quinconce *tas, QGraphicsItem *parent=NULL);
};

#endif
