/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

/*
*	CLASS SPIRAL ANIMATION
*	A rotating spiral
*/

#pragma once

#include "Animation.h"

class AnimationSpiral : public Animation
{
	Q_OBJECT
		
	public slots:
		virtual void slotTimeout();
		virtual void slotDemarrer();
		
	signals:
		virtual void animationTerminee(int); // Pour indiquer à ListeAnimation que le temps est venu de détruire cet individu

	public:
	//Constructeur
		AnimationSpiral(bool toTheRight, CarteG *carte, int duree=0, QPointF depart=QPointF(0, 0), QGraphicsItem *parent=NULL);	

	//Destructeur
		virtual ~AnimationSpiral();

	protected:
		int rho;
		qreal theta;
		qreal flipAngle;
		bool toTheRight;
};
