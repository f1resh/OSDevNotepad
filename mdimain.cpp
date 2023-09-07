#include "mdimain.h"
#include "mainwindow.h"
#include <QTextEdit>

mdiMain::mdiMain(QMdiArea*parent)
    : QMdiArea{parent}
{

}

void mdiMain::slotOpenNewDoc()
{
    //mdi -> addSubWindow(new QTextEdit());
}
