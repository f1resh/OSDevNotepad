#include "saveload.h"

#include <QFile>
#include <QTextEdit>
#include <QMdiSubWindow>
#include "file_io.h"


void SaveLoad::SaveActiveTabToFile()
{
    if (mdi == nullptr) return;
    QMdiSubWindow* active = mdi->activeSubWindow();
    if (active == nullptr) return;

    FileIO file(filters,path);
    QString content = (qobject_cast<QTextEdit*>(active->widget()))->toPlainText();
    if (file.Save(content)){
        QFileInfo fInfo(file.getFileName());
        active->setWindowTitle(fInfo.fileName());
    }
}

void SaveLoad::LoadTabFromFile()
{
    if (mdi == nullptr) return;

    FileIO file(filters,path);
    if (file.Load()){
        QString content = file.getContent();
        QFileInfo fInfo(file.getFileName());
        QMdiSubWindow* newTab = mdi->addSubWindow(new QTextEdit(mdi));
        newTab->show();
        qobject_cast<QTextEdit*>(newTab->widget())->setPlainText(content);
        newTab->setWindowTitle(fInfo.fileName());
    }
}
