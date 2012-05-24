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
*	CLASSE ANIMATION COLORATION
*	Colorie une carte
*/

#ifndef ANIMATIONCOLORATION_H
#define ANIMATIONCOLORATION_H

#include "Animation.h"
#include <QPixmap>
#include <QPainter>

class AnimationColoration : public Animation
{
	Q_OBJECT
		
	public slots:
		virtual void slotTimeout();
		virtual void slotDemarrer();
		
	signals:
		void animationTerminee(int);//Pour indiquer à ListeAnimation que le temps est venu de détruire cet individu
		void carteLibre(int);//Pour indiquer à Widget que la carte est de nouveau non coloriée

	public:
	//Constructeur
		AnimationColoration(CarteG *carte, int duree=0, QPointF pos=QPointF(0, 0), QGraphicsItem *parent=NULL);	

	//Destructeur
		virtual ~AnimationColoration();
};

#endif
