/*
*	Document produit par AXEL SCHUMACHER,
*	élève en license INFORMATIQUE 3ème année Semestre 5,
*	à l'université MONTPELLIER II,
*	pour l'UE Maîtrise des Médias de Communication.
*	
*	Encodage : ANSI
*	Version de Qt utilisée : 4.4.3
*/

#include "Options.h"
#include <QLocale>
#include <iostream>
using namespace std;

/***********************
*	CONSTRUCTEUR	*
***********************/

Options::Options(QWidget *parent, QApplication *app):
	QDialog(parent),
	application(app)
{
	setWindowTitle(tr("Options du QSolitaire"));
	
	LOptions = new QGridLayout(this);
	
	groupeCasesACocher = new QGroupBox(tr("Options"), this);
		LGroupeCasesACocher = new QGridLayout(groupeCasesACocher);
	
		labelAnimation = new QLabel(tr("Montrer les animations"));
		checkAnimation = new QCheckBox(groupeCasesACocher);
		labelAnimation->setBuddy(checkAnimation);
		LGroupeCasesACocher->addWidget(labelAnimation, 0, 0);
		LGroupeCasesACocher->addWidget(checkAnimation, 0, 1);

		labelChrono = new QLabel(tr("Chronometrer"));
		checkChrono = new QCheckBox(groupeCasesACocher);
		labelChrono->setBuddy(checkChrono);
		LGroupeCasesACocher->addWidget(labelChrono, 1, 0);
		LGroupeCasesACocher->addWidget(checkChrono, 1, 1);

		labelPoints = new QLabel(tr("Compter les points"));
		checkPoints = new QCheckBox(groupeCasesACocher);
		labelPoints->setBuddy(checkPoints);
		LGroupeCasesACocher->addWidget(labelPoints, 2, 0);
		LGroupeCasesACocher->addWidget(checkPoints, 2, 1);

		labelSilhouette = new QLabel(tr("Silhouette sous déplacement"));
		checkSilhouette = new QCheckBox(groupeCasesACocher);
		labelSilhouette->setBuddy(checkSilhouette);
		LGroupeCasesACocher->addWidget(labelSilhouette, 3, 0);
		LGroupeCasesACocher->addWidget(checkSilhouette, 3, 1);

		labelUneCarte = new QLabel(tr("Tirer une carte"));
		radioUneCarte = new QRadioButton(groupeCasesACocher);
		labelUneCarte->setBuddy(radioUneCarte);
		LGroupeCasesACocher->addWidget(labelUneCarte, 4, 0);
		LGroupeCasesACocher->addWidget(radioUneCarte, 4, 1);

		labelTroisCartes = new QLabel(tr("Tirer trois cartes"));
		radioTroisCartes = new QRadioButton(groupeCasesACocher);
		labelTroisCartes->setBuddy(radioTroisCartes);
		LGroupeCasesACocher->addWidget(labelTroisCartes, 5, 0);
		LGroupeCasesACocher->addWidget(radioTroisCartes, 5, 1);
		
		languagesGroupBox = new QGroupBox(tr("Program language"), this);
		languagesLayout = new QGridLayout(languagesGroupBox);

		// TODO adapt to existing translations
		languagesStrings[0] = "en";
		languagesStrings[1] = "fr";
		for (int i=0; i<2; i++) {
			languagesLabels[i] = new QLabel(languagesStrings[i]);
			languagesRadioButtons[i] = new QRadioButton(languagesGroupBox);
			languagesLabels[i]->setBuddy(languagesRadioButtons[i]);
			languagesLayout->addWidget(languagesLabels[i], i, 0);
			languagesLayout->addWidget(languagesRadioButtons[i], i, 1);
		}
		languagesGroupBox->setLayout(languagesLayout);

		LGroupeCasesACocher->addWidget(languagesGroupBox, 6, 0, 1, 2);
	groupeCasesACocher->setLayout(LGroupeCasesACocher);
	
	LOptions -> addWidget(groupeCasesACocher, 0, 0, 1, 2);
	
	boutonOk = new QPushButton(this);
		boutonOk->setText(tr("Appliquer"));
		connect(boutonOk, SIGNAL(clicked()), this, SLOT(slotSauverQuitter()));
		
	boutonAnnuler = new QPushButton(this);
		boutonAnnuler->setText(tr("Annuler"));
		connect(boutonAnnuler, SIGNAL(clicked()), this, SLOT(reject()));
		
	LOptions -> addWidget(boutonOk, 1, 0);
	LOptions -> addWidget(boutonAnnuler, 1, 1);
	
	initialiser();
}

