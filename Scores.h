/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#ifndef SCORES_H
#define SCORES_H

#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>

#include "BDDElement.h"
#include "BDD.h"

class Scores : public QDialog
{
	Q_OBJECT
	
	public:
	
		//Constructeur
		Scores(QWidget *parent);
		
		//Reecrire le fichier de scores
		void reecrireScores();
	
	public slots:
	
		//AjouterScore
		void slotAjouterScore(QString nom, int score);
		
		//Executer la fenetre
		int exec(bool ajouter, int score);
		int exec();
	
	private:
	
		void initialiser();
		QLabel *label;
};

#endif
