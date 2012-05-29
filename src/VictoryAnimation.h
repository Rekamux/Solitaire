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
