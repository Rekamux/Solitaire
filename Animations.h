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
*	CLASSE ANIMATIONS
*	Gère plusieurs  animations du jeu en tant qu'une seule avec un décalage entre chacune
*/

#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "Animation.h"

class Animations : public AnimationAbstraite, public QList<AnimationAbstraite *>
{
	Q_OBJECT
		
	public slots:
		virtual void slotDemarrer();
		//Détruire une animation quand elle se termine et emettre animationTerminee si la liste est vide
		virtual void slotDetruireAnimation(int id);
		//Lancer une nouvelle animation si il ya lieu
		virtual void slotTimeout();
		
	signals:
		virtual void animationTerminee(int);//Pour indiquer à ListeAnimation que le temps est venu de détruire cet individu
		
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
								
		int nbALancer;			//Nombre d'Animation restantes à lancer
};

#endif