/***********************
*	INITIALISER	*
***********************/

void Options::initialiser()
{
	bool reecrireConfig = false;
	bool erreurLireConfig = false;
	QDir dossierCourant;
	if (dossierCourant.exists("Autre"))
	{
		if (!QFile::exists("Autre/config.conf"))
		{
			reecrireConfig = true;
		}
	}
	else
	{
		if (!dossierCourant.mkdir("Autre"))
		{
			cerr<<"Erreur lors du chargement de Autre/config.conf : impossible d'accéder au dossier ./Autre verifiez les droits d'accès. "<<endl;
			erreurLireConfig = true;
		}
		else
		{
			reecrireConfig = true;
		}
	}
	if (reecrireConfig)
	{
		this->reecrireConfig();
	}
	if (!erreurLireConfig)
	{
		BDD *config = new BDD("Autre/config.conf");
		for (int i=0; i<config->size(); i++)
		{
			if (config->at(i)->getNom() == "animation")
			{
				int valeur = config->at(i)->at(0).toInt();
				if (valeur == 1)
					checkAnimation->setCheckState(Qt::Checked);
				else
					checkAnimation->setCheckState(Qt::Unchecked);
			}
			else if (config->at(i)->getNom() == "chrono")
			{
				int valeur = config->at(i)->at(0).toInt();
				if (valeur == 1)
					checkChrono->setCheckState(Qt::Checked);
				else
					checkChrono->setCheckState(Qt::Unchecked);
			}
			else if (config->at(i)->getNom() == "points")
			{
				int valeur = config->at(i)->at(0).toInt();
				if (valeur == 1)
					checkPoints->setCheckState(Qt::Checked);
				else
					checkPoints->setCheckState(Qt::Unchecked);
			}
			else if (config->at(i)->getNom() == "silhouette")
			{
				int valeur = config->at(i)->at(0).toInt();
				if (valeur == 1)
					checkSilhouette->setCheckState(Qt::Checked);
				else
					checkSilhouette->setCheckState(Qt::Unchecked);
			}
			else if (config->at(i)->getNom() == "nb_cartes_donnees")
			{
				if (config->at(i)->at(0).toInt() == 3)
					radioTroisCartes->setChecked(true);
				else
					radioUneCarte->setChecked(true);
			}
			else if (config->at(i)->getNom() == "language") {
				QString l = config->at(i)->at(0);
				// TODO adapt to existing translations
				int j;
				for (j=0; j<2; j++) {
					if (l == languagesStrings[j]) {
						languagesRadioButtons[j]->setChecked(true);
						break;
					}
				}
				if (j == 2) {
					languagesRadioButtons[0]->setChecked(true);
				}
			}
		}
	}
	updateLanguage();
}

/*****************************
*	REECRIRE CONFIG	*
*****************************/

