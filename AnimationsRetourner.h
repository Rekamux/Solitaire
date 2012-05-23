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

#ifndef ANIMATIONSRETOURNER_H
#define ANIMATIONSRETOURNER_H

#include "Animations.h"
#include "AnimationRotationY.h"
#include "AnimationTranslation.h"

class AnimationsRetourner : public Animations
{
	Q_OBJECT
		
	public:
	//Constructeur
		AnimationsRetourner(int duree, CarteG *carte, QPointF pos, QGraphicsItem *parent=NULL, bool cacheeDepart=true, bool aGauche=false);
};

#endif
