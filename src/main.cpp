#include "FenetrePrincipale.h"
#include <QApplication>
#include <QTranslator>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QString locale = QLocale::system().name().section('_', 0, 0);
 
    QTranslator translator;
    translator.load(QString("translations/solitaire_") + locale);
    app.installTranslator(&translator);
	
	FenetrePrincipale fen;
	
	fen.show();
	
	return app.exec();
}
