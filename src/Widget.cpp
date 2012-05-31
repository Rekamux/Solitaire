/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "Widget.h"

/***********************
*	CONSTRUCTEUR	*
***********************/

Widget::Widget()
{

	/*	Propriétés	*/
	////////////////

	carteBougee = NULL;
	qCB = NULL;
	nbCartesDistribuees = 3;
	hasWon = false;

	/*	Animations	*/
	////////////////
	animation = false;
	animations = new Animations(0, false);
	
	/*	Chrono	*/
	////////////////
	
	chrono = false;
	chronoLance=false;

	/*	Points	*/
	////////////////
	
	points = 0;
	compterPoints = false;
	
	/*	Silhouette	*/
	//////////////////
	
	silhouette = false;
	animationsColorations = new AnimationsColorations();
		
	/*	Cartes	*/
	////////////////

	cartes = NULL;
	cartesDonne = NULL;
	donne = NULL;
	receveurDonne = NULL;
	casesBut = NULL;
	emplacements = NULL;

	/*	Fond		*/
	////////////////

	fond = "./Fonds/Tortue.bmp";
	
	/*	Initialisation	*/
	/////////////////////
	
	deal();
}

/********************
*	DESTRUCTEUR	*
********************/

Widget::~Widget()
{
	if (cartes != NULL)
	{
		for (int i=0; i<52; i++)
			if (cartes[i] != NULL)
				delete cartes[i];
		delete []cartes;
	}
}


/***********************************
*	RETOURNER CARTE DONNE	*
************************************/

void Widget::retournerCarteDonne()
{
	//On rabat les précédentes
	if (animation && donne->nombre()!=0 && nbCartesDistribuees!=1)
		for (int i=0; i<nbCartesDistribuees-1 && i<receveurDonne->nombre()-1; i++)
			animations->ajouterAnimation(new AnimationTranslation(receveurDonne->at(i), 100-i*10, receveurDonne->at(i)->scenePos(), receveurDonne->scenePos(), this, false, true, NULL, 99-i));
	//On retourne les cartes
	CarteG *auDessus = NULL;
	for (int i=0; i<nbCartesDistribuees; i++)
	{
		CarteG *carte = donne -> retirerCarte();
		if (carte != NULL)
		{
			QPointF depart = carte->scenePos();
			receveurDonne -> ajouterCarte(carte, i);
			QPointF arrivee = carte->scenePos();
			if (animation)
			{
				AnimationsRetournerDonne *retournement = new AnimationsRetournerDonne(200, carte, depart, arrivee, this, 100+i);
				animations->ajouterAnimation(retournement);
			}
			auDessus = carte;
		}
		else
			i = nbCartesDistribuees;
	}
	//Si la donne était vide lorsqu'on a cliqué dessus
	if (auDessus == NULL)
	{
		bool reussi=true;
		while (reussi)
		{
			CarteG *c = receveurDonne->retirerCarte();
			reussi = (c != NULL);
			if (reussi)
				donne -> ajouterCarte(c);
		}
	}
}

/********************
*	SLOT DONNE	*
********************/

