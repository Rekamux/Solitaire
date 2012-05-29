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
*	CLASSE CARTES
*	Paquet de cartes
*
*	Hérite de QList : gère une liste de pointeurs sur CarteG
*/
#ifndef CARTES_H
#define CARTES_H

#include "CarteG.h"
#include <QList>
#include <QGraphicsWidget>

class Cartes : public QList<CarteG*>
{
	public:
	//Constructeurs
		Cartes();											//Construit un paquet vide
		Cartes(const QList<CarteG *> &autre);				//Construit à partir de la liste
		Cartes(int nombre, QGraphicsWidget *parent = NULL, QString fond = "");//Construit un paquet de nombre cartes de 0 à nbre-1
		Cartes(const Cartes &autre);						//Constructeur par copie SANS COPIE EN PROFONDEUR
		
	//Destructeur
		virtual ~Cartes();
		
	//Accesseurs
		virtual int getNombre() const;						//Retourne le nombre de cartes
		virtual int nombre() const;							//Idem
		virtual CarteG *getCarte(int i);					//Retourne la i-1ème carte, modifiable, NULL si i non correct
		virtual CarteG *getCarte(int i, bool &reussi);					//Retourne la i-1ème carte, modifiable, NULL si i non correct
		virtual bool estVide() const;						//Si le paquet est vide
		virtual bool estAuDessus(int val) const;			//Si la première carte est de cette valeur
		virtual int position(int val); 						//Position de cette valeur, -1 si non trouvée
		virtual int position(CarteG *carte); 				//Position de cette valeur, -1 si non trouvée

		
	//Modificateurs
		virtual bool ajouterCarte(CarteG *carte);			//Ajouter une carte
		virtual bool posAjouterCarte(CarteG *carte);		//Possibilité d'ajouter une carte
		virtual bool posAjouterCarte(int carte);			//Idem avec la valeur
		virtual bool ajouterCartes(const Cartes &cartes);	//Ajouter un paquet de cartes
		virtual bool setCarte(int pos, CarteG *carte);		//Modifier une carte donnée
		virtual CarteG *retirerCarte();						//Retirer la première carte
		virtual Cartes retirerCartes(int nombre, bool &reussi);//Retire nombre carte et met le résultat dans reussi
		virtual Cartes recupererCartesAvant(CarteG *carte, bool &reussi);//Récupère les cartes avant la première occurence de valeur, réussi indique la réussite
		
	//Méthodes
		virtual void melanger(bool cheat=false);			//Mélange les cartes
		virtual QString getString();						//En toutes lettres
		
	private:
	//Fonctions internes
		virtual void echanger(CarteG *&a, CarteG *&b);		//Pour la fonction de mélange
};

#endif
