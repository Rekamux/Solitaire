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
*	CLASSE ANIMATION (ABSTRAITE)
*	Gère une animation du jeu sur une carte
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
		virtual void animationTerminee(int);//Pour indiquer à ListeAnimation que le temps est venu de détruire cet individu
		
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
		CarteG *copie;			//La carte représentative
		CarteG *carteOrigine;	//La carte représentée
		QPointF depart;			//Position de départ de la copie
		int duree;				//La durée de l'animation en ms
		bool montreQuandTermine;//Si l'animation doit de nouveau montrer la carte représentée lorsqu'elle se termine
		bool detruireCopie;		//Si on doit détruire la copie à la fin de l'animation
};

#endif
