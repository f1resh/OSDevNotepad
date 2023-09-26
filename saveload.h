#pragma once
#include <QMdiArea>
#include <QDir>

class SaveLoad : public QObject
{
    Q_OBJECT
private:
    QMdiArea* mdi;
    QString filters;
    QString path;
public:
    SaveLoad(QMdiArea* m) : mdi(m)
    {
        filters = tr("Text file(*.txt)");
        path = QDir::homePath();
    };

public slots:
    void SaveActiveTabToFile();
    void LoadTabFromFile();
};

