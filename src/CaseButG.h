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
*	CLASSE CASE BUT GRAPHIQUE
*	Là où on empile les cartes par famille
*
*	Gère le fait que l'on ajoute bien les cartes dans l'ordre
*	et les place graphiquement
*/

#ifndef CASEBUTG_H
#define CASEBUTG_H

#include "LieuG.h"

class CaseButG : public LieuG
{
	public:
	//Constructeur
	CaseButG(QPixmap dessin);			//Tas vide
	
	//Modificateurs
		bool ajouterCarte(CarteG *carte);			//Ajouter une carte
		bool posAjouterCarte(CarteG *carte);		//Possibilité d'ajouter une carte
};

#endif
