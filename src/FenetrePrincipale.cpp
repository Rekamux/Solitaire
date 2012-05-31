/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "FenetrePrincipale.h"
#include <iostream>

using namespace std;

/********************
*	Constructeur	*
********************/

FenetrePrincipale::FenetrePrincipale(QApplication *app) : QMainWindow()
{	
	/*	Initialisation	*/
	/////////////////////

	setWindowTitle(tr("QSolitaire"));
	setWindowIcon(QIcon("Fonds/Tortue.bmp"));

	/*	OPTIONS	*/
	////////////////
	
	options = new Options(this, app);
	connect(options, SIGNAL(accepted()), this, SLOT(slotChargerOptions()));
	
	/*	MEILLEURS SCORES	*/
	//////////////////////////
	
	scores = new Scores(this, "Fonds/scores.conf");


	/* 	Menu		*/
	////////////////
	menuPartie = menuBar() -> addMenu(tr("Partie"));
	
		/*	Actions de Fichier	*/
		//////////////////////////
		
		actionDonne = menuPartie -> addAction(tr("Donner"));
			actionDonne -> setShortcut(QKeySequence("F2"));
			actionDonne -> setIcon(QIcon("./Autre/donner.bmp"));
			actionDonne -> setStatusTip(tr("Distribue une nouvelle partie"));
			QObject::connect(actionDonne, SIGNAL(triggered()), this, SLOT(slotDonne()));
			
		actionRegles = menuPartie -> addAction(tr("Règles"));
			actionRegles -> setShortcut(QKeySequence("F5"));
			actionRegles -> setIcon(QIcon("./Autre/aPropos.bmp"));
			actionRegles -> setStatusTip(tr("Règles du QSolitaire"));
			QObject::connect(actionRegles, SIGNAL(triggered()), this, SLOT(slotRegles()));
		
		actionOptions = menuPartie -> addAction(tr("Options"));
			actionOptions -> setShortcut(QKeySequence("F3"));
			actionOptions -> setIcon(QIcon("./Autre/options.bmp"));
			actionOptions -> setStatusTip(tr("Parametrer QSolitaire"));
			QObject::connect(actionOptions, SIGNAL(triggered()), options, SLOT(exec()));
			
		actionScores = menuPartie -> addAction(tr("Scores"));
			actionScores -> setShortcut(QKeySequence("F6"));
			actionScores -> setIcon(QIcon("./Autre/scores.bmp"));
			actionScores -> setStatusTip(tr("Les meilleurs scores"));
			QObject::connect(actionScores, SIGNAL(triggered()), scores, SLOT(exec()));
			
			
		actionQuitter = menuPartie -> addAction(tr("Quitter"));
			actionQuitter -> setShortcut(QKeySequence("F4"));
			actionQuitter -> setIcon(QIcon("./Autre/quitter.bmp"));
			actionQuitter -> setStatusTip(tr("Quitte le programme"));
			QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
	
	menuFonds = menuBar() -> addMenu(tr("Fonds"));
	
		actionAideFonds = menuFonds->addAction(tr("Ajouter des fonds"));
			actionAideFonds -> setIcon(QIcon("./Autre/aPropos.bmp"));
			actionAideFonds -> setStatusTip(tr("Comment ajouter d'autres fonds"));
			connect(actionAideFonds, SIGNAL(triggered()), this, SLOT(slotAideFonds()));
			
		fondMapper = new QSignalMapper(this);
			QObject::connect(fondMapper, SIGNAL(mapped(QString)), this, SLOT(slotChangerFond(QString)));

	menuCheat = menuBar()->addMenu(tr("Cheat"));

		actionCheatDeal = menuCheat->addAction(tr("Cheating deal"));
		actionCheatDeal->setStatusTip(tr("Give an always-winning deal"));
		QObject::connect(actionCheatDeal, SIGNAL(triggered()), this, SLOT(slotCheatDeal()));
	
	menuAPropos = menuBar() -> addMenu(tr("?"));
	
		/*	Actions de ?	*/
		/////////////////////
		
		actionAPropos = menuAPropos -> addAction(tr("A propos de QSolitaire"));
			actionAPropos -> setIcon(QIcon("./Autre/aPropos.bmp"));
			actionAPropos -> setShortcut(QKeySequence("F1"));
			actionAPropos -> setStatusTip(tr("Pour en savoir plus sur QSolitaire"));
			QObject::connect(actionAPropos,SIGNAL(triggered()),this,SLOT(aProposSlot()));
			
		actionAProposQt = menuAPropos -> addAction(tr("A propos de Qt"));
			actionAProposQt -> setIcon(QIcon("./Autre/aProposQt.bmp"));
			actionAProposQt -> setShortcut(QKeySequence("CTRL+F1"));
			actionAProposQt -> setStatusTip(tr("Pour en savoir plus sur Qt"));
			QObject::connect(actionAProposQt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));

	/*	Barre d'outils	*/
	/////////////////////
	barreOutils = addToolBar(tr("Barre d'outils"));
		barreOutils -> addAction(actionDonne);
		barreOutils -> addAction(actionOptions);
		barreOutils -> addAction(actionScores);
		
		barreOutils -> addSeparator();
		
		slotProposerFonds();
		
		barreOutils -> addSeparator();
		
		barreOutils -> addAction(actionQuitter);
		
	/*	Barre d'etat	*/
	/////////////////////
	barreEtat = statusBar();
		vide = new QWidget();
		labelChrono = new QLabel();
		labelPoints = new QLabel();
		barreEtat -> addWidget(vide, 2000);
		barreEtat -> addPermanentWidget(labelPoints);
		barreEtat -> addPermanentWidget(labelChrono);
		vide->hide();
		labelChrono->hide();
		labelPoints->hide();
		barreEtat->showMessage(tr("Vous pouvez commencer à jouer"), 5000);
		
		/*	Chrono	*/
		////////////////
		chrono = new QTimer(this);
		chrono->setInterval(1000);
		connect(chrono, SIGNAL(timeout()), this, SLOT(slotMAJChrono()));
		temps = 0;
		
	/*	Vue		*/
	////////////////
	vue = new QGraphicsView(this);
	
		/*	Scène graphique		*/
		//////////////////////////
		scene = new QGraphicsScene(0, 0, 577, 402, vue);
		
	vue->setScene(scene);
	
		scene -> setBackgroundBrush(QBrush(QColor(0, 128, 0)));
		
			/*	Widget Principal		*/
			//////////////////////////
			widgetPrincipal = new Widget();
			
		scene -> addItem(widgetPrincipal);
		
			widgetPrincipal -> setGeometry(scene -> sceneRect());

		vue->setMinimumSize(QSize(587, 412));
		vue->setGeometry(0, 0, 587, 412);

	
	setCentralWidget(vue);
	
	connect(widgetPrincipal, SIGNAL(lancerChrono()), this, SLOT(slotLancerChrono()));
	connect(widgetPrincipal, SIGNAL(arreterChrono(bool, bool)), this, SLOT(slotStopChrono(bool, bool)));
	connect(widgetPrincipal, SIGNAL(MAJPoints(int)), this, SLOT(slotMAJPoints(int)));
	connect(widgetPrincipal, SIGNAL(cacherPoints()), this, SLOT(slotCacherPoints()));
	connect(widgetPrincipal, SIGNAL(montrerScore(int)), scores, SLOT(exec(int)));
	
	QTimer::singleShot(100, this, SLOT(slotDonne()));
}

