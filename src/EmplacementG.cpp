/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "EmplacementG.h"

/********************
*	Constructeur	*
********************/

EmplacementG::EmplacementG()
{
	setGeometry(0, 0, 71, 6*3+13*15);
}

EmplacementG::EmplacementG(const Cartes &autre, CarteG *carteVisible) : LieuG(autre)
{
	setGeometry(0, 0, 71, 6*3+13*15);
	visibles.ajouterCarte(carteVisible);
	for (int i=0; i<nombreCachees(); i++)
		LieuG::getCarte(nombreCachees()-i-1)->setPos(0, i*3);
	carteVisible->setParentItem(this);
	carteVisible->setPos(0, nombreCachees()*3);
	carteVisible->setZValue(nombreCachees()+2);
	carteVisible->setDeplacable(true);
	carteVisible->setCache(false);
}

/********************
*	Destructeur	*
********************/

EmplacementG::~EmplacementG()
{}

/********************
*	Accesseurs	*
********************/

int EmplacementG::nombre() const
{
	return LieuG::nombre() + visibles.nombre();
}

int EmplacementG::nombreVisibles() const
{
	return visibles.nombre();
}

int EmplacementG::nombreCachees() const
{
	return LieuG::nombre();
}

bool EmplacementG::estAuDessus(CarteG *carte)
{
	return visibles.estAuDessus(carte->i());
}

int EmplacementG::position(CarteG *carte)
{
	return visibles.position(carte);
}

bool EmplacementG::estVide() const
{
	return (isEmpty() && visibles.estVide());
}

/***********************
*	Modificateurs	*
***********************/

bool EmplacementG::ajouterCarte(CarteG *carte)
{
	if (carte == NULL)
		return false;
	bool reussi = false;
	if (estVide())
	{
		if (carte->getValeur() == 12)
			reussi = visibles.ajouterCarte(carte);
		else
			return false;
	}
	else
		reussi = visibles.ajouterCarte(carte);
	if (reussi)
	{
		carte->setPos(0, nombreCachees()*3+(nombreVisibles()-1)*15);
		carte->setParentItem(this);
		carte->setZValue(nombre()+1);
		carte->setCache(false);
		carte->setDeplacable(true);
	}
	return reussi;
}

bool EmplacementG::posAjouterCarte(int carte)
{
	if (estVide())
	{
		if (CarteG::getValeur(carte) == 12)
			return visibles.posAjouterCarte(carte);
		return false;
	}
	else if (nombreVisibles() == 0)
		return false;
	return visibles.posAjouterCarte(carte);
}

bool EmplacementG::posAjouterCarte(CarteG *carte)
{
	if (carte == NULL)
		return false;
	if (estVide())
	{
		if (carte->getValeur() == 12)
			return visibles.posAjouterCarte(carte);
		return false;
	}
	else if (nombreVisibles()==0)
		return false;
	return visibles.posAjouterCarte(carte);
}

bool EmplacementG::ajouterCartes(Quinconce &tas)
{
	bool reussi = false;
	if (estVide())
	{
		CarteG *c = tas.getCarte(tas.nombre()-1);
		if (c->getValeur() == 12)
			reussi = visibles.ajouterCartes(tas);
		else
			return false;
	}
	else
		reussi = visibles.ajouterCartes(tas);
	if (reussi)
	{
		for (int i=0; i<tas.nombre(); i++)
		{
			CarteG *carte = tas.getCarte(i);
			carte->setParentItem(this);
			carte->setZValue(nombre()+1-i);
			carte->setPos(0, nombreCachees()*3+(nombreVisibles()-1-i)*15);
			carte->setCache(false);
			carte->setDeplacable(true);
		}
	}
	return reussi;
}

bool EmplacementG::retournerCarteCachee()
{
	bool reussi = false;
	if (visibles.getNombre() == 0 && nombreCachees() != 0)
	{
		CarteG *retournee = LieuG::retirerCarte();
		reussi = (retournee != NULL);
		if (reussi)
			reussi = visibles.ajouterCarte(retournee);
		else
			QMessageBox::critical(0, "Bug", "Fonction retourner carte cachees EmplacementG.cc<br />Impossible de retirer des cartes cachees!");
		if (reussi)
		{
			retournee->setParentItem(this);
			retournee->setZValue(nombre()+1);
			retournee->setPos(0, nombreCachees()*3+(nombreVisibles()-1)*15);
			retournee->setCache(false);
			retournee->setDeplacable(true);
		}
	}
	return reussi;
}

CarteG *EmplacementG::retirerCarte()
{
	CarteG *retour = visibles.retirerCarte();
	if (retour != NULL)
		if (nombreVisibles()!=0)
			visibles.getCarte(0)->setDeplacable(true);
	return retour;
}

Cartes EmplacementG::retirerCartes(int qtite, bool &reussi)
{
	Cartes retour = visibles.retirerCartes(qtite, reussi);
	if (reussi)
		if (nombreVisibles()!=0)
			visibles.getCarte(0)->setDeplacable(true);
	return retour;
}

Cartes EmplacementG::recupererCartesAvant(CarteG *valeur, bool &reussi)
{
	return visibles.recupererCartesAvant(valeur, reussi);
}

CarteG *EmplacementG::getCarte(int i)
{
	return visibles.getCarte(i);
}
/********************
*	Méthodes		*
********************/

QString EmplacementG::getString()
{
	QString retour = tr("Tas de ") + QString::number(nombre()) + tr(" cartes dont ") + QString::number(Cartes::nombre()) + tr(" sont cachées et ") + QString::number(visibles.nombre()) + tr(" sont visibles :\n");
	retour += tr("Visibles : \n");
	retour += visibles.getString();
	retour += tr("Cachées : \n");
	retour += Cartes::getString();
	return retour;
}
