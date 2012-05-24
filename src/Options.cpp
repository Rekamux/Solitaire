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

/***********************
*	CONSTRUCTEUR	*
***********************/

Options::Options(QWidget *parent) : QDialog(parent)
{
	setWindowTitle(tr("Options du QSolitaire"));
	
	LOptions = new QGridLayout(this);
	
	groupeCasesACocher = new QGroupBox(tr("Options"), this);
		LGroupeCasesACocher = new QFormLayout(groupeCasesACocher);
	
		checkAnimation = new QCheckBox(groupeCasesACocher);
		checkChrono = new QCheckBox(groupeCasesACocher);
		checkPoints = new QCheckBox(groupeCasesACocher);
		checkSilhouette = new QCheckBox(groupeCasesACocher);
		radioUneCarte = new QRadioButton(groupeCasesACocher);
		radioTroisCartes = new QRadioButton(groupeCasesACocher);
		
		LGroupeCasesACocher -> addRow(tr("Montrer les animations"), checkAnimation);
		LGroupeCasesACocher -> addRow(tr("Chronometrer"), checkChrono);
		LGroupeCasesACocher -> addRow(tr("Compter les points"), checkPoints);
		LGroupeCasesACocher -> addRow(tr("Silhouette sous déplacement"), checkSilhouette);
		LGroupeCasesACocher -> addRow(tr("Tirer une carte"), radioUneCarte);
		LGroupeCasesACocher -> addRow(tr("Tirer trois cartes"), radioTroisCartes);
	
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
			QMessageBox::critical(this, tr("Erreur lors du chargement de Autre/config.conf"), tr("Impossible d'accéder au dossier ./Autre verifiez les droits d'accès. "));
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
		}
	}
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
	if (!config->enregistrerSous("Autre/config.conf"))
		QMessageBox::critical(this, tr("Erreur lors du chargement de Autre/config.conf"), tr("Impossible d'accéder au dossier ./donnees verifiez les droits d'accès. "));
	delete config;	
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
	if (!config->enregistrerSous("Autre/config.conf"))
		QMessageBox::critical(this, tr("Erreur lors du chargement de Autre/config.conf"), tr("Impossible d'accéder au dossier ./donnees verifiez les droits d'accès. "));
	delete config;	
	accept();
}
