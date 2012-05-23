#include "FenetrePrincipale.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	FenetrePrincipale fen;
	
	fen.show();
	
	return app.exec();
}
