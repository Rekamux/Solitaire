/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
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
