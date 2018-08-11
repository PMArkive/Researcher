#include <QApplication>
#include <Forms/Researcher.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Researcher w;
    w.show();

    return a.exec();
}
