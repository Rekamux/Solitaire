/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

#include "AnimationsPlacerTas.h"

/*************************
*	CONSTRUCTEUR	*
*************************/

AnimationsPlacerTas::AnimationsPlacerTas(int duree, CarteG *dessus, QPointF posDessusDepart, QPointF posDessusArrivee, Quinconce *tas, QGraphicsItem *parent) : Animations(0, true)
{
	for (int i=0; i<tas->nombre(); i++)
		tas->at(i)->hide();
	Animation *transDessus = new AnimationTranslation(dessus, duree+1*duree/13, posDessusDepart, posDessusArrivee, parent, false, true, NULL, 99);
	ajouterAnimation(transDessus);
	for (int i=0; i<tas->nombre(); i++)
	{
		QPointF depart = posDessusDepart + QPointF(0, 15*(i+1));
		QPointF arrivee = posDessusArrivee + QPointF(0, 15*(i+1));
		Animation *transElmt = new AnimationTranslation(tas->getCarte(tas->nombre()-1-i), duree+(i+2)*duree/13, depart, arrivee, parent, false, true, NULL, 100+i);
		ajouterAnimation(transElmt);
	}
}
