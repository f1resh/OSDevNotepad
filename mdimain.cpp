#include "mdimain.h"
#include <QTextEdit>
#include <QMdiSubWindow>

void MdiMain::slotOpenNewDoc()
{
    this -> addSubWindow(new QTextEdit(this)) -> show();
    this -> nameDoc();
}

void MdiMain::nameDoc()
{
    docNameText = tr("Новый %1").arg(subWindowList().count());
    currentSubWindow() -> setWindowTitle(docNameText);
}
