#include "mdimain.h"

//ceartes a new subwindow with text plain
MdiMain::MdiMain(QWidget *parent) : QMdiArea(parent)
{
    this -> setViewMode(QMdiArea::TabbedView);
    this -> setActivationOrder(QMdiArea::StackingOrder);
    this -> setTabsClosable(true);
    this -> setTabsMovable(true);
}

void MdiMain::slotOpenNewDoc()
{
    this -> addSubWindow(new QTextEdit(this)) -> show();
    this -> nameDoc();
}

//to do
void MdiMain::nameDoc()
{

}
