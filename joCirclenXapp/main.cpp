#include "jocirclenxapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	joCirclenXapp w;
	w.show();
	return a.exec();
}
