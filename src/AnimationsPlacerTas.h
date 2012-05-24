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
*	CLASSE ANIMATIONS PLACER TAS
*	Animation d'une tas de cartes qui vient se déposer à l'emplacement prévu
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
