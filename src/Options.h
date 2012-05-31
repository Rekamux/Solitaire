/*
*	Document produit par AXEL SCHUMACHER,
*	�l�ve en license INFORMATIQUE 3�me ann�e Semestre 5,
*	� l'universit� MONTPELLIER II,
*	pour l'UE Ma�trise des M�dias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilis�e : 4.4.3
*/

#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QMessageBox>
#include <QApplication>
#include <QTranslator>

#include "BDDElement.h"
#include "BDD.h"

class Options : public QDialog
{
	Q_OBJECT
	
	public:
	
		//Constructeur
		Options(QWidget *parent, QApplication *app);
			
		//Initialiser les boutons
		void initialiser();
		
		//Reecrire le fichier de config
		void reecrireConfig();

		// Change language
		void updateLanguage();
	
	public slots:
	
		//Sauver et quitter
		void slotSauverQuitter();
	
	private:
		
		QGridLayout *LOptions;
		
		//Cases � cocher
		QGroupBox *groupeCasesACocher;
			QFormLayout *LGroupeCasesACocher;
			
			QCheckBox *checkAnimation;
			QCheckBox *checkChrono;
			QCheckBox *checkPoints;
			QCheckBox *checkSilhouette;
			QRadioButton *radioUneCarte;
			QRadioButton *radioTroisCartes;

			QGroupBox *languagesGroupBox;
				QFormLayout *languagesFormLayout;
				// TODO adapt to existing translations
				QRadioButton *languagesRadioButtons[2];
				QString languagesString[2];
			
		QPushButton *boutonOk;
		QPushButton *boutonAnnuler;

		QApplication *application;
};

#endif
