/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "Animations.h"

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
	if (!trouve)	
		QMessageBox::critical(0, "Destruction d'animation", "Impossible de trouver l'animation "+QString::number(id));
	if (isEmpty() && termineQuandVide)
		emit animationTerminee(getId());
}

/***********************
*	DESTRUCTEUR	*
***********************/

Animations::~Animations()
{
	if (!isEmpty())
		QMessageBox::critical(0, "Destruction d'Animations", "On détruit des Animations alors qu'elles ne sont pas toutes terminées!");		
	if (nbALancer!=0)
		QMessageBox::critical(0, "Destruction d'Animations", "On détruit des Animations alors qu'elles ne sont pas toutes lancées!");		
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
				QMessageBox::critical(0, "Timeout d'Animations", "nbALancer == "+QString::number(nbALancer)+" et pourtant toutes les animations sont lancées!");
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
		QMessageBox::critical(0, "Animations incorrectes", "Ajout d'un pointeur sur Animation nul!");		
}
