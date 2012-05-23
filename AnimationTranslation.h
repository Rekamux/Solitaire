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
*	CLASSE ANIMATION TRANSLATION
*	Gère une simple translation
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
		virtual void animationTerminee(int);//Pour indiquer à ListeAnimation que le temps est venu de détruire cet individu

	public:
	//Constructeur
		AnimationTranslation(CarteG *carte, int duree=0, QPointF depart=QPointF(0, 0), QPointF arrivee=QPointF(0, 0), QGraphicsItem *parent=NULL, bool cacherCarte=false, bool montreQdTermine=true, CarteG *copieUtilisee=NULL, int zValue=100);	

	//Destructeur
		virtual ~AnimationTranslation();
		
	protected:
		QPointF arrivee;		//Le point d'arrivée
		bool carteCachee;		//Si la carte est cachée lors du déplacement
};

#endif