/*************************
*	SLOT A PROPOS	*
*************************/

void FenetrePrincipale::aProposSlot()
{
	QMessageBox::information(this,tr("A propos de QSolitaire"),tr("Programme réalisé par <strong>Axel Schumacher</strong><h3>Remerciements :</h3><ul><li><strong>M. Nebra</strong> : <a href='www.siteduzero.com'>www.siteduzero.com</a></li><li><strong>J. Chauche</strong> : <a href='http://www.lirmm.fr/~chauche/'>http://www.lirmm.fr/~chauche/</a></li><li><strong>M. Yèche</strong> pour les images</li></ul>"));
}

/*******************
 * SLOT CHEAT DEAL *
 *******************/

void FenetrePrincipale::slotCheatDeal() {
	if (widgetPrincipal) {
		widgetPrincipal->deal(true);
	}
}

/********************
*	SLOT DONNE	*
********************/

void FenetrePrincipale::slotDonne()
{
	if (widgetPrincipal!=NULL)
		widgetPrincipal->deal();
}

/**********************************
*	SLOT PROPOSER FONDS		*
**********************************/

void FenetrePrincipale::slotProposerFonds()
{
	QStringList images;
	QDir dossier("./Fonds/");
	images = dossier.entryList(QDir::Files);
	QStringList aEnlever;
	for (int i=0; i<images.size(); i++)
	{
		if (!(images[i].endsWith(".bmp") || images[i].endsWith(".jpg") || images[i].endsWith(".png")))
		{
			aEnlever << images[i];
		}
	}
	for (int i=0; i<aEnlever.size(); i++)
	{
		images.removeOne(aEnlever[i]);
	}
	for (int i=0; i<images.size(); i++)
	{
		QString image = images[i];
		images[i].truncate(images[i].size()-4);
		QAction *actionChoixFond = menuFonds -> addAction(images[i]);
			actionChoixFond -> setIcon(QIcon("./Fonds/"+image));
			actionChoixFond -> setStatusTip(tr("Changer l'image de fond des cartes"));
		barreOutils -> addAction(actionChoixFond);
		connect(actionChoixFond, SIGNAL(triggered()), fondMapper, SLOT(map()));
		fondMapper -> setMapping(actionChoixFond, image);
	}
}

