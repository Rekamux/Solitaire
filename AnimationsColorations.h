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
*	CLASSE ANIMATIONS COLORATIONS
*	G�re plusieurs  colorations du jeu 
*/

#ifndef ANIMATIONSCOLORATIONS_H
#define ANIMATIONSCOLORATIONS_H

#include "Animations.h"
#include "AnimationColoration.h"

class AnimationsColorations : public Animations
{
	Q_OBJECT
		
	public slots:
		//D�truire une animation quand elle se termine
		void slotDetruireAnimation(int id);
		//D�truire toutes les animations
		void slotVider();

	signals:
		void animationTerminee(int);//Pour indiquer � ListeAnimation que le temps est venu de d�truire cet individu
		
	public:
	//Constructeur
		AnimationsColorations();
		
	//Ajouter une animation
		void ajouterAnimation(AnimationColoration *ajout);

};

#endif
