/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "AnimationRotationY.h"

/*************************
*	CONSTRUCTEUR	*
*************************/

AnimationRotationY::AnimationRotationY(CarteG *carte, int duree, QPointF depart, QGraphicsItem *parent, bool carteCacheeDepart, bool montre, CarteG *copieUtilisee, int zValue) : Animation(carte, duree, parent, depart, montre, copieUtilisee, zValue)
{
	angleCourant = 180;
	cacheeDepart = carteCacheeDepart;
}

/********************
*	DESTRUCTEUR	*
********************/

AnimationRotationY::~AnimationRotationY()
{}

/*************************
*	SLOT TIMEOUT		*
*************************/

void AnimationRotationY::slotTimeout()
{
	if (passages >= (duree/intervalle))
	{
		if (montreQuandTermine)
			carteOrigine->show();	
		emit animationTerminee(getId());
	}
	else
	{
		passages++;
		angleCourant -= 180*intervalle/duree;
		copie->setTransform(QTransform().translate(71, 0).rotate(angleCourant, Qt::YAxis));
		if (angleCourant<=90)
			copie->setCache(false);
	}
}
