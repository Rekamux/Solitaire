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
*	CLASSE ANIMATION ROTATION Y
*	G�re une simple rotation selon l'axe Y
*/

#ifndef ANIMATIONROTATIONY_H
#define ANIMATIONROTATIONY_H

#include "Animation.h"

class AnimationRotationY : public Animation
{
	Q_OBJECT
		
	public slots:
		virtual void slotTimeout();
		
	signals:
		virtual void animationTerminee(int);//Pour indiquer � ListeAnimation que le temps est venu de d�truire cet individu
		
	public:
	//Constructeur
		AnimationRotationY(CarteG *carte, int duree=0, QPointF depart=QPointF(0, 0), QGraphicsItem *parent=NULL, bool carteCacheeDepart=true, bool montre=true, CarteG *copieUtilisee=NULL, int zValue=100);

	//Destructeur
		virtual ~AnimationRotationY();
		
	protected:
		qreal angleCourant;		//L'angle de rotation en cours
		bool cacheeDepart;		//Si la carte �tait cach�e au d�but de l'animation
};

#endif
