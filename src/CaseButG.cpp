/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

#include "CaseButG.h"

CaseButG::CaseButG(QPixmap dessin) : LieuG(dessin)
{}

bool CaseButG::ajouterCarte(CarteG *carte)
{
	bool estAs = false;
	if (carte == NULL)
		return false;
	int famCarte = carte->getFamille();
	int valCarte = carte->getValeur();
	if (nombre() == 0) {
		if (valCarte != 0) {
			return false;
        }
		else {
			estAs = true;
        }
    }
	if (!estAs) {
		int famTas = getCarte(0) -> getFamille();
		int valTas = getCarte(0) -> getValeur();
		if (famCarte != famTas)
			return false;
		if (valCarte != valTas + 1)
			return false;
	}
	bool reussi = LieuG::ajouterCarte(carte);
	if (reussi) {
		if (nombre()>1)
			getCarte(1)->setDeplacable(false);
		carte->setDeplacable(true);
		carte->setCache(false);
	}
	return reussi;
}

bool CaseButG::posAjouterCarte(CarteG *carte)
{
	if (carte == NULL)
		return false;
	int famCarte = carte->getFamille();
	int valCarte = carte->getValeur();
	if (nombre() == 0 && valCarte == 0)
		return Cartes::posAjouterCarte(carte);
	if (nombre() == 0)
		return false;
	int famTas = getCarte(0) -> getFamille();
	int valTas = getCarte(0) -> getValeur();
	if (famCarte != famTas)
		return false;
	if (valCarte != valTas + 1)
		return false;
	return true;
}
