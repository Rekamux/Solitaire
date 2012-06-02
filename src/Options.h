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
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
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
			QGridLayout *LGroupeCasesACocher;
			
			QLabel *labelAnimation;
			QCheckBox *checkAnimation;
			QLabel *labelChrono;
			QCheckBox *checkChrono;
			QLabel *labelPoints;
			QCheckBox *checkPoints;
			QLabel *labelSilhouette;
			QCheckBox *checkSilhouette;
			QLabel *labelUneCarte;
			QRadioButton *radioUneCarte;
			QLabel *labelTroisCartes;
			QRadioButton *radioTroisCartes;

			QGroupBox *languagesGroupBox;
				QGridLayout *languagesLayout;
				// TODO adapt to existing translations
				QLabel *languagesLabels[2];
				QRadioButton *languagesRadioButtons[2];
				QString languagesStrings[2];
			
		QPushButton *boutonOk;
		QPushButton *boutonAnnuler;

		QApplication *application;
	protected:
		/** Retranslate */
		virtual void retranslate();

		/** Change event */
		virtual void changeEvent(QEvent *);
};

#endif
