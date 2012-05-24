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
*	CLASSE ANIMATION ABSTRAITE
*	Représente une animation du jeu
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
		virtual void animationTerminee(int);//Pour indiquer à ListeAnimation que le temps est venu de détruire cet individu
		
	public:

	//Constructeur
		AnimationAbstraite();

	//Destructeur
		virtual ~AnimationAbstraite();
		
	//Récupérer l'id de l'animation (en fait du timer)
		virtual int getId() const;
	//Savoir si l'animation a été lancée
		virtual bool getEstLancee() const;
		
	protected:
		QTimer *timer;			//Le QTimer qui gère l'animation
		int passages;			//Le nombre de passages dans slotTimeout()
		static int intervalle;	//Le temps entre deux executions de slotTimeout()
		bool estLancee;			//Si l'animation a été lancée
};

#endif
