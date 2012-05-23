/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

#include "AnimationsRetourner.h"

/*************************
*	CONSTRUCTEUR	*
*************************/

AnimationsRetourner::AnimationsRetourner(int duree, CarteG *carte, QPointF pos, QGraphicsItem *parent, bool cacheeDepart, bool aGauche) : Animations(duree/2, true)
{
	if (aGauche)
	{
		Animation *rotat = new AnimationRotationY(carte, 3*duree/8, pos-QPointF(71, 0), parent, !cacheeDepart, true);
		Animation *trans = new AnimationTranslation(carte, duree/2, pos, pos-QPointF(71, 0), parent, cacheeDepart, false);
		ajouterAnimation(trans);
		ajouterAnimation(rotat);
	}
	else
	{
		Animation *rotat = new AnimationRotationY(carte, 3*duree/8, pos, parent, cacheeDepart, false);
		Animation *trans = new AnimationTranslation(carte, duree/2, pos+QPointF(71, 0), pos, parent, !cacheeDepart, true);
		ajouterAnimation(rotat);
		ajouterAnimation(trans);
	}
}
