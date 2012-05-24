/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "LieuG.h"

/********************
*	Constructeur	*
********************/

LieuG::LieuG()
{
	setGeometry(0, 0, 71, 96);
	supportDessin = new CarteG(0, 0, 0, this);
	supportDessin->setRect(0, 0, 71, 96);
	supportDessin->setBrush(QBrush(Qt::transparent));
	supportDessin->setPen(QPen(Qt::transparent));
	supportDessin->setZValue(1);
	supportDessin->setPos(0, 0);
	setZValue(0);
}

LieuG::LieuG(QPixmap dessin)
{
	setGeometry(0, 0, 71, 96);
	supportDessin = new CarteG(0, 0, 0, this);
	supportDessin->setRect(0, 0, 71, 96);
	supportDessin->setBrush(dessin);
	supportDessin->setPen(QPen(Qt::transparent));
	supportDessin->setZValue(1);
	supportDessin->setPos(0, 0);
	setZValue(0);
}

LieuG::LieuG(const Cartes &autre, QPixmap dessin) : Cartes(autre)
{
	setGeometry(0, 0, 71, 96);
	supportDessin = new CarteG(0, 0, 0, this);
	supportDessin->setRect(0, 0, 71, 96);
	supportDessin->setBrush(dessin);
	supportDessin->setPen(QPen(Qt::transparent));
	supportDessin->setZValue(1);
	supportDessin->setPos(0, 0);
	setZValue(0);
	for (int i=0; i<nombre(); i++)
	{
		getCarte(i)->setParentItem(this);
		getCarte(i)->setPos(0, 0);
		getCarte(i)->setDeplacable(false);
		getCarte(i)->setCache(true);
		getCarte(i)->setZValue(nombre()+1-i);
	}
}

LieuG::LieuG(const Cartes &autre) : Cartes(autre)
{
	setGeometry(0, 0, 71, 96);
	supportDessin = new CarteG(0, 0, 0, this);
	supportDessin->setRect(0, 0, 71, 96);
	supportDessin->setBrush(QBrush(Qt::transparent));
	supportDessin->setPen(QPen(Qt::transparent));
	supportDessin->setZValue(1);
	supportDessin->setPos(0, 0);
	setZValue(0);
	for (int i=0; i<nombre(); i++)
	{
		getCarte(i)->setParentItem(this);
		getCarte(i)->setPos(0, 0);
		getCarte(i)->setDeplacable(false);
		getCarte(i)->setCache(true);
		getCarte(i)->setZValue(nombre()+1-i);
	}
}

/********************
*	Destructeur	*
********************/

LieuG::~LieuG()
{}

/***********************
*	Modificateurs	*
***********************/

bool LieuG::ajouterCarte(CarteG *carte)
{
	bool reussi = Cartes::ajouterCarte(carte);
	if (reussi)
	{
		carte->setParentItem(this);
		carte->setPos(0, 0);
		carte->setDeplacable(false);
		carte->setCache(true);
		carte->setZValue(nombre()+1);
	}
	return reussi;
}

bool LieuG::ajouterCartes(Cartes &tas)
{
	bool reussi = Cartes::ajouterCartes(tas);
	if (reussi)
	{
		for (int i=0; i<tas.nombre(); i++)
		{
			tas.getCarte(i)->setParentItem(this);
			tas.getCarte(i)->setPos(0, 0);
			tas.getCarte(i)->setDeplacable(false);
			tas.getCarte(i)->setCache(true);
			tas.getCarte(i)->setZValue(nombre()-i+1);
		}
	}
	return reussi;
}

bool LieuG::retournerCarteCachee()
{
	return false;
}

CarteG *LieuG::getSupportDessin()
{
	return supportDessin;
}	
