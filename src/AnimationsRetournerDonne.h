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
*	CLASSE ANIMATIONS RETOURNER DONNE
*	Animation d'une carte qui va de la donne à l'emplacement de donne
*/

#ifndef ANIMATIONSRETOURNERDONNE_H
#define ANIMATIONSRETOURNERDONNE_H

#include "Animations.h"
#include "AnimationRotationY.h"
#include "AnimationTranslation.h"

class AnimationsRetournerDonne : public Animations
{
	Q_OBJECT
	public:
	//Constructeur
		AnimationsRetournerDonne(int duree, CarteG *carte, QPointF depart, QPointF arrivee, QGraphicsItem *parent, int zValue=100, bool envers=false);
};

#endif
