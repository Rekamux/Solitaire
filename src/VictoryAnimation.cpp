/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "VictoryAnimation.h"
#include "AnimationSpiral.h"

/*************************
*	CONSTRUCTEUR	*
*************************/

VictoryAnimation::VictoryAnimation(bool toTheRight, int duree, Cartes *cartes, QPointF depart, QGraphicsItem *parent) : Animations(duree/13, true)
{
	for (int i=0; i<13; i++)
	{
		cartes->getCarte(i)->hide();
		Animation *trans = new AnimationSpiral(toTheRight, cartes->getCarte(i), duree, depart, parent);
		ajouterAnimation(trans);
	}
}