void Widget::deal(bool cheat)
{
if (animations->isEmpty() && animationsColorations->isEmpty() && carteBougee == NULL && qCB == NULL)
{
	hasWon = false;
	points = cheat?-615:0;
	emit cacherPoints();
	slotChargerOptions();
	emit arreterChrono();
	chronoLance = false;
	ajouterPoints(0);
	
	/*	Réinitailisation du moteur du jeu	*/
	////////////////////////////////////
	
	if (donne != NULL)
		delete donne;
	if (receveurDonne != NULL)
		delete receveurDonne;
		
	if (casesBut != NULL)
	{
		for (int i=0; i<4; i++)
			if (casesBut[i] != NULL)
				delete casesBut[i];
		delete []casesBut;
	}
	
	if (emplacements != NULL)
	{
		for (int i=0; i<7; i++)
			if (emplacements[i] != NULL)
				delete emplacements[i];
		delete []emplacements;
	}
		
	if (cartes != NULL)
		delete []cartes;

	if (cartesDonne != NULL)
		delete []cartesDonne;

	/*	Initialisation	*/
	/////////////////////
	
	qreal espaceH = (rect().width() - 497) / 8;
	qreal espaceV = (rect().height() - 372) / 3;	
	
	Cartes aDonner(52, this, fond);
	
	cartes = new CarteG *[52];
	for (int i=0; i<52; i++)
		cartes[i] = aDonner.getCarte(i);
	aDonner.melanger(cheat);
	
	donne = new DonneG(aDonner, QPixmap("Autre/fondDonne.bmp"));
		donne->setParentItem(this);
		donne->setPos(1*espaceH + 0*71, 1*espaceV);
	cartesDonne = new CarteG *[52];
	for (int i=0; i<52; i++)
		cartesDonne[i] = aDonner.getCarte(i);	
		
	receveurDonne = new ReceveurDonneG();
		receveurDonne->getSupportDessin()->setBrush(Qt::transparent);
		receveurDonne->setParentItem(this);
		receveurDonne->setPos(2*espaceH + 1*71, 1*espaceV);
	
	casesBut = new CaseButG *[4];
	for (int i=0; i<4; i++)
	{
		casesBut[i] = new CaseButG(QPixmap("Autre/fondCaseBut.bmp"));
		casesBut[i]->setParentItem(this);
		casesBut[i]->setPos((4+i)*espaceH + (3+i)*71, 1*espaceV);
	}
	
	/*	Distribution des cartes	*/
	///////////////////////////////
	
	bool verification;
	emplacements = new EmplacementG *[7];
	for (int i=0; i<7; i++)
	{
		emplacements[i] = new EmplacementG(donne->retirerCartes(i, verification), donne -> retirerCarte());
		emplacements[i]->getSupportDessin()->setBrush(Qt::transparent);
		emplacements[i]->setParentItem(this);
		//emplacements[i]->setPos((1+i)*espaceH + i*71, 2*espaceV + 1*96);
		if (!verification)
			QMessageBox::critical(0, "Deal de Widget.cc", "Erreur lors du retrait des cartes de la donne");
	}
	
	if (animation)
	{
		for (int i=0; i<52; i++)
		{
			cartes[i]->hide();
		}
		QTimer::singleShot(1, this, SLOT(slotAnimationDonne()));
	}
		
	resizeEvent((int)(rect().width()), (int)(rect().height()));
}
}

/************************************
*	SLOT CHARGER OPTIONS	*
************************************/

void Widget::slotChargerOptions()
{
	bool reecrireConfig = false;
	bool erreurLireConfig = false;
	QDir dossierCourant;
	if (dossierCourant.exists("Autre"))
	{
		if (!QFile::exists("Autre/config.conf"))
		{
			reecrireConfig = true;
		}
	}
	else
	{
		if (!dossierCourant.mkdir("donnees"))
		{
			QMessageBox::critical(0, tr("Erreur lors du chargement de Autre/config.conf"), tr("Impossible d'accéder au dossier ./donnees verifiez les droits d'accès. "));
			erreurLireConfig = true;
		}
		else
		{
			reecrireConfig = true;
		}
	}
	if (reecrireConfig)
	{
		QMessageBox::information(0, "Fichier de configuration corrompu", "Veuillez choisir vos options afin de le recréer.");
		Options *nul = new Options(0);
		nul->reecrireConfig();
		nul->exec();
	}
	if (!erreurLireConfig)
	{
		BDD *config = new BDD("Autre/config.conf");
		for (int i=0; i<config->size(); i++)
		{
			if (config->at(i)->getNom() == "animation")
			{
				int valeur = config->at(i)->at(0).toInt();
				animation = (valeur == 1);
			}
			else if (config->at(i)->getNom() == "chrono")
			{
				int valeur = config->at(i)->at(0).toInt();
				chrono = (valeur == 1);
			}
			else if (config->at(i)->getNom() == "silhouette")
			{
				int valeur = config->at(i)->at(0).toInt();
				silhouette = (valeur == 1);
			}
			else if (config->at(i)->getNom() == "nb_cartes_donnees")
			{
				if (config->at(i)->at(0).toInt() == 3)
					nbCartesDistribuees = 3;
				else
					nbCartesDistribuees = 1;
			}
			else if (config->at(i)->getNom() == "points")
			{
				int valeur = config->at(i)->at(0).toInt();
				compterPoints = (valeur == 1);
			}
		}
	}

}

/**********************************
*	SLOT ANIMATION DONNE	*
**********************************/

void Widget::slotAnimationDonne()
{
	if (animation)
		animations->ajouterAnimation(new AnimationsDonne(500, cartesDonne, donne->scenePos()+QPointF(100, 0), this));
}

/**************************
 * SLOT VICTORY ANIMATION *
 **************************/

