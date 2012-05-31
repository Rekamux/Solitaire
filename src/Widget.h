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
*	CLASSE WIDGET
*	Le QGraphicsWidget principal
*
*	Est le widget principal de la scene et est le parent de tous les widgets du jeu
*/

#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsView>
#include <QMainWindow>
#include <QLabel>
#include <QGraphicsScene>
#include <QObject>
#include <QMainWindow>
#include <QIcon>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QApplication>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsWidget>
#include <QGraphicsGridLayout>
#include <QResizeEvent>
#include <QDialog>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QGraphicsSceneMouseEvent>
#include <QBitmap>
#include <QSignalMapper>
#include <QPainter>
#include <QPixmap>

#include "EmplacementG.h"
#include "CaseButG.h"
#include "ReceveurDonneG.h"
#include "DonneG.h"
#include "BDD.h"
#include "Options.h"
#include "Animations.h"
#include "AnimationsRetourner.h"
#include "AnimationsRetournerDonne.h"
#include "AnimationsPlacerTas.h"
#include "AnimationsDonne.h"
#include "AnimationColoration.h"
#include "AnimationsColorations.h"
#include "VictoryAnimation.h"

class Widget : public QGraphicsWidget
{
	Q_OBJECT
	
	public:
		Widget();
		
		~Widget();
		
		void resize();
		
		void changerFond(QString);
		
		void ajouterPoints(int);

		// Deal cards
		void deal(bool cheat = false);
		
	public slots:
		//Charger les options
		void slotChargerOptions();
		//Animation de la donne
		void slotAnimationDonne();
		// Victory animation
		void slotVictoryAnimation();
		
	signals:
		//Gestion du chrono
		void arreterChrono(bool, bool);
		void lancerChrono();
		//Gestion des points
		void MAJPoints(int);
		void cacherPoints();
		//Gestion du score
		void montrerScore(int);
		
	protected:
		// Is game playable (false if won)
		bool hasWon;

		// Lift all possible cards
		void liftAllCards();

		// Return the top card of a place if possible
		void showLastCard(LieuG *place);

		//Drag and Drop
		void mousePressEvent(QGraphicsSceneMouseEvent *event);
		void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
		void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
		void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
		
		//Savoir quelle carte a été cliquée
		CarteG *quelleCarteCliquee(QPointF clic);
		
		//Monter une carte
		bool monterCarte(CarteG *);
		void victoire();
		
		//Montrer les cartes de la donne
		void retournerCarteDonne();

		//Animations
		bool animation;
		Animations *animations;
		
		//Chrono
		bool chrono;
		bool chronoLance;
		
		//Points
		bool compterPoints;
		int points;
		
		//Silhouettes
		bool silhouette;
		AnimationsColorations *animationsColorations;
				
		//Gestion de la carte bougée
		CarteG *carteBougee;
		QPointF origineCarteBougee;
		QPointF sceneOrigineCarteBougee;
		QPointF hotSpotCarteBougee;
		Quinconce *qCB;
		
		//Options
		int nbCartesDistribuees;
	
		//Cartes
		CarteG **cartes;
		CarteG **cartesDonne;	//Dans l'ordre de la donne au début de la partie
			
		DonneG *donne;
		ReceveurDonneG *receveurDonne;
			
		CaseButG **casesBut;
		
		EmplacementG **emplacements;
						
		//Face cachée
		QString fond;
		
		//Coup précédent
		// CarteG *carteCP;
		// LieuG *lieuDepartCP;
		// LieuG *lieuArriveeCP;
};
#endif
