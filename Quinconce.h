/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

/*
*	CLASSE QUINCONCE
*	
*	Cette classe gère l'alterance des couleurs des cartes du solitaire
*/
#ifndef QUINCONCE_H
#define QUINCONCE_H

#include "Cartes.h"

class Quinconce : public Cartes
{
	public :
		//Constructeur
		Quinconce();								//Tas vide
		Quinconce(const Quinconce &paquet);			//Constructeur par copie
		Quinconce(const Cartes &paquet);			//Attention : ne verifie pas si paquet est structuré
		
		//Modificateurs
		bool ajouterCarte(CarteG *carte);			//Ajouter une carte
		bool posAjouterCarte(CarteG *carte);		//Possibilité d'ajouter une carte
		bool posAjouterCarte(int carte);			//Idem avec la valeur
		bool ajouterCartes(Quinconce &paquet);		//Ajouter un autre paquet du même type
};

#endif
