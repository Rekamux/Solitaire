/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "AnimationColoration.h"

/*************************
*	CONSTRUCTEUR		*
*************************/
AnimationColoration::AnimationColoration(CarteG *carte, int duree, QPointF depart, QGraphicsItem *parent) : Animation(carte, duree, parent, depart, true, NULL, (int)(carte->zValue()))
{
	montreQuandTermine=true;
	this->duree = duree;
}

/********************
*	DESTRUCTEUR	*
********************/

AnimationColoration::~AnimationColoration()
{}

/*************************
*	SLOT TIMEOUT		*
*************************/

void AnimationColoration::slotTimeout()
{
	if (passages >= (qreal)duree/intervalle)
	{
		carteOrigine->show();
		emit carteLibre(copie->i());
	}
	else if (passages==0)
	{
		QPixmap tempPixmap;
		tempPixmap = copie->brush().texture();
		if (copie->i()==0)
			tempPixmap.fill(Qt::transparent);
		QPainter painter;
		painter.begin(&tempPixmap);
		painter.fillRect(copie->brush().texture().rect(), QColor(0, 0, 200, 150));
		painter.end();
		copie->setBrush(QBrush(tempPixmap));
	}
	passages++;
}

/***********************
*	SLOT DEMARRER	*
***********************/

void AnimationColoration::slotDemarrer()
{
	Animation::slotDemarrer();	
	copie->setCache(false);
	if (copie->i() == 0)
		copie->setBrush(Qt::transparent);
}
