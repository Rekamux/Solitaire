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
*	CLASSE CARTEG
*	Carte graphique
*
*	H�rite � la fois de QGraphicsRectItem
*	Repr�sentation d'une carte dans la Sc�ne

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
		int valeurAbsolue;					//Valeur absolue de la carte qui la d�termine enti�rement comprise entre 0 et 51
		static QStringList listeValeur;		//Valeur de la carte en toute lettres
		static QStringList listeFamille;	//Famille de la carte en toute lettres
		static QStringList listeCouleur;	//Couleur de la carte en toute lettres
		static QString fond;				//Chemin de l'image arri�re
		bool cache;							//La carte est retourn�e
		bool deplacable;					//La carte est d�placable
		QPixmap *devant;					//L'image avant
		QPixmap *derriere;					//L'image arri�re
		QString fondPrecedent;				//Pour d�terminer si il y a besoin de changer le fond lors de l'appel de changerImage()
		
	public:
		//Constructeur
			//x : position en abscisse
			//y : position en ordonn�e
			//l : largeur
			//h : hauteur
			//fond : chemin constant de la Classe Widget qui indique o� prendre l'image arri�re
			//parent : Cartes o� se trouve la carteG
			//si on change de fond,
			//chaque image verra son fond chang� � partir de l'appel de changerImage()
		CarteG(int x, int y, int val, QGraphicsItem *parent = NULL, int h=71, int l=96, QString fond="");
		
		//Destructeur
		~CarteG();
		
		//Accesseurs
		bool getCache() const;				//Si la carte est retourn�e
		bool getDeplacable() const;			//Si la carte est d�placable
		QPixmap getPixmap() const;			//Image avant de la carte
		QString getFond() const;			//L'image de fond commun
		int getValeurAbsolue() const;		//Retourne la valeur absolue de la carte, comprise entre 0 et 51
		int i() const;						//M�me chose, simple commodit�
		int getValeur() const;				//Retourne la valeur simple de la carte
		QString getValeurString() const;	//Retourne la valeur en toutes lettres
		int getFamille() const;				//Retourne la famille de la carte comprise entre 0 et 3
		QString getFamilleString() const;	//Retourne la famille en toutes lettres
		int getCouleur() const;				//Retourne 0 ou 1 pour la couleur
		QString getCouleurString() const;	//Retourne la couleur en toutes lettres

		
		//M�thodes et modificateurs
		void changerImage();				//Mettre � jour l'image en fonction de cache	
		void setCache(bool);				//Changer la valeur de cache
		void setDeplacable(bool);			//Changer la valeur de deplacable
		void inverserImage();				//Effet miroir sur la carte (utile pour les rotations)
		void inverserImageFond();			//Effet miroir sur l'arri�re de la carte (idem)
		void setValeurAbsolue(int valAbs);	//Modifie la valeur absolue de la carte (valAbs dans [0, 51])
		void setValeur(int val);			//Modifie la valeur simple de la carte (val dans [0, 12]
		void setFamille(int fam);			//Modifie la famille de la carte (fam dans [0, 4])
		QString getString();				//Carte en toutes lettres
		bool operator==(const CarteG &autre);//Egalit�
		bool operator!=(const CarteG &autre);//Diff�rence
		static int getValeur(int valAbs);
		static int getFamille(int valAbs);
		static int getCouleur(int valAbs);
		
			//A d�clarer AVANT de se servir des CarteG ou bien le faire lors du premier appel de constructeur
		static void setFond(QString);		//Changer le fond commun chaque image verra son fond chang� � partir de l'appel de changerImage()		
	protected:
		/** Translate the whole card */
		virtual void retranslate();

		/** Change event */
		virtual void changeEvent(QEvent *);
};

#endif