/****************************
*	SLOT CHANGER FOND	*
****************************/

void FenetrePrincipale::slotChangerFond(QString image)
{
	widgetPrincipal->changerFond(image);
}

/****************************
*	SLOT AIDE FONDS	*
*****************************/

void FenetrePrincipale::slotAideFonds()
{
	QMessageBox::information(this,tr("Ajouter des images de fonds"),tr("Ajoutez simplement des images aux formats bmp, jpg ou png dans le répertoire Fonds."));
}

/**********************************
*	SLOT CHARGER OPTIONS		*
**********************************/

void FenetrePrincipale::slotChargerOptions()
{
	QMessageBox::warning(0, tr("Information"), tr("Pour appliquer les options, vous devez redonner les cartes."));
}

/****************************
*	SLOT REGLES	*
*****************************/

void FenetrePrincipale::slotRegles()
{
	QMessageBox::information(this,tr("Règles du QSolitaire"),tr("Rules"));
}

/*******************************
*	SLOT LANCER CHRONO	*
*******************************/

void FenetrePrincipale::slotLancerChrono()
{
	chrono->start();
	temps = 0;
	slotMAJChrono();
}

/******************************
*	SLOT STOP CHRONO	*
******************************/

void FenetrePrincipale::slotStopChrono(bool show, bool init)
{
	vide->hide();
	if (show) {
		labelChrono->show();
	}
	else {
		labelChrono->hide();
	}
	chrono->stop();
	temps = 0;
	if (init) {
		slotMAJChrono();
	}
}

/*************************
*	SLOT MAJ CHRONO	*
*************************/

void FenetrePrincipale::slotMAJChrono()
{
	if (vide->isHidden() || labelChrono->isHidden())
	{
		vide -> show();
		labelChrono -> show();
	}
	QString aAfficher = tr("Temps : ");
	int minutes = 0;
	if (temps>=60)
		minutes = temps/60;
	if (minutes != 0)
		aAfficher += QString::number(minutes)+tr(" min ");
	labelChrono->setText(aAfficher+QString::number(temps - minutes*60)+tr(" sec"));
	temps++;
}

/**************************
*	SLOT MAJ POINTS	*
**************************/

void FenetrePrincipale::slotMAJPoints(int points)
{
	if (vide->isHidden() || labelPoints->isHidden())
	{
		vide->show();
		labelPoints->show();
	}
	labelPoints -> setText(tr("Points : ")+QString::number(points));
}

/******************************
*	SLOT CACHER POINTS	*
******************************/

void FenetrePrincipale::slotCacherPoints()
{
	vide->hide();
	labelPoints->hide();
}

/*************************
*	RESIZE EVENT		*
*************************/
//Largeur Carte : 71px
//Hauteur Carte : 96px
//pixels visibles lors du chevauchement : 15px
//Taille prise par les cartes en largeur = 497px
//Taille prise en hauteur = 96+12*15+96 = 372px
//Espacement min : 10px
//Largeur minimale = 497 + 8*10 = 577px
//Hauteur minimale = 372 + 3*10 = 402px

void FenetrePrincipale::resizeEvent(QResizeEvent *e)
{
	//widgetPrincipal->setGeometry(scene -> sceneRect());
	widgetPrincipal -> resize();
	QMainWindow::resizeEvent(e);
}
