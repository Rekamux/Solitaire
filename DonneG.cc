/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "DonneG.h"

/********************
*	Constructeur	*
********************/

DonneG::DonneG(QPixmap dessin) : LieuG(dessin)
{}

DonneG::DonneG(const Cartes &autre, QPixmap dessin) : LieuG(autre, dessin)
{
	for (int i=0; i<nombre(); i++)
		getCarte(i)->setPos((nombre()-i)/15*2, 0);
}

/********************
*	Destructeur	*
********************/

DonneG::~DonneG()
{}

/***********************
*	Modificateurs	*
***********************/

bool DonneG::ajouterCarte(CarteG *carte)
{
	bool reussi = LieuG::ajouterCarte(carte);
	if (reussi)
		carte->setPos(nombre()/15*2, 0);
	return reussi;
}

bool DonneG::ajouterCartes(Cartes &tas)
{
	bool reussi = LieuG::ajouterCartes(tas);
	if (reussi)
	{
		for (int i=0; i<tas.nombre(); i++)
			tas.getCarte(i)->setPos((nombre()-i)/15*2, 0);
	}
	return reussi;
}

