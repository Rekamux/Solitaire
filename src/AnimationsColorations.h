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
*	CLASSE ANIMATIONS COLORATIONS
*	Gère plusieurs  colorations du jeu 
*/

#ifndef ANIMATIONSCOLORATIONS_H
#define ANIMATIONSCOLORATIONS_H

#include "Animations.h"
#include "AnimationColoration.h"

class AnimationsColorations : public Animations
{
	Q_OBJECT
		
	public slots:
		//Détruire une animation quand elle se termine
		void slotDetruireAnimation(int id);
		//Détruire toutes les animations
		void slotVider();

	signals:
		void animationTerminee(int);//Pour indiquer à ListeAnimation que le temps est venu de détruire cet individu
		
	public:
	//Constructeur
		AnimationsColorations();
		
	//Ajouter une animation
		void ajouterAnimation(AnimationColoration *ajout);

};

#endif
