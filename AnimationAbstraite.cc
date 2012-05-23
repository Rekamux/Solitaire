/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "AnimationAbstraite.h"
/****************************
*	CONSTRUCTEUR		*
****************************/

AnimationAbstraite::AnimationAbstraite()
{
	passages = 0;
	estLancee = false;
	timer = new QTimer(this);
	timer->setInterval(intervalle);
	connect(timer, SIGNAL(timeout()), this, SLOT(slotTimeout()));
}

/********************
*	DESTRUCTEUR	*
********************/

AnimationAbstraite::~AnimationAbstraite()
{}

/***************
*	GET ID	*
***************/

int AnimationAbstraite::getId() const
{
	int retour = -2;
	if (timer != NULL)
		retour = timer->timerId();
	return retour;
}

/***********************
*	GET EST LANCEE	*
***********************/

bool AnimationAbstraite::getEstLancee() const
{
	return estLancee;
}

/******************************
*	ATTRIBUT STATIQUE	*
******************************/

int AnimationAbstraite::intervalle = 1000/50; //Avoir 50 images par seconde
