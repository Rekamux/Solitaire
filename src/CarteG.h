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
*	CLASSE CARTEG
*	Carte graphique
*
*	Hérite à la fois de QGraphicsRectItem
*	Représentation d'une carte dans la Scène

*/

#ifndef CARTEG_H
#define CARTEG_H

#include <QGraphicsRectItem>
#include <QImage>
#include <QString>
#include <QBrush>
#include <QPixmap>
#include <QPen>
#include <QEvent>

#include <QGraphicsRectItem>

class CarteG : public QGraphicsRectItem
{	
	protected:
		int valeurAbsolue;					//Valeur absolue de la carte qui la détermine entièrement comprise entre 0 et 51
		static QStringList listeValeur;		//Valeur de la carte en toute lettres
		static QStringList listeFamille;	//Famille de la carte en toute lettres
		static QStringList listeCouleur;	//Couleur de la carte en toute lettres
		static QString fond;				//Chemin de l'image arrière
		bool cache;							//La carte est retournée
		bool deplacable;					//La carte est déplacable
		QPixmap *devant;					//L'image avant
		QPixmap *derriere;					//L'image arrière
		QString fondPrecedent;				//Pour déterminer si il y a besoin de changer le fond lors de l'appel de changerImage()
		
	public:
		//Constructeur
			//x : position en abscisse
			//y : position en ordonnée
			//l : largeur
			//h : hauteur
			//fond : chemin constant de la Classe Widget qui indique où prendre l'image arrière
			//parent : Cartes où se trouve la carteG
			//si on change de fond,
			//chaque image verra son fond changé è partir de l'appel de changerImage()
		CarteG(int x, int y, int val, QGraphicsItem *parent = NULL, int h=71, int l=96, QString fond="");
		
		//Destructeur
		~CarteG();
		
		//Accesseurs
		bool getCache() const;				//Si la carte est retournée
		bool getDeplacable() const;			//Si la carte est déplacable
		QPixmap getPixmap() const;			//Image avant de la carte
		QString getFond() const;			//L'image de fond commun
		int getValeurAbsolue() const;		//Retourne la valeur absolue de la carte, comprise entre 0 et 51
		int i() const;						//Même chose, simple commodité
		int getValeur() const;				//Retourne la valeur simple de la carte
		QString getValeurString() const;	//Retourne la valeur en toutes lettres
		int getFamille() const;				//Retourne la famille de la carte comprise entre 0 et 3
		QString getFamilleString() const;	//Retourne la famille en toutes lettres
		int getCouleur() const;				//Retourne 0 ou 1 pour la couleur
		QString getCouleurString() const;	//Retourne la couleur en toutes lettres

		
		//Méthodes et modificateurs
		void changerImage();				//Mettre à jour l'image en fonction de cache	
		void setCache(bool);				//Changer la valeur de cache
		void setDeplacable(bool);			//Changer la valeur de deplacable
		void inverserImage();				//Effet miroir sur la carte (utile pour les rotations)
		void inverserImageFond();			//Effet miroir sur l'arrière de la carte (idem)
		void setValeurAbsolue(int valAbs);	//Modifie la valeur absolue de la carte (valAbs dans [0, 51])
		void setValeur(int val);			//Modifie la valeur simple de la carte (val dans [0, 12]
		void setFamille(int fam);			//Modifie la famille de la carte (fam dans [0, 4])
		QString getString();				//Carte en toutes lettres
		bool operator==(const CarteG &autre);//Egalité
		bool operator!=(const CarteG &autre);//Différence
		static int getValeur(int valAbs);
		static int getFamille(int valAbs);
		static int getCouleur(int valAbs);
		
			//A déclarer AVANT de se servir des CarteG ou bien le faire lors du premier appel de constructeur
		static void setFond(QString);		//Changer le fond commun chaque image verra son fond changé à partir de l'appel de changerImage()		
	protected:
		/** Translate the whole card */
		virtual void retranslate();

		/** Change event */
		virtual void changeEvent(QEvent *);
};

#endif
