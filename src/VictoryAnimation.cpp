/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
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
