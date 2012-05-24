/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

#include "AnimationsDonne.h"

/*************************
*	CONSTRUCTEUR	*
*************************/

AnimationsDonne::AnimationsDonne(int duree, CarteG **cartes, QPointF depart, QGraphicsItem *parent) : Animations(duree/52, true)
{
	for (int i=0; i<52; i++)
	{
		cartes[i]->hide();
		Animation *trans = new AnimationTranslation(cartes[i], duree, depart, cartes[i]->scenePos(), parent, true, true, NULL, 100-i);
		ajouterAnimation(trans);
	}
}
