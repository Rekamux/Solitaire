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
*	CLASSE ANIMATIONS
*	G�re plusieurs  animations du jeu en tant qu'une seule avec un d�calage entre chacune
*/

#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "Animation.h"

class Animations : public AnimationAbstraite, public QList<AnimationAbstraite *>
{
	Q_OBJECT
		
	public slots:
		virtual void slotDemarrer();
		//D�truire une animation quand elle se termine et emettre animationTerminee si la liste est vide
		virtual void slotDetruireAnimation(int id);
		//Lancer une nouvelle animation si il ya lieu
		virtual void slotTimeout();
		
	signals:
		virtual void animationTerminee(int);//Pour indiquer � ListeAnimation que le temps est venu de d�truire cet individu
		
	public:
	//Constructeur
		Animations(int decalage=0, bool arret=true);
		
	//Destructeur
		virtual ~Animations();
		
	//Ajouter une animation
		virtual void ajouterAnimation(AnimationAbstraite *ajout);
		
	protected:
		bool termineQuandVide;	//Emet ou non le signal d'auto-destruction quand l'animation est vide
								//Si vrai, il est impossible de rajouter une animation quand le timer est parti (slotDemarrer())
								
		int nbALancer;			//Nombre d'Animation restantes � lancer
};

#endif