void Widget::slotVictoryAnimation() {
	if (animation) {
		for (int i=0; i<4; i++) {
			animations->ajouterAnimation(new VictoryAnimation(i%2, 10000, casesBut[i], casesBut[i]->scenePos(), this));
		}
	}
}

/***************************************************************************************************
******************************************DRAG N' DROP*********************************************
***************************************************************************************************/

/*****************************
*	MOUSE PRESS EVENT	*
*****************************/

void Widget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (hasWon) {
		if (animation && !animations->empty()) {
			animations->kill();
		}
		deal();
		return;
	}
	if (chrono && !chronoLance)
	{
		chronoLance = true;
		emit lancerChrono();
	}
	if (event -> button() == Qt::RightButton) {
		if (receveurDonne->estVide()) {
			retournerCarteDonne();
		}
		liftAllCards();
	}
	else if (event -> button() == Qt::LeftButton)
	{
		QPointF clic = event -> scenePos();
		//Détermination de la carte cliquée
		CarteG *carteCliquee = quelleCarteCliquee(clic);
		if (carteCliquee != NULL)
			if (carteCliquee->getDeplacable())
			{
				carteBougee = carteCliquee;
				origineCarteBougee = carteBougee -> pos();
				sceneOrigineCarteBougee = carteBougee -> scenePos();
				hotSpotCarteBougee = clic - carteBougee -> scenePos();
				carteBougee -> parentWidget() -> setZValue(100);
				bool reussi = false;
				Cartes qcce;
				for (int i=0; i<7 && !reussi; i++)
					qcce = emplacements[i]->recupererCartesAvant(carteBougee, reussi);
				if (reussi)
					qCB = new Quinconce(qcce);
				else
					qCB = new Quinconce();
			}
			else
			{
				bool doitRetourner = false;
				for (int i=0; i<7 && !doitRetourner; i++)
					if (emplacements[i]->LieuG::getCarte(0)==carteCliquee && emplacements[i]->nombreVisibles()==0 && emplacements[i]->nombreCachees()!=0)
					{
						doitRetourner = true;
						showLastCard(emplacements[i]);
					}
				//Si on a cliqué sur la donne
				if (!doitRetourner && donne->LieuG::getCarte(0)==carteCliquee)
					retournerCarteDonne();
			}
		else if (donne->sceneBoundingRect().contains(clic))
			retournerCarteDonne();
		else
			event->ignore();
	}
}

/*****************************
*	MOUSE RELEASE EVENT	*
*****************************/

void Widget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	animationsColorations->slotVider();
	if (carteBougee != NULL && carteBougee->scenePos() != sceneOrigineCarteBougee)
	{
		bool pasCase = true;
		QRectF position = carteBougee -> sceneBoundingRect();
		QPointF depart = carteBougee->scenePos();
		LieuG *lieuDepart = static_cast<LieuG*>(carteBougee->parentWidget());
		//Recherche de l'arrivee
		for (int i=0; i<4 && pasCase; i++)
			if (position.intersects(casesBut[i]->sceneBoundingRect()) && qCB->nombre()==0 && casesBut[i]->posAjouterCarte(carteBougee))
			{
				pasCase = false;
				CarteG *test = lieuDepart->retirerCarte();
				if (test == NULL)
					QMessageBox::critical(0, "Dans mouse release event de Widget.cc", "Impossible de retirer la carte de son parent!");
				carteBougee->parentWidget()->setZValue(0);
				casesBut[i]->ajouterCarte(carteBougee);
				QPointF arrivee = carteBougee->scenePos();
				if (animation)
					animations->ajouterAnimation(new AnimationTranslation(carteBougee, 200, depart, arrivee, this));
				if (*lieuDepart != *casesBut[0] && *lieuDepart != *casesBut[1] && *lieuDepart != *casesBut[2] && *lieuDepart != *casesBut[3])
					ajouterPoints(10);
				victoire();
			}
		for (int i=0; i<7 && pasCase; i++)
			if (position.intersects(emplacements[i]->sceneBoundingRect()) && emplacements[i]->posAjouterCarte(carteBougee))
			{
				if (*lieuDepart == *receveurDonne)
					ajouterPoints(5);
				bool vientDUneCaseBut = false;
				for (int j=0; j<4 && !vientDUneCaseBut; j++)
					if (*lieuDepart==*casesBut[j])
						vientDUneCaseBut = true;
				if (vientDUneCaseBut)
					ajouterPoints(-15);
				pasCase = false;
				bool reussi;
				lieuDepart->retirerCartes(qCB->nombre(), reussi);
				CarteG * test = static_cast<LieuG*>(carteBougee->parentWidget())->retirerCarte();
				if (!reussi || test == NULL)
					QMessageBox::critical(0, "Dans mouse release event de Widget.cc", "Impossible de retirer les cartes de leur parent!");
				carteBougee->parentWidget()->setZValue(0);
				emplacements[i]->ajouterCarte(carteBougee);
				emplacements[i]->ajouterCartes(*qCB);
				if (animation)
					animations->ajouterAnimation(new AnimationsPlacerTas(200, carteBougee, depart, carteBougee->scenePos(), qCB, this));
			}
		if (pasCase)
		{
			carteBougee->parentWidget()->setZValue(0);
			carteBougee->setPos(origineCarteBougee);
			for (int i=qCB->nombre()-1; i>=0; i--)
				qCB->getCarte(i)->setPos(origineCarteBougee + QPointF(0, (qCB->nombre()-i)*15));
			if (animation)
				animations->ajouterAnimation(new AnimationsPlacerTas(200, carteBougee, depart, carteBougee->scenePos(), qCB, this));
		}
		else {
			// We return the previously hidden card
			showLastCard(lieuDepart);
		}
		carteBougee = NULL;
		if (qCB!=NULL)
			delete qCB;
		qCB = NULL;
	}
	else if (carteBougee != NULL && carteBougee->scenePos() == sceneOrigineCarteBougee)
	{
		carteBougee->parentWidget()->setZValue(0);
		carteBougee = NULL;
		if (qCB!=NULL)
			delete qCB;
		qCB = NULL;
		event->ignore();
	}
}

