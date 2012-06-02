/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/
#include "CarteG.h"

/*************************
*	CONSTRUCTEUR	*
*************************/
CarteG::CarteG(int x, int y, int val, QGraphicsItem *parent, int h, int l, QString fond) : QGraphicsRectItem(0, 0, h, l, parent)
{
	//Si val est valide
	if (val >= 0 && val < 52)
		valeurAbsolue = val;
	else
		valeurAbsolue = 0;

	//Mise en place de la position et des attributs de base
	setPos(x, y);
	cache = true;
	deplacable = false;
	
	//Determination de l'image
	QString chemin;
	if (val < 10)
		chemin = "./Cartes/0" + QString::number(val) + ".bmp";
	else
		chemin = "./Cartes/" + QString::number(val) + ".bmp";
	
	devant = new QPixmap(chemin, "bmp");
	if (fond != "")
		this->fond = fond;
	fondPrecedent = fond;
	derriere = new QPixmap(fond);
	
	//Dessin
	setPen(QPen(Qt::black));
	setBrush(QBrush(*derriere));
}

/***********************
*	DESTRUCTEUR	*
***********************/

CarteG::~CarteG()
{}

/********************
*	ACCESSEURS	*
********************/

bool CarteG::getCache() const
{
	return cache;
}

QPixmap CarteG::getPixmap() const
{
	return *devant;
}

bool CarteG::getDeplacable() const
{
	return deplacable;
}

QString CarteG::getFond() const
{
	return fond;
}
int CarteG::getValeurAbsolue() const
{
	return valeurAbsolue;
}
int CarteG::i() const
{
	return valeurAbsolue;
}

int CarteG::getValeur() const
{
	return valeurAbsolue % 13;
}

QString CarteG::getValeurString() const
{
	return listeValeur[getValeur()];
}

int CarteG::getFamille() const
{
	return valeurAbsolue / 13;
}

QString CarteG::getFamilleString() const
{
	return listeFamille[getFamille()];
}

int CarteG::getCouleur() const
{
	if (valeurAbsolue < 26)
		return 0;
	else
		return 1;
}

QString CarteG::getCouleurString() const
{
	return listeCouleur[getCouleur()];
}

/*************************
*	MODIFICATEURS	*
*************************/

void CarteG::changerImage()
{
	if (fond != fondPrecedent)
	{
		delete derriere;
		derriere = new QPixmap(fond);
		fondPrecedent = fond;
		}

	if (cache)
		setBrush(QBrush(*derriere));
	else
		setBrush(QBrush(*devant));
}

void CarteG::setCache(bool etat)
{
	cache = etat;
	changerImage();
}

void CarteG::setDeplacable(bool b)
{
	deplacable = b;
}

void CarteG::inverserImage()
{
	QPixmap nouv = *devant;
	nouv = nouv.transformed(QTransform().rotate(180, Qt::YAxis));
	delete devant;
	devant = new QPixmap(nouv);
}

void CarteG::inverserImageFond()
{
	QPixmap nouv = *derriere;
	nouv = nouv.transformed(QTransform().rotate(180, Qt::YAxis));
	delete derriere;
	derriere = new QPixmap(nouv);
}

void CarteG::setFond(QString chemin)
{
	CarteG::fond = chemin;
}
void CarteG::setValeurAbsolue(int valAbs)
{
	if (valAbs >=0 && valAbs < 52)
	{
		valeurAbsolue = valAbs;
	}
}

void CarteG::setValeur(int val)
{
	if (val >= 0 && val < 13)
	{
		valeurAbsolue = val + 4 * getFamille();
	}
}

void CarteG::setFamille(int fam)
{
	if (fam >= 0 && fam < 4)
	{
		valeurAbsolue = getValeur() + 4 * fam;
	}
}

QString CarteG::getString()
{
	return getValeurString() + QObject::tr(" de ") + getFamilleString();
}

int CarteG::getValeur(int valAbs)
{
	//Si val est valide
	if (valAbs >= 0 && valAbs < 52)
		return valAbs % 13;
	else
		return -1;
}

int CarteG::getFamille(int valAbs)
{
	//Si val est valide
	if (valAbs >= 0 && valAbs < 52)
		return valAbs / 13;
	else
		return -1;
}

int CarteG::getCouleur(int valAbs)
{
	//Si val est valide
	if (valAbs >= 0 && valAbs < 52)
		if (valAbs < 26)
			return 0;
		else
			return 1;
	else
		return -1;
}

/****************************************
*	Initialisation des attributs statiques	*
****************************************/

//Possibilité de les traduire grâce àl'utilisation de tr()
QStringList CarteG::listeValeur = (QStringList() << QObject::tr("As") << QObject::tr("Deux") << QObject::tr("Trois") << QObject::tr("Quatre") << QObject::tr("Cinq") << QObject::tr("Six") << QObject::tr("Sept") << QObject::tr("Huit") << QObject::tr("Neuf") << QObject::tr("Dix") << QObject::tr("Valet") << QObject::tr("Dame") << QObject::tr("Roi"));
QStringList CarteG::listeFamille = (QStringList() << QObject::tr("Pique") << QObject::tr("Trefle") << QObject::tr("Coeur") << QObject::tr("Carreau"));
QStringList CarteG::listeCouleur = (QStringList() << QObject::tr("Noir") << QObject::tr("Rouge"));

QString CarteG::fond = "";

/***************
 * RETRANSLATE *
 ***************/
void CarteG::retranslate() {
	listeValeur = (QStringList()
			<< QObject::tr("As")
			<< QObject::tr("Deux")
			<< QObject::tr("Trois")
			<< QObject::tr("Quatre")
			<< QObject::tr("Cinq")
			<< QObject::tr("Six")
			<< QObject::tr("Sept")
			<< QObject::tr("Huit")
			<< QObject::tr("Neuf")
			<< QObject::tr("Dix")
			<< QObject::tr("Valet")
			<< QObject::tr("Dame")
			<< QObject::tr("Roi"));
	listeFamille = (QStringList()
			<< QObject::tr("Pique")
			<< QObject::tr("Trefle")
			<< QObject::tr("Coeur")
			<< QObject::tr("Carreau"));
	listeCouleur = (QStringList()
			<< QObject::tr("Noir")
			<< QObject::tr("Rouge"));
}

void CarteG::changeEvent(QEvent* event)
{
	if (event->type() == QEvent::LanguageChange) {
		retranslate();
	}
}

