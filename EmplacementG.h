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
*	CLASSE EMPLACEMENT GRAPHIQUE
*	les sept cases du jeu
*
*	Contient en plus un tas de quinconce
*	gère le placement graphiques de ses membres
*/

#ifndef EMPLACEMENTG_H
#define EMPLACEMENTG_H

#include "LieuG.h"
#include "Quinconce.h"

#include <QMessageBox>

class EmplacementG : public LieuG
{
	protected:
		Quinconce visibles;									//Tas de cartes en quinconce
		
	public:
	//Constructeurs
		EmplacementG();				//Tas vide
		EmplacementG(const Cartes &cartesCachees, CarteG *carteVisible);//A partir de ces éléments
	//Destructeurs
		~EmplacementG();
		
	//Accesseurs
		int nombre() const;									//Retourne le nombre total de cartes
		int nombreVisibles() const;							//Retourne le nombre de cartes visibles
		int nombreCachees() const;							//Retourne le nombre de cartes cachées
		bool estAuDessus(CarteG *carte);					//Demande si la valeur est au dessus
		int position(CarteG *carte); 						//Retourne la position d'une carte donnée
		bool estVide() const;						//Si le paquet est vide

		
	//Modificateurs
		bool ajouterCarte(CarteG *carte);					//Ajoute une carte dans les visibles
		bool posAjouterCarte(CarteG *carte);				//Possibilité d'ajouter une carte
		bool posAjouterCarte(int carte);					//Idem
		bool ajouterCartes(Quinconce &tas);					//Ajoute un tas de cartes
		bool retournerCarteCachee();						//Retourne la carte du dessus s'il y lieu (booléen retourné)
		CarteG *retirerCarte();								//Retire la carte du dessus
		Cartes retirerCartes(int nombre, bool &reussi);		//Retire un certain nombre de cartes
		Cartes recupererCartesAvant(CarteG *carte, bool &reussi);//Retire un les cartes avant celle indiquée
		CarteG *getCarte(int);								//Retourne la ieme carte des visibles, NULL sinon
		
	//Méthodes
		QString getString();
};

#endif