/*****************************
*	MOUSE MOVE EVENT	*
*****************************/

void Widget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (carteBougee != NULL)
	{
		QPointF souris = event -> scenePos();
		carteBougee -> setPos(souris - carteBougee -> parentWidget() -> pos() - hotSpotCarteBougee);
		for (int i=0; i<qCB->nombre(); i++)
			qCB->getCarte(i)->setPos(souris-carteBougee->parentWidget()->pos()-hotSpotCarteBougee+QPointF(0,(qCB->nombre()-i)*15));
		if (silhouette)
		{
			QRectF arrivee = carteBougee->sceneBoundingRect();
			bool pasCase = true;
			//Recherche de l'arrivee
			for (int i=0; i<11 && pasCase; i++)
			{
				LieuG *survol = NULL;
				if (i<4 && arrivee.intersects(casesBut[i]->sceneBoundingRect()) && qCB->nombre()==0)
					survol = casesBut[i];
				else if (i>=4 && arrivee.intersects(emplacements[i-4]->sceneBoundingRect()))
					survol = emplacements[i-4];
				if (survol!=NULL)
					if (survol->posAjouterCarte(carteBougee) && survol!=carteBougee->parentWidget())
					{
						pasCase = false;
						// Colorier l'emplacement
						AnimationColoration * coloration;
						if (survol->nombre() == 0) {
							coloration = new AnimationColoration(survol->getSupportDessin(), 500, survol->getSupportDessin()->scenePos(), this);	
						}
						else	
						{	
							coloration = new AnimationColoration(survol->getCarte(0), 500, survol->getCarte(0)->scenePos(), this);		
						}
						animationsColorations->ajouterAnimation(coloration);
					}
			}
		}
	}
}

/**********************************
*	MOUSE DOUBLE CLICK EVENT	*
**********************************/

void Widget::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	if (event -> button() == Qt::LeftButton) {
		monterCarte(quelleCarteCliquee(event -> scenePos()));
	}
	else {
	}
		event->ignore();
}

/***********************
*	RESIZE EVENT	*
***********************/

void Widget::resizeEvent(int l, int h)
{
	int espaceH = (l - 497) / 8;
	int espaceV = (h - 372) / 3;
	
	donne -> setPos(1*espaceH + 0*71, 1*espaceV);
	receveurDonne -> setPos(2*espaceH + 1*71, 1*espaceV);
	
	for (int i=0; i<4; i++)	
		casesBut[i]->setPos((4+i)*espaceH + (3+i)*71, 1*espaceV);
		
	for (int i=0; i<7; i++)
		emplacements[i]->setPos((i+1)*espaceH + i*71, 2*espaceV + 1*96);
}

