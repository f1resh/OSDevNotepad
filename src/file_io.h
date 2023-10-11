#pragma once

#include <QString>
#include <QDir>

class FileIO
{
private:
    QString content_ = "";
    QDir path_;
    QString filters_;
    QString filename_;
public:
    FileIO(const QString& filters, const QDir& path) : filters_(filters), path_(path) {};
    FileIO();
    ~FileIO();

    bool Load();
    bool Save(QString&);
    QString getFileName();
    QString getContent();
};


