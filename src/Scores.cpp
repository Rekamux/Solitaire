/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "Scores.h"

/***********************
*	CONSTRUCTEUR	*
***********************/

Scores::Scores(QWidget *parent) : QDialog(parent)
{
	setWindowTitle(tr("Meilleurs Scores du QSolitaire"));

	label = new QLabel(this);
	
	setGeometry(200, 200, 300, 400);
	
	initialiser();
}

/***********************
*	INITIALISER	*
***********************/

void Scores::initialiser()
{
	bool reecrireScores = false;
	bool erreurLireScores = false;
	QDir dossierCourant;
	if (dossierCourant.exists("Autre"))
	{
		if (!QFile::exists("Autre/scores.conf"))
			reecrireScores = true;
	}
	else
		if (!dossierCourant.mkdir("Autre"))
		{
			QMessageBox::critical(this, tr("Erreur lors du chargement de Autre/scores.conf"), tr("Impossible d'accéder au dossier ./Autre verifiez les droits d'accès. "));
			erreurLireScores = true;
		}
		else
			reecrireScores = true;
	if (reecrireScores)
		this->reecrireScores();
	if (!erreurLireScores)
	{
		label->setText(tr("<h1 style='text-align:center;'>Meilleurs Scores</h1>"));
		BDD *scores = new BDD("Autre/scores.conf");
		label->setText(label->text()+"<table><tr><th>Nom</th><th>Score</th></tr>");
		for (int i=0; i<scores->size(); i++)
		{
			if (scores->at(i)->size()!=0)
				label->setText(label->text()+tr("<tr><td>")+scores->at(i)->getNom()+tr("</td><td>")+scores->at(i)->at(0)+"</td></tr>");
		}
		label->setText(label->text()+"</table>");
	}
}

/*****************************
*	REECRIRE SCORES	*
*****************************/

void Scores::reecrireScores()
{
	BDD *score = new BDD("Autre/scores.conf");
	if (!score->enregistrerSous("Autre/scores.conf"))
		QMessageBox::critical(this, tr("Erreur lors du chargement de Autre/scores.conf"), tr("Impossible d'accéder au dossier ./Autre verifiez les droits d'accès. "));
	delete score;	
}

/*****************************
* SLOT SAUVER QUITTER	*
****************************/

void Scores::slotAjouterScore(QString nom, int score)
{
	BDD *scoreDB = new BDD("Autre/scores.conf");
	BDDElement *e = new BDDElement(nom);
	e->ajouterAttribut(QString::number(score));
	int indice = scoreDB->size();
	bool trouve = false;
	for (int i=0; i<scoreDB->size() && !trouve; i++)
		if (scoreDB->at(i)->size()!=0 && scoreDB->at(i)->at(0).toInt()<score)
		{
			indice = i;
			trouve = true;
		}
	scoreDB->insert(indice, e);
	if (!scoreDB->enregistrerSous("Autre/scores.conf"))
		QMessageBox::critical(this, tr("Erreur lors du chargement de Autre/scores.conf"), tr("Impossible d'accéder au dossier ./Autre verifiez les droits d'accès. "));
	delete scoreDB;	
}

/***************
*	EXEC	*
***************/

int Scores::exec(bool ajouter, int score)
{
	if (ajouter)
	{
		bool ok = false;
		QString pseudo = QInputDialog::getText(this, tr("Meilleur Score!"), tr("Vous avez cumulé ")+QString::number(score)+tr(" points.<br />Quel est votre nom ?"), QLineEdit::Normal, QString(), &ok);
	
		if (ok && !pseudo.isEmpty())
			slotAjouterScore(pseudo, score);
	
		initialiser();
	}
	return QDialog::exec();
}
int Scores::exec()
{
	initialiser();
	return QDialog::exec();
}

