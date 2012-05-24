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
		void animationTerminee(int);//Pour indiquer � ListeAnimation que le temps est venu de d�truire cet individu
		void carteLibre(int);//Pour indiquer � Widget que la carte est de nouveau non colori�e

	public:
	//Constructeur
		AnimationColoration(CarteG *carte, int duree=0, QPointF pos=QPointF(0, 0), QGraphicsItem *parent=NULL);	

	//Destructeur
		virtual ~AnimationColoration();
};

#endif
