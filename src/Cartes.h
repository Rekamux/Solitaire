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
*	CLASSE CARTES
*	Paquet de cartes
*
*	H�rite de QList : g�re une liste de pointeurs sur CarteG
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
		Cartes(const QList<CarteG *> &autre);				//Construit � partir de la liste
		Cartes(int nombre, QGraphicsWidget *parent = NULL, QString fond = "");//Construit un paquet de nombre cartes de 0 � nbre-1
		Cartes(const Cartes &autre);						//Constructeur par copie SANS COPIE EN PROFONDEUR
		
	//Destructeur
		virtual ~Cartes();
		
	//Accesseurs
		virtual int getNombre() const;						//Retourne le nombre de cartes
		virtual int nombre() const;							//Idem
		virtual CarteG *getCarte(int i);					//Retourne la i-1�me carte, modifiable, NULL si i non correct
		virtual CarteG *getCarte(int i, bool &reussi);					//Retourne la i-1�me carte, modifiable, NULL si i non correct
		virtual bool estVide() const;						//Si le paquet est vide
		virtual bool estAuDessus(int val) const;			//Si la premi�re carte est de cette valeur
		virtual int position(int val); 						//Position de cette valeur, -1 si non trouv�e
		virtual int position(CarteG *carte); 				//Position de cette valeur, -1 si non trouv�e

		
	//Modificateurs
		virtual bool ajouterCarte(CarteG *carte);			//Ajouter une carte
		virtual bool posAjouterCarte(CarteG *carte);		//Possibilit� d'ajouter une carte
		virtual bool posAjouterCarte(int carte);			//Idem avec la valeur
		virtual bool ajouterCartes(const Cartes &cartes);	//Ajouter un paquet de cartes
		virtual bool setCarte(int pos, CarteG *carte);		//Modifier une carte donn�e
		virtual CarteG *retirerCarte();						//Retirer la premi�re carte
		virtual Cartes retirerCartes(int nombre, bool &reussi);//Retire nombre carte et met le r�sultat dans reussi
		virtual Cartes recupererCartesAvant(CarteG *carte, bool &reussi);//R�cup�re les cartes avant la premi�re occurence de valeur, r�ussi indique la r�ussite
		
	//M�thodes
		virtual void melanger(bool cheat=false);			//M�lange les cartes
		virtual QString getString();						//En toutes lettres
		
	private:
	//Fonctions internes
		virtual void echanger(CarteG *&a, CarteG *&b);		//Pour la fonction de m�lange
};

#endif
