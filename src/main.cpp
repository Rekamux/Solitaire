#include "FenetrePrincipale.h"
#include <QApplication>
#include <QTranslator>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QString locale = QLocale::system().name().section('_', 0, 0);
	QString file_start = "translations/solitaire_";
	QTranslator translator;
	if (!QFile(file_start + locale + QString(".qm")).exists()) {
		locale = QString("en");
	}
	translator.load(file_start + locale);
	app.installTranslator(&translator);
	
	FenetrePrincipale fen(&app);
	
	fen.show();
	
	return app.exec();
}
