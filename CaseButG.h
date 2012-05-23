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
*	CLASSE CASE BUT GRAPHIQUE
*	L� o� on empile les cartes par famille
*
*	G�re le fait que l'on ajoute bien les cartes dans l'ordre
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
		bool posAjouterCarte(CarteG *carte);		//Possibilit� d'ajouter une carte
};

#endif
