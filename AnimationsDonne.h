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
*	CLASSE ANIMATIONS RETOURNER
*	Animation d'une carte qui se retourne
*/

#ifndef ANIMATIONSDONNE_H
#define ANIMATIONSDONNE_H

#include "Animations.h"
#include "AnimationsRetourner.h"
#include "AnimationTranslation.h"

class AnimationsDonne : public Animations
{
	Q_OBJECT
		
	public:
	//Constructeur
		AnimationsDonne(int duree, CarteG **cartes, QPointF depart, QGraphicsItem *parent=NULL);
};

#endif
