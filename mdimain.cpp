#include "mdimain.h"
#include <QTextEdit>
#include <QMdiSubWindow>

//ceartes a new subwindow with text plain
void MdiMain::slotOpenNewDoc()
{
    this -> addSubWindow(new QTextEdit(this)) -> show();
    this -> nameDoc();
}

//to do
void MdiMain::nameDoc()
{

}
