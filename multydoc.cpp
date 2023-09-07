#include "multydoc.h"
#include "qtextedit.h"

multyDoc::multyDoc(QMdiArea*parent)
    : QMdiArea{parent}
{

}

void multyDoc::openNewDoc()
{
    mdiArea -> addSubWindow(new QTextEdit(this));
}
