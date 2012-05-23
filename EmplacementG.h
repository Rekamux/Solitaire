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
*	CLASSE EMPLACEMENT GRAPHIQUE
*	les sept cases du jeu
*
*	Contient en plus un tas de quinconce
*	g�re le placement graphiques de ses membres
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
		EmplacementG(const Cartes &cartesCachees, CarteG *carteVisible);//A partir de ces �l�ments
	//Destructeurs
		~EmplacementG();
		
	//Accesseurs
		int nombre() const;									//Retourne le nombre total de cartes
		int nombreVisibles() const;							//Retourne le nombre de cartes visibles
		int nombreCachees() const;							//Retourne le nombre de cartes cach�es
		bool estAuDessus(CarteG *carte);					//Demande si la valeur est au dessus
		int position(CarteG *carte); 						//Retourne la position d'une carte donn�e
		bool estVide() const;						//Si le paquet est vide

		
	//Modificateurs
		bool ajouterCarte(CarteG *carte);					//Ajoute une carte dans les visibles
		bool posAjouterCarte(CarteG *carte);				//Possibilit� d'ajouter une carte
		bool posAjouterCarte(int carte);					//Idem
		bool ajouterCartes(Quinconce &tas);					//Ajoute un tas de cartes
		bool retournerCarteCachee();						//Retourne la carte du dessus s'il y lieu (bool�en retourn�)
		CarteG *retirerCarte();								//Retire la carte du dessus
		Cartes retirerCartes(int nombre, bool &reussi);		//Retire un certain nombre de cartes
		Cartes recupererCartesAvant(CarteG *carte, bool &reussi);//Retire un les cartes avant celle indiqu�e
		CarteG *getCarte(int);								//Retourne la ieme carte des visibles, NULL sinon
		
	//M�thodes
		QString getString();
};

#endif