void Options::reecrireConfig()
{
	BDD *config = new BDD("Autre/config.conf");
	BDDElement *e = new BDDElement("animation");
	e->ajouterAttribut("1");
	config->ajouterElement(e);
	e = new BDDElement("chrono");
	e->ajouterAttribut("0");
	config->ajouterElement(e);
	e = new BDDElement("silhouette");
	e->ajouterAttribut("0");
	config->ajouterElement(e);
	e = new BDDElement("nb_cartes_donnees");
	e->ajouterAttribut("1");
	config->ajouterElement(e);
	e = new BDDElement("point");
	e->ajouterAttribut("0");
	config->ajouterElement(e);
	e = new BDDElement("language");
	e->ajouterAttribut("en");
	config->ajouterElement(e);
	if (!config->enregistrerSous("Autre/config.conf"))
		cerr<<"Erreur lors du chargement de Autre/config.conf : impossible d'accéder au dossier ./donnees verifiez les droits d'accès. "<<endl;
	updateLanguage();
	delete config;	
}

/*******************
 * UPDATE LANGUAGE *
 *******************/

void Options::updateLanguage() {
	BDD *config = new BDD("Autre/config.conf");
	for (int i=0; i<config->size(); i++) {
		if (config->at(i)->getNom() == "language") {
			QString locale = config->at(i)->at(0);
			QString file_start = "translations/solitaire_";
			QTranslator *translator = new QTranslator();
			if (!QFile(file_start + locale + QString(".qm")).exists()) {
				locale = QString("en");
			}
			translator->load(file_start + locale);
			application->installTranslator(translator);
			break;
		}
	}
}

/*****************************
* SLOT SAUVER QUITTER	*
****************************/

void Options::slotSauverQuitter()
{
	BDD *config = new BDD;
	BDDElement *e = new BDDElement("animation");
	if (checkAnimation->checkState() == Qt::Checked)
		e->ajouterAttribut("1");
	else
		e->ajouterAttribut("0");
	config->ajouterElement(e);
	e = new BDDElement("chrono");
	if (checkChrono->checkState() == Qt::Checked)
		e->ajouterAttribut("1");
	else
		e->ajouterAttribut("0");
	config->ajouterElement(e);
	e = new BDDElement("points");
	if (checkPoints->checkState() == Qt::Checked)
		e->ajouterAttribut("1");
	else
		e->ajouterAttribut("0");
	config->ajouterElement(e);
	e = new BDDElement("silhouette");
	if (checkSilhouette->checkState() == Qt::Checked)
		e->ajouterAttribut("1");
	else
		e->ajouterAttribut("0");
	config->ajouterElement(e);
	e = new BDDElement("nb_cartes_donnees");
	if (radioUneCarte->isChecked())
		e->ajouterAttribut("1");
	else
		e->ajouterAttribut("3");
	config->ajouterElement(e);
	e = new BDDElement("language");
	// TODO handle any count of languages
	for (int i=0; i<2; i++) {
		if (languagesRadioButtons[i]->isChecked()) {
			e->ajouterAttribut(languagesStrings[i]);
			break;
		}
	}
	config->ajouterElement(e);
	if (!config->enregistrerSous("Autre/config.conf"))
		cerr<<"Erreur lors du chargement de Autre/config.conf : impossible d'accéder au dossier ./donnees verifiez les droits d'accès. "<<endl;
	updateLanguage();
	delete config;	
	accept();
}

void Options::changeEvent(QEvent* event)
{
	if (event->type() == QEvent::LanguageChange) {
		retranslate();
	}

	QDialog::changeEvent(event);
}

/***************
 * RETRANSLATE *
 ***************/
void Options::retranslate() {
	setWindowTitle(tr("Options du QSolitaire"));

	groupeCasesACocher->setTitle(tr("Options"));
	labelAnimation->setText(tr("Montrer les animations"));
	labelChrono->setText(tr("Chronometrer"));
	labelPoints->setText(tr("Compter les points"));
	labelSilhouette->setText(tr("Silhouette sous déplacement"));
	labelUneCarte->setText(tr("Tirer une carte"));
	labelTroisCartes->setText(tr("Tirer trois cartes"));

	languagesGroupBox->setTitle(tr("Program language"));

	boutonOk->setText(tr("Appliquer"));
	boutonAnnuler->setText(tr("Annuler"));
}