/*****************
* MONTER CARTE	*
*****************/

bool Widget::monterCarte(CarteG *carteCliquee)
{
	if (carteCliquee == NULL || !carteCliquee->getDeplacable()) {
		return false;
	}
	int position = -1;
	for (int i=0; i<7 && position == -1; i++)
		position = emplacements[i]->position(carteCliquee);
	//Si soit la carte ne vient pas d'un emplacement, soit la carte n'a pas d'autres cartes sur elle
	if (position>0) {
		return false;
	}
	for (int i=0; i<4; i++) {
		if (!casesBut[i]->posAjouterCarte(carteCliquee)) {
			continue;
		}
		QPointF depart = carteCliquee->scenePos();
		LieuG *lieuDepart = static_cast<LieuG*>(carteCliquee->parentWidget());
		lieuDepart->retirerCarte();
		casesBut[i]->ajouterCarte(carteCliquee);
		QPointF arrivee = carteCliquee->scenePos();
		if (*lieuDepart!=*casesBut[0] && *lieuDepart!=*casesBut[1] && *lieuDepart!=*casesBut[2] && *lieuDepart!=*casesBut[3]) {
			ajouterPoints(10);
		}
		if (animation) {
			animations->ajouterAnimation(new AnimationTranslation(carteCliquee, 200, depart, arrivee, this));
		}
		showLastCard(lieuDepart);
		victoire();
		return true;
	}
	return false;
}

/*****************
*	VICTOIRE	*
*****************/

void Widget::victoire()
{
	bool gagne = true;
	for (int i=0; i<4; i++)
		gagne = gagne && (casesBut[i]->nombre()==13);
	if (gagne)
	{
		hasWon = true;
		QMessageBox *message = new QMessageBox(QMessageBox::NoIcon, tr("Victoire!"), tr("Félicitations!<br />Vous avez remporté la partie!"), QMessageBox::Ok, scene()->views()[0]);
		message->setIconPixmap(QPixmap("./Autre/victoire.jpg"));
		message->exec();
		if (message->clickedButton() == message->button(QMessageBox::Ok))
		{
			if (compterPoints) {
				emit montrerScore(true, points);
			}
			if (animation) {
				slotVictoryAnimation();
			}
		}
	}
}

/***********************
*	CHANGER FOND	*
***********************/

void Widget::changerFond(QString image)
{
	QString chemin = "./Fonds/"+image;
	fond = chemin;
	CarteG::setFond(chemin);
	for (int i=0; i<52; i++)
	{	
		cartes[i] -> changerImage();
	}
}

/******************
 * LIFT ALL CARDS *
 ******************/
void Widget::liftAllCards() {
	bool hasLifted = true;
	while (hasLifted) {
		hasLifted = false;
		if (!receveurDonne->estVide()) {
			hasLifted |= monterCarte(receveurDonne->getCarte(0));
		}
		for (int i=0; i<7; i++) {
			if (!emplacements[i]->estVide()) {
				hasLifted |= monterCarte(emplacements[i]->getCarte(0));
			}
		}
	}
}

/******************
 * SHOW LAST CARD *
 ******************/
void Widget::showLastCard(LieuG *place) {
	if (place == receveurDonne) {
		if (receveurDonne->estVide() && !donne->estVide()) {
			retournerCarteDonne();
		}
		return;
	}
	CarteG *showedCard = place->retournerCarteCachee();
	if (!showedCard) {
		return;
	}
	if (animation)
	{
		AnimationsRetourner *retournement = new AnimationsRetourner(200, showedCard, showedCard->scenePos(), this, true, place==emplacements[6]);
		animations->ajouterAnimation(retournement);
	}
	ajouterPoints(5);
}

/*********************************
*	QUELLE CARTE CLIQUEE ?	*
*********************************/

CarteG *Widget::quelleCarteCliquee(QPointF clic)
{
	qreal zValueMax = 0;
	int indice = -1;
	for (int i=0; i<52; i++)
	{
		if (cartes[i]->sceneBoundingRect().contains(clic))
			if (zValueMax < cartes[i]->zValue())
			{
				zValueMax = cartes[i]->zValue();
				indice = i;
			}
	}
	CarteG *retour = NULL;
	if (indice != -1)
		retour = cartes[indice];
	return retour;
}

/*************************
*	AJOUTER POINTS	*
*************************/

void Widget::ajouterPoints(int p)
{
	points += p;
	if (compterPoints)
		emit MAJPoints(points);
}

