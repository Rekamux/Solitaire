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
*	CLASSE ANIMATIONS RETOURNER
*	Animation d'une carte qui se retourne
*/

#ifndef ANIMATIONSRETOURNER_H
#define ANIMATIONSRETOURNER_H

#include "Animations.h"
#include "AnimationRotationY.h"
#include "AnimationTranslation.h"

class AnimationsRetourner : public Animations
{
	Q_OBJECT
		
	public:
	//Constructeur
		AnimationsRetourner(int duree, CarteG *carte, QPointF pos, QGraphicsItem *parent=NULL, bool cacheeDepart=true, bool aGauche=false);
};

#endif
