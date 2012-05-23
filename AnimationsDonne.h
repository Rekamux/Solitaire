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

#ifndef ANIMATIONSDONNE_H
#define ANIMATIONSDONNE_H

#include "Animations.h"
#include "AnimationsRetourner.h"
#include "AnimationTranslation.h"

class AnimationsDonne : public Animations
{
	Q_OBJECT
		
	public:
	//Constructeur
		AnimationsDonne(int duree, CarteG **cartes, QPointF depart, QGraphicsItem *parent=NULL);
};

#endif
