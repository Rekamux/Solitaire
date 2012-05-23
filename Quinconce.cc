/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "Quinconce.h"

Quinconce::Quinconce() : Cartes()
{}

Quinconce::Quinconce(const Quinconce &paquet) : Cartes(paquet)
{}

Quinconce::Quinconce(const Cartes &paquet) : Cartes(paquet)
{}

bool Quinconce::ajouterCarte(CarteG *carte)
{
	int val = carte->i();
	if (val < 0 || val >= 52)
		return false;
		
	bool ok = false;
	if (nombre() == 0)
		ok = true;
	else
	{
		CarteG *prec = at(0);
		int coulPrec = prec->getCouleur();
		int valPrec = prec->getValeur();
		int coul = carte->getCouleur();
		int val = carte->getValeur();
		ok = (coulPrec != coul) && (valPrec - 1 == val);
	}
		
	if (ok)
		this -> Cartes::ajouterCarte(carte);
	return ok;
}

bool Quinconce::posAjouterCarte(int carte)
{
	int val = carte;
	if (val < 0 || val >= 52)
		return false;
		
	bool ok = false;
	if (nombre() == 0)
		ok = true;
	else
	{
		CarteG *prec = at(0);
		int coulPrec = prec->getCouleur();
		int valPrec = prec->getValeur();
		int coul = CarteG::getCouleur(carte);
		int val = CarteG::getValeur(carte);
		ok = (coulPrec != coul) && (valPrec - 1 == val);
	}
	return ok;
}

bool Quinconce::posAjouterCarte(CarteG *carte)
{
	int val = carte->getValeurAbsolue();
	if (val < 0 || val >= 52)
		return false;
		
	bool ok = false;
	if (nombre() == 0)
		ok = true;
	else
	{
		CarteG *prec = at(0);
		int coulPrec = prec->getCouleur();
		int valPrec = prec->getValeur();
		int coul = carte->getCouleur();
		int val = carte->getValeur();
		ok = (coulPrec != coul) && (valPrec - 1 == val);
	}
	return ok;
}

bool Quinconce::ajouterCartes(Quinconce &paquet)
{
	bool ok = false;
	if (nombre()!=0 && paquet.nombre()!=0)
	{
		CarteG *derniere = at(0);
		CarteG *premiere = paquet.getCarte(paquet.nombre() - 1);
		int coulDerniere = derniere->getCouleur();
		int valDerniere = derniere->getValeur();
		int coulPremiere = premiere->getCouleur();
		int valPremiere = premiere->getValeur();
		ok = (coulDerniere != coulPremiere) && (valDerniere - 1 == valPremiere);
	}
	if (ok)
		Cartes::ajouterCartes(paquet);
	return ok;
}

