/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

/*
*	CLASSE QUINCONCE
*	
*	Cette classe g�re l'alterance des couleurs des cartes du solitaire
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
		Quinconce(const Cartes &paquet);			//Attention : ne verifie pas si paquet est structur�
		
		//Modificateurs
		bool ajouterCarte(CarteG *carte);			//Ajouter une carte
		bool posAjouterCarte(CarteG *carte);		//Possibilit� d'ajouter une carte
		bool posAjouterCarte(int carte);			//Idem avec la valeur
		bool ajouterCartes(Quinconce &paquet);		//Ajouter un autre paquet du m�me type
};

#endif
