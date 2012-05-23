/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "AnimationsRetournerDonne.h"

/*************************
*	CONSTRUCTEUR	*
*************************/

AnimationsRetournerDonne::AnimationsRetournerDonne(int duree, CarteG *carte, QPointF depart, QPointF arrivee, QGraphicsItem *parent, int zValue, bool envers) : Animations(duree/2, true)
{
	if (!envers)
	{
		Animation *rotat = new AnimationRotationY(carte, 3*duree/8, depart, parent, true, false, NULL, zValue);
		Animation *trans = new AnimationTranslation(carte, duree/2, depart+QPointF(71, 0), arrivee, parent, false, true, NULL, zValue);
		ajouterAnimation(rotat);
		ajouterAnimation(trans);
	}
	else
	{
		Animation *rotat = new AnimationRotationY(carte, 3*duree/8, depart, parent, false, false, NULL, zValue);
		Animation *trans = new AnimationTranslation(carte, duree/2, depart+QPointF(71, 0), arrivee, parent, true, true, NULL, zValue);
		ajouterAnimation(rotat);
		ajouterAnimation(trans);
	}
}
