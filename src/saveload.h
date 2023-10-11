#pragma once
#include <QMdiArea>
#include <QDir>
#include "mdimain.h"

class SaveLoad : public QObject
{
    Q_OBJECT
private:
    MdiMain* mdi;
    QString filters;
    QString path;
public:
    SaveLoad(MdiMain* m) : mdi(m)
    {
        filters = tr("Text file(*.txt)");
        path = QDir::homePath();
    };

public slots:
    void SaveActiveTabToFile();
    void LoadTabFromFile();
};

