/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "AnimationSpiral.h"
#include <math.h>

/*************************
*	CONSTRUCTEUR		*
*************************/
AnimationSpiral::AnimationSpiral(bool toTheRight, CarteG *carte, int duree, QPointF depart, QGraphicsItem *parent):
	Animation(carte, duree, parent, depart, false, NULL, 0),
	rho(0),
	theta(0),
	flipAngle(0),
	toTheRight(toTheRight)
{
	carteOrigine->show();
	copie->setCache(false);
}

/********************
*	DESTRUCTEUR	*
********************/

AnimationSpiral::~AnimationSpiral()
{}

/*************************
*	SLOT TIMEOUT		*
*************************/

void AnimationSpiral::slotTimeout()
{
	copie->setCache(false);
	if (passages >= (qreal)duree/intervalle-1) {
		emit animationTerminee(getId());
	}
	else
	{
		passages++;
		QPointF depl(rho*cos(theta), rho*sin(theta));
		rho += toTheRight?1:2;
		theta += toTheRight?0.1:-0.1;
		flipAngle += 10;
		if (flipAngle >= 90) {
			copie->setCache(true);
		}
		if (flipAngle >= 270) {
			copie->setCache(false);
		}
		if (flipAngle >= 360) {
			flipAngle -= 360;
		}
		copie->setPos(depart+depl);
		copie->setTransform(QTransform().rotate(flipAngle, Qt::YAxis));
	}
}

/***********************
*	SLOT DEMARRER	*
***********************/

void AnimationSpiral::slotDemarrer()
{
	Animation::slotDemarrer();
	carteOrigine->hide();
}
