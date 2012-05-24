/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

#include "BDDElement.h"

/***********************
*	CONSTRUCTEUR	*
***********************/

BDDElement::BDDElement(QString n) : QStringList()
{
	nom = n;
}

/***********************
*	DESTRUCTEUR	*
***********************/

BDDElement::~BDDElement()
{}

/****************************
*	AJOUTER ATTRIBUT	*
****************************/

void BDDElement::ajouterAttribut(QString attribut)
{
	push_front(attribut);
}

/*****************************
*	RETIRER ATTRIBUT	*
*****************************/

bool BDDElement::retirerAttribut(QString attribut)
{
	return removeOne(attribut);
}

/*****************************
*	RECUPERER LE NOM	*
*****************************/

QString BDDElement::getNom() const
{
	return nom;
}

/****************************
*	CHANGER LE NOM		*
****************************/

void BDDElement::setNom(QString n)
{
	nom = n;
}
