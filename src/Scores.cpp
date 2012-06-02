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
#include <iostream>

using namespace std;

/***********************
*	CONSTRUCTEUR	*
***********************/

Scores::Scores(QWidget *parent, QString fileName):
	QDialog(parent),
	fileName(fileName),
	scoresDB(NULL)
{
	setWindowTitle(tr("Meilleurs Scores du QSolitaire"));

	label = new QLabel(this);
	
	setGeometry(200, 200, 300, 400);
	
	initialiser();
}

/**************
 * DESTRUCTOR *
 **************/

Scores::~Scores() {
	if (scoresDB) {
		delete scoresDB;
	}
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
		if (!QFile::exists(fileName))
			reecrireScores = true;
	}
	else {
		if (!dossierCourant.mkdir("Autre"))
		{
			cerr<<"Erreur lors du chargement de Autre/scores.conf : impossible d'accéder au dossier ./Autre verifiez les droits d'accès."<<endl;
			erreurLireScores = true;
		}
		else {
			reecrireScores = true;
		}
	}

	if (reecrireScores) {
		this->reecrireScores();
	}
	else {
		scoresDB = new BDD(fileName);
	}
	if (!erreurLireScores)
	{
		if (scoresDB->size()) {
			label->setText(tr("<h1 style='text-align:center;'>Meilleurs Scores</h1>"));
			label->setText(label->text()+tr("<table><tr><th>Nom</th><th>Score</th></tr>"));
			for (int i=0; i<scoresDB->size(); i++)
			{
				if (scoresDB->at(i)->size()!=0)
					label->setText(label->text()+"<tr><td>"+scoresDB->at(i)->getNom()+"</td><td style='text-align:right;'>"+scoresDB->at(i)->at(0)+"</td></tr>");
			}
			label->setText(label->text()+"</table>");
		}
		else {
			label->setText(tr("<h1 style='text-align:center;'>No best score saved</h1>"));
		}
	}
}

/*****************************
*	REECRIRE SCORES	*
*****************************/

void Scores::reecrireScores()
{
	if (scoresDB) {
		delete scoresDB;
	}
	scoresDB = new BDD();
	if (!scoresDB->enregistrerSous(fileName))
		cerr<<"Erreur lors du chargement de Autre/scores.conf : impossible d'accéder au dossier ./Autre verifiez les droits d'accès. "<<endl;
}

/*****************************
* SLOT SAUVER QUITTER	*
****************************/

void Scores::slotAjouterScore(QString nom, int score)
{
	BDDElement *e = new BDDElement(nom);
	e->ajouterAttribut(QString::number(score));
	int indice = scoresDB->size();
	bool trouve = false;
	for (int i=0; i<scoresDB->size() && !trouve; i++)
		if (scoresDB->at(i)->size()!=0 && scoresDB->at(i)->at(0).toInt()<score)
		{
			indice = i;
			trouve = true;
		}
	scoresDB->insert(indice, e);
	if (!scoresDB->enregistrerSous(fileName))
		cerr<<"Erreur lors du chargement de "<<fileName.toStdString()<<" : impossible d'accéder au dossier ./Autre verifiez les droits d'accès. "<<endl;
}

/***************
*	EXEC	*
***************/

int Scores::exec(int score)
{
	int size = scoresDB->size();
	int lowestScore = size?scoresDB->at(size-1)->at(0).toInt():0;
	if (lowestScore < score)
	{
		bool ok = false;
		QString pseudo = QInputDialog::getText(this, tr("Meilleur Score!"), tr("Vous avez cumulé ")+QString::number(score)+tr(" points.<br />Quel est votre nom ?"), QLineEdit::Normal, QString(), &ok);
	
		if (ok && !pseudo.isEmpty())
			slotAjouterScore(pseudo, score);
		while (size>10) {
			scoresDB->removeAt(scoresDB->size()-1);
			size = scoresDB->size();
		}
	
		initialiser();
	}
	return QDialog::exec();
}
int Scores::exec()
{
	initialiser();
	return QDialog::exec();
}

void Scores::changeEvent(QEvent* event)
{
	if (event->type() == QEvent::LanguageChange) {
		retranslate();
	}

	QDialog::changeEvent(event);
}

/***************
 * RETRANSLATE *
 ***************/
void Scores::retranslate() {
	setWindowTitle(tr("Meilleurs Scores du QSolitaire"));
	initialiser();
}
