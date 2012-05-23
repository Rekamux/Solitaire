/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
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
