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
*	CLASSE ANIMATION (ABSTRAITE)
*	G�re une animation du jeu sur une carte
*/

#ifndef ANIMATION_H
#define ANIMATION_H

#include <QTimer>
#include <QObject>
#include <QPointF>
#include <QMessageBox>
#include <QTransform>
#include <QGraphicsItem>

#include "AnimationAbstraite.h"

class Animation : public AnimationAbstraite
{
	Q_OBJECT
	
	public slots:
		void slotDemarrer();
		
	signals:
		virtual void animationTerminee(int);//Pour indiquer � ListeAnimation que le temps est venu de d�truire cet individu
		
	public:
	//Constructeur
		Animation(CarteG *carte, int duree=0, QGraphicsItem *parent=NULL, QPointF depart=QPointF(0, 0), bool montre=true, CarteG *copieUtilisee=NULL, int zValue=100);

	//Destructeur
		virtual ~Animation();
		
	//Methode
		virtual void cacherOrigine();
		virtual CarteG *getCopie();
		virtual CarteG *getOrigine();
	
	protected:
		CarteG *copie;			//La carte repr�sentative
		CarteG *carteOrigine;	//La carte repr�sent�e
		QPointF depart;			//Position de d�part de la copie
		int duree;				//La dur�e de l'animation en ms
		bool montreQuandTermine;//Si l'animation doit de nouveau montrer la carte repr�sent�e lorsqu'elle se termine
		bool detruireCopie;		//Si on doit d�truire la copie � la fin de l'animation
};

#endif
