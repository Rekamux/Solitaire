/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "AnimationsColorations.h"
#include <iostream>

using namespace std;

/*************************
*	CONSTRUCTEUR	*
*************************/

AnimationsColorations::AnimationsColorations() : Animations(0, false)
{
}

/**********************************
*	SLOT DETRUIRE ANIMATION	*
**********************************/

void AnimationsColorations::slotDetruireAnimation(int val)
{
	bool trouve = false;
	for (int i=0; i<size() && !trouve; i++)
		if (static_cast<AnimationColoration*>(at(i))->getCopie()->i() == val)
		{
			trouve = true;
			delete operator[](i);
			removeAt(i);
		}
	if (!trouve) {
		cerr<<"Destruction d'animation : impossible de trouver l'animation "<<val<<endl;
	}
	if (isEmpty() && termineQuandVide) {
		emit animationTerminee(getId());
	}
}

/********************
*	SLOT VIDER	*
********************/

void AnimationsColorations::slotVider()
{
	while (!isEmpty())
	{
		static_cast<AnimationColoration*>(at(0))->getOrigine()->show();
		delete operator[](0);
		removeAt(0);
	}
}


/**********************************
*	AJOUTER	ANIMATION	*
**********************************/

void AnimationsColorations::ajouterAnimation(AnimationColoration *ajout)
{
	if (ajout != NULL)
	{
		bool trouve = false;
		int iAjout = ajout->getCopie()->i();
		for (int i=0; i<size() && !trouve; i++)
			if (static_cast<AnimationColoration*>(at(i))->getCopie()->i()==iAjout)
				trouve = true;
		if (!trouve)
		{
			append(ajout);
			connect(ajout, SIGNAL(carteLibre(int)), this, SLOT(slotDetruireAnimation(int)));
			nbALancer++;
			ajout->slotDemarrer();
		}
	}
	else {
		cerr<<"Animations incorrectes : ajout d'un pointeur sur Animation nul!"<<endl;		
	}
}
