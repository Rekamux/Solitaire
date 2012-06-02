/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

#include "Animations.h"

#include <iostream>

using namespace std;

/*************************
*	CONSTRUCTEUR	*
*************************/

Animations::Animations(int decalage, bool arret) : AnimationAbstraite()
{
	termineQuandVide = arret;
	timer->setInterval(decalage);
	nbALancer = 0;
}


/**********************************
*	SLOT DETRUIRE ANIMATION	*
**********************************/

#include <iostream>
void Animations::slotDetruireAnimation(int id)
{
	bool trouve = false;
	for (int i=0; i<size() && !trouve; i++)
		if (at(i)->getId() == id)
		{
			trouve = true;
			delete operator[](i);
			removeAt(i);
		}
	if (!trouve) {
		cerr<<"Destruction d'animation : impossible de trouver l'animation "<<id<<endl;
	}
	if (isEmpty() && termineQuandVide)
		emit animationTerminee(getId());
}

/***********************
*	DESTRUCTEUR	*
***********************/

Animations::~Animations()
{
	if (!isEmpty())
		cerr<<"Destruction d'Animations : on d�truit des Animations alors qu'elles ne sont pas toutes termin�es!"<<endl;
	if (nbALancer!=0)
		cerr<<"Destruction d'Animations : on d�truit des Animations alors qu'elles ne sont pas toutes lanc�es!"<<endl;
}

/*****************************
*	SLOT DEMARRER		*
*****************************/

void Animations::slotDemarrer()
{
	if (termineQuandVide)
	{
		first()->slotDemarrer();
		nbALancer--;
	}
	timer->start();
}

/*************************
*	SLOT TIMEOUT		*
*************************/

void Animations::slotTimeout()
{
	if (termineQuandVide) {
		if (isEmpty()) {
			emit animationTerminee(getId());
        }
		else if (nbALancer!=0) {
			//Lancement de la suivante
			bool trouve = false;
			for (int i=0; i<size() && !trouve; i++)
				if (!at(i)->getEstLancee())
				{
					trouve = true;
					at(i)->slotDemarrer();
					nbALancer--;
				}
			if (!trouve) {
				cerr<<"Timeout d'Animations : nbALancer == "<<nbALancer<<" et pourtant toutes les animations sont lanc�es!"<<endl;
            }
		}
    }
	passages++;
}

/**********************************
*	AJOUTER	ANIMATION	*
**********************************/

void Animations::ajouterAnimation(AnimationAbstraite *ajout)
{
	if (ajout != NULL)
	{
		append(ajout);
		connect(ajout, SIGNAL(animationTerminee(int)), this, SLOT(slotDetruireAnimation(int)));
		nbALancer++;
		if (!termineQuandVide)
			ajout->slotDemarrer();
	}
	else
		cerr<<"Animations incorrectes : ajout d'un pointeur sur Animation nul!"<<endl;
}

/********
 * KILL *
 ********/

void Animations::kill() {
	timer->stop();
	for (int i=size()-1; i>=0; i--) {
		at(i)->kill();
		delete operator[](i);
		removeAt(i);
	}
	nbALancer = 0;
}
