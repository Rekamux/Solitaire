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
*	CLASSE ANIMATION ROTATION Y
*	Gère une simple rotation selon l'axe Y
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
		virtual void animationTerminee(int);//Pour indiquer à ListeAnimation que le temps est venu de détruire cet individu
		
	public:
	//Constructeur
		AnimationRotationY(CarteG *carte, int duree=0, QPointF depart=QPointF(0, 0), QGraphicsItem *parent=NULL, bool carteCacheeDepart=true, bool montre=true, CarteG *copieUtilisee=NULL, int zValue=100);

	//Destructeur
		virtual ~AnimationRotationY();
		
	protected:
		qreal angleCourant;		//L'angle de rotation en cours
		bool cacheeDepart;		//Si la carte était cachée au début de l'animation
};

#endif
