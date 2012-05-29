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
*	CLASS VICTORY ANIMATION
*	Goal slot animation in case of victory
*/

#pragma once

#include "Animations.h"
#include "Cartes.h"

class VictoryAnimation : public Animations
{
	Q_OBJECT
		
	public:
	//Constructeur
		VictoryAnimation(bool toTheRight, int duree, Cartes *cartes, QPointF depart, QGraphicsItem *parent=NULL);
};
