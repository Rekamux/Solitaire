/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
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
		virtual void animationTerminee(int); // Pour indiquer � ListeAnimation que le temps est venu de d�truire cet individu

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
