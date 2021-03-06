/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

#ifndef SCORES_H
#define SCORES_H

#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>
#include <QEvent>

#include "BDDElement.h"
#include "BDD.h"

class Scores : public QDialog
{
	Q_OBJECT
	
	public:
	
		//Constructeur
		Scores(QWidget *parent, QString fileName);

		//Destructor
		~Scores();
		
		//Reecrire le fichier de scores
		void reecrireScores();
	
	public slots:
	
		//AjouterScore
		void slotAjouterScore(QString nom, int score);
		
		//Executer la fenetre
		int exec(int score);
		int exec();
	
	private:
	
		void initialiser();
		QLabel *label;
		QString fileName;
		BDD *scoresDB;

	protected:
		/** Retranslate */
		virtual void retranslate();

		/** Change event */
		virtual void changeEvent(QEvent *);
};

#endif
