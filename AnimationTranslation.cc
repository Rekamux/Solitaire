/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

#include "AnimationTranslation.h"

/*************************
*	CONSTRUCTEUR		*
*************************/
AnimationTranslation::AnimationTranslation(CarteG *carte, int duree, QPointF depart, QPointF arrivee, QGraphicsItem *parent, bool cache, bool montre, CarteG *copieUtilisee, int zValue) : Animation(carte, duree, parent, depart, montre, copieUtilisee, zValue)
{
	this->arrivee = arrivee;
		
	montreQuandTermine=montre;

	this->duree = duree;	
	
	carteCachee = cache;
}

/********************
*	DESTRUCTEUR	*
********************/

AnimationTranslation::~AnimationTranslation()
{}

/*************************
*	SLOT TIMEOUT		*
*************************/

void AnimationTranslation::slotTimeout()
{
	if (passages >= (qreal)duree/intervalle-1)
	{
		if (montreQuandTermine)
			carteOrigine->show();
		emit animationTerminee(getId());
	}
	else
	{
		passages++;
		QPointF depl = (arrivee-depart)*passages*intervalle/duree;
		copie->setPos(depart+depl);
	}
}

/***********************
*	SLOT DEMARRER	*
***********************/

void AnimationTranslation::slotDemarrer()
{
	Animation::slotDemarrer();		
	copie->setCache(carteCachee);
}
