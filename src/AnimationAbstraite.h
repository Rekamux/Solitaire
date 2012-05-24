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
*	CLASSE ANIMATION ABSTRAITE
*	Repr�sente une animation du jeu
*/

#ifndef ANIMATIONABSTRAITE_H
#define ANIMATIONABSTRAITE_H

#include <QTimer>
#include <QObject>
#include <QPointF>
#include <QMessageBox>
#include <QTransform>
#include <QGraphicsItem>

#include "CarteG.h"

class AnimationAbstraite : public QObject
{
	Q_OBJECT
		
	public slots:
		virtual void slotTimeout()=0;
		virtual void slotDemarrer()=0;
		
	signals:
		virtual void animationTerminee(int);//Pour indiquer � ListeAnimation que le temps est venu de d�truire cet individu
		
	public:

	//Constructeur
		AnimationAbstraite();

	//Destructeur
		virtual ~AnimationAbstraite();
		
	//R�cup�rer l'id de l'animation (en fait du timer)
		virtual int getId() const;
	//Savoir si l'animation a �t� lanc�e
		virtual bool getEstLancee() const;
		
	protected:
		QTimer *timer;			//Le QTimer qui g�re l'animation
		int passages;			//Le nombre de passages dans slotTimeout()
		static int intervalle;	//Le temps entre deux executions de slotTimeout()
		bool estLancee;			//Si l'animation a �t� lanc�e
};

#endif
