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
*	CLASSE ANIMATION TRANSLATION
*	G�re une simple translation
*/

#ifndef ANIMATIONTRANSLATION_H
#define ANIMATIONTRANSLATION_H

#include "Animation.h"

class AnimationTranslation : public Animation
{
	Q_OBJECT
		
	public slots:
		virtual void slotTimeout();
		virtual void slotDemarrer();
		
	signals:
		virtual void animationTerminee(int);//Pour indiquer � ListeAnimation que le temps est venu de d�truire cet individu

	public:
	//Constructeur
		AnimationTranslation(CarteG *carte, int duree=0, QPointF depart=QPointF(0, 0), QPointF arrivee=QPointF(0, 0), QGraphicsItem *parent=NULL, bool cacherCarte=false, bool montreQdTermine=true, CarteG *copieUtilisee=NULL, int zValue=100);	

	//Destructeur
		virtual ~AnimationTranslation();
		
	protected:
		QPointF arrivee;		//Le point d'arriv�e
		bool carteCachee;		//Si la carte est cach�e lors du d�placement
};

#endif
