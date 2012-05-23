/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "ReceveurDonneG.h"

/********************
*	Constructeur	*
********************/

ReceveurDonneG::ReceveurDonneG()
{}

/********************
*	Destructeur	*
********************/

ReceveurDonneG::~ReceveurDonneG()
{}

/***********************
*	Modificateurs	*
***********************/

bool ReceveurDonneG::ajouterCarte(CarteG *carte, int pos)
{
	bool reussi = LieuG::ajouterCarte(carte);
	if (reussi)
	{
		carte->setParentItem(this);
		carte->setPos(pos*15, 0);
		carte->setZValue(nombre()+1);
		carte->setDeplacable(true);
		carte->setCache(false);
		if (nombre()!=1)
		{
			for (int i=1; i<nombre(); i++)
			{
				getCarte(i)->setDeplacable(false);
				if (pos==0)
					getCarte(i)->setPos(0, 0);
			}
		}
	}
	return reussi;
}

bool ReceveurDonneG::ajouterCartes(Cartes &tas)
{
	bool reussi = Cartes::ajouterCartes(tas);
	if (reussi)
	{
		for (int i=nombre()-1; i>=tas.nombre(); i--)
		{
			getCarte(i)->setPos(0, 0);
			getCarte(i)->setDeplacable(false);
		}
		for (int i=0; i<tas.nombre(); i++)
		{
			tas.getCarte(i)->setParentItem(this);
			tas.getCarte(i)->setPos((nombre()-i)/15*2, 0);
			tas.getCarte(i)->setZValue(nombre()+i+1);
			tas.getCarte(i)->setCache(false);
			tas.getCarte(i)->setDeplacable(i==0);
		}
	}
	return reussi;
}

CarteG *ReceveurDonneG::retirerCarte()
{
	CarteG *retour = NULL;
	if (nombre()!=0)
		retour = LieuG::retirerCarte();
	if (nombre()!=0)
		getCarte(0)->setDeplacable(true);
	return retour;
}

