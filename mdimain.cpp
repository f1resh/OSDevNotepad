#include "mdimain.h"
#include "printer.h"

//ceartes a new subwindow with text plain
MdiMain::MdiMain(QWidget *parent) : QMdiArea(parent)
{
    this -> setViewMode(QMdiArea::TabbedView);
    this -> setActivationOrder(QMdiArea::StackingOrder);
    this -> setTabsClosable(true);
    this -> setTabsMovable(true);
}

QTextEdit *MdiMain::getActiveDocument()
{
    QMdiSubWindow* active = activeSubWindow();
    if (active == nullptr) return nullptr;
    return qobject_cast<QTextEdit*>(active->widget());
}

void MdiMain::slotOpenNewDoc()
{
    this -> addSubWindow(new QTextEdit(this)) -> show();
    this -> nameDoc();
}

void MdiMain::slotPrint()
{
    QTextEdit* textEdit = getActiveDocument();
    if (textEdit) {
        Printer* printer = new Printer(textEdit);
        printer->Print();
        delete printer;
    }
}

//to do
void MdiMain::nameDoc()
{

}
