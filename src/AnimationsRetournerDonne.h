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
*	CLASSE ANIMATIONS RETOURNER DONNE
*	Animation d'une carte qui va de la donne � l'emplacement de donne
*/

#ifndef ANIMATIONSRETOURNERDONNE_H
#define ANIMATIONSRETOURNERDONNE_H

#include "Animations.h"
#include "AnimationRotationY.h"
#include "AnimationTranslation.h"

class AnimationsRetournerDonne : public Animations
{
	Q_OBJECT
	public:
	//Constructeur
		AnimationsRetournerDonne(int duree, CarteG *carte, QPointF depart, QPointF arrivee, QGraphicsItem *parent, int zValue=100, bool envers=false);
};

#endif
