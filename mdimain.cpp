#include "mdimain.h"
#include <QTextEdit>


void MdiMain::slotOpenNewDoc(MdiMain *mdi)
{
    mdi -> addSubWindow(new QTextEdit());
}
