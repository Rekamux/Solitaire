/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "Cartes.h"

/********************
*	Constructeurs	*
********************/

Cartes::Cartes()
{}

Cartes::Cartes(const QList<CarteG *> &autre) : QList<CarteG*>(autre)
{}

Cartes::Cartes(int nb, QGraphicsWidget *parent, QString fond)
{
	if (fond != "")
		CarteG::setFond(fond);
	if (nb >= 0 && nb <= 52)
		for (int i=0; i<nb; i++)
			operator<<(new CarteG(0, 0, i, parent));
}

Cartes::Cartes(const Cartes &autre) : QList<CarteG *>(autre)
{}

/********************
*	Destructeur	*
********************/

Cartes::~Cartes()
{
	for (int i=0; i<size(); i++)
		operator[](i) = NULL;
}

/********************
*	Accesseurs	*
********************/

int Cartes::getNombre() const
{
	return size();
}

int Cartes::nombre() const
{
	return size();
}

bool Cartes::estVide() const
{
	return isEmpty();
}

CarteG *Cartes::getCarte(int i)
{
	if (estVide())
		return NULL;
	if (i >= nombre() || i < 0)
		return NULL;
		
	return operator[](i);
}

CarteG *Cartes::getCarte(int i, bool &reussi)
{
	if (estVide())
	{
		reussi = false;
		return NULL;
	}
	if (i >= nombre() || i < 0)
	{
		reussi = false;
		return NULL;
	}	
	reussi = true;
	return operator[](i);
}

bool Cartes::estAuDessus(int val) const
{
	if (estVide())
		return false;
	return at(0)->i()==val;
}

int Cartes::position(int val)
{
	if (estVide())
		return -1;
	bool reussi = true;
	int i=0;
	while (reussi)
	{
		CarteG *c = getCarte(i, reussi);
		if (reussi)
		{
			int vc = c->i();
			if (vc == val)
				return i;
		}
		i++;
	}
	return -1;
}

int Cartes::position(CarteG *carte)
{
	return indexOf(carte);
}


/***********************
*	Modificateurs	*
***********************/

bool Cartes::ajouterCarte(CarteG *carte)
{
	push_front(carte);
	return true;
}

bool Cartes::posAjouterCarte(int carte)
{
	if (carte < 0 || carte >= 52)
		return false;
		
	return true;
}

bool Cartes::posAjouterCarte(CarteG *carte)
{
	return (carte!=NULL);
}

bool Cartes::ajouterCartes(const Cartes &paquet)
{
	operator=(paquet + *this);
	return true;
}

bool Cartes::setCarte(int pos, CarteG *carte)
{
	if (pos >= nombre())
		return false;
	
	operator[](pos) = carte;
	return true;
}

CarteG *Cartes::retirerCarte()
{
	if (estVide())
	{
		return NULL;
	}
	CarteG *retour = takeAt(0);
	return retour;
}

Cartes Cartes::retirerCartes(int qtite, bool &reussi, bool invert)
{
	if (qtite > nombre() || qtite < 0)
	{
		reussi = false;
		return Cartes();
	}
	QList<CarteG *> retour;
	for (int i=0; i<qtite; i++)
		retour << (takeAt(0));
	reussi = true;
	if (invert) {
		for (int i=0; i<retour.size()/2; i++) {
			retour.swap(i, retour.size()-1-i);
		}
	}
	return Cartes(retour);
}

Cartes Cartes::recupererCartesAvant(CarteG *carte, bool &reussi)
{
	int pos = position(carte->i());
	if (pos == -1)
	{
		reussi = false;
		return Cartes();
	}
	QList<CarteG *> retour;
	for (int i=0; i<pos; i++)
		retour << (at(i));
	reussi = true;
	return Cartes(retour);
}

/********************
*	Méthodes		*
********************/

using namespace std;
#include <iostream>

void Cartes::melanger(bool cheat)
{
	if (!cheat) {
		srand(time(NULL));
		for (int i=0; i<nombre(); i++)
			echanger(operator[](i), operator[](rand() % 52));
		return;
	}

	// Generating this pattern
	// 1	2	4	5	6	7	7
	// 		1	3	4	5	6	7
	// 			1	3	4	6	7
	// 				1	3	5	6
	// 					2	3	5	
	// 						2	4
	// 							2
	Cartes other(*this);
	int index = 0;
	int column = 0;
	int row = 0;
	for (int card=0; card<7; card++) {
		for (int family=0; family<4; family++) {
			operator[](index) = other[family*13+card];
			if (column != 6) {
				column ++;
				row ++;
			}
			else {
				column = 7-row;
				row = 0;
			}
			index = (column*(column+1))/2 + row;
		}
	}
	index = 7*4;
	for (int card=7; card<13; card++) {
		for (int family=0; family<4; family++) {
			operator[](index) = other[family*13+card];
			index++;
		}
	}
}

QString Cartes::getString()
{
	QString retour = QObject::tr("Paquet de ") + QString::number(nombre()) + QObject::tr(" cartes :<br />");
	for (int i=0; i<nombre(); i++)
	{
		retour += QString::number(i) + " : " + getCarte(i) -> getString() + "<br />";
	}
	return retour;
}

/*************************
*	Fonction privée		*
*************************/

void Cartes::echanger(CarteG *&a, CarteG *&b)
{
	CarteG *c = a;
	a = b;
	b = c;
}

