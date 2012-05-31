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
*	CLASSE FENETRE PRINCIPALE
*	
*	Hérite de QMainWindow
*	Centralise toutes les autres classes et gère les menus, les actions et la vue graphique.
*/

#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>
#include <QApplication>
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
#include <QFile>
#include <QDir>

#include "Options.h"
#include "Widget.h"
#include "Scores.h"

class FenetrePrincipale : public QMainWindow
{
	Q_OBJECT
	
	public:
	
		FenetrePrincipale(QApplication *app);
		
	public slots:
	
		//Redonner les cartes
		void slotDonne();

		// Deal by cheating
		void slotCheatDeal();
		
		//Ouvrir la fenetre A Propos de QSloitaire
		void aProposSlot();
		
		//Changer l'image arriere des cartes
		void slotChangerFond(QString);
		
		//Ajouter tous les fonds choisissables
		void slotProposerFonds();
		
		//Conseils sur comment changer le fond
		void slotAideFonds();
		
		//MAJ des options
		void slotChargerOptions();
		
		//Montrer les règles
		void slotRegles();
		
		//Lancer le chrono
		void slotLancerChrono();
		
		//Réinitialiser le chrono
		void slotStopChrono(bool show, bool init);
				
		//Mettre à jour le temps
		void slotMAJChrono();
		
		//Mettre à jour les points
		void slotMAJPoints(int);
		
		//Cacher les points
		void slotCacherPoints();
		
	private:
		//Evenement de redimensionnement
		void resizeEvent(QResizeEvent *);
	
		//Menu
		QMenu *menuPartie;
		
			//Elements de Partie
			QAction *actionRegles;
			QAction *actionDonne;
			QAction *actionOptions;
			QAction *actionScores;
			QAction *actionQuitter;
			
		QMenu *menuFonds;
		
			//Elements de Fonds
			QAction *actionAideFonds;
			QSignalMapper *fondMapper;

		QMenu *menuCheat;

			// Cheat elements
			QAction *actionCheatDeal;
			
		QMenu *menuAPropos;
		
			//Elements de ?
			QAction *actionAPropos;
			QAction *actionAProposQt;
			
		//Barre d'outil
		QToolBar *barreOutils;
		
		//Barre d'etat
		QStatusBar *barreEtat;
			QLabel *pret;
			QWidget *vide;
			QLabel *labelChrono;
			QLabel *labelPoints;
				
			//Chrono
			QTimer *chrono;
			int temps;
	
		//Vue
		QGraphicsView *vue;
			
			//Scene graphique
			QGraphicsScene *scene;
				
				//Widget Principal
				Widget *widgetPrincipal;
		
		//Fenetre d'options
		Options *options;
		
		//Fenetre de meilleurs scores
		Scores *scores;
};

#endif
