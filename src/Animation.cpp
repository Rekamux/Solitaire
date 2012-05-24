/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "Animation.h"

/*************************
*	CONSTRUCTEUR	*
*************************/

Animation::Animation(CarteG *carte, int duree, QGraphicsItem *parent, QPointF depart, bool montre, CarteG *copieUtilisee, int zValue)
{
	if (carte==NULL)
	{
		QMessageBox::critical(0, "Animation incorrecte", "Demande d'une animation avec un pointeur sur CarteG null!");
		copie = NULL;
		timer = NULL;
	}
	else
	{			
		carteOrigine = carte;

		if (copieUtilisee == NULL)
		{
			detruireCopie = true;
			copie = new CarteG(0, 0, carte->i(), parent, 71, 96, carte->getFond());
		}
		else
		{
			detruireCopie = false;
			copie = copieUtilisee;
		}
		
		montreQuandTermine=montre;
	
		this->duree = duree;	
		
		this->depart = depart;
		
		copie->setZValue(zValue);
		copie->hide();
	}	
}

/********************
*	DESTRUCTEUR	*
********************/

Animation::~Animation()
{
	if (copie != NULL && detruireCopie)
		delete copie;
}

/***********************
*	CACHER ORIGINE	*
***********************/

void Animation::cacherOrigine()
{
	carteOrigine->hide();
	copie->show();
}

/*****************
*	GET COPIE	*
*****************/

CarteG *Animation::getCopie()
{
	return copie;
}

/********************
*	GET ORIGINE	*
********************/

CarteG *Animation::getOrigine()
{
	return carteOrigine;
}

/***********************
*	SLOT DEMARRER	*
***********************/

void Animation::slotDemarrer()
{
	carteOrigine->hide();
	copie->show();
	timer->start();
	estLancee = true;
	copie->setDeplacable(false);
	copie->setPos(depart);
}
