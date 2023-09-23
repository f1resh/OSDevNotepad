#include "file_io.h"

#include <QFileDialog>
#include <QTextStream>

FileIO::FileIO()
{
    filters_ = "All files(*.*)";
    path_ = QDir::current();
}

FileIO::~FileIO()
{
}

bool FileIO::Load()
{
    QString filepath = QFileDialog::getOpenFileName(nullptr, "Open file", path_.path(), filters_);
    if (filepath.length()>0){

        QFile file(filepath);
        if (file.open(QFile::ReadOnly | QFile::ExistingOnly)){
            QTextStream stream(&file);
            content_ = stream.readAll();
            file.close();
            filename_ = filepath;
            return true;
        }else{
            //cannot open for read
            file.close();
            return false;
        }

    }else{
        //path is not correct
        return false;
    }
}

bool FileIO::Save(QString &text)
{
    QString filepath = QFileDialog::getSaveFileName(nullptr, "Save file", path_.path(), filters_);
    if (filepath.length()>0){

        if (!filepath.endsWith(".txt")) filepath += ".txt";

        QFile file(filepath);

        if (file.open(QFile::WriteOnly)){
            QTextStream stream(&file);
            stream << text;
            file.close();
            filename_ = filepath;
            return true;
        }else{
            //cannot open for write
            file.close();
            return false;
        }

    }else{
        //path is not correct
        return false;
    }
}

QString FileIO::getFileName()
{
    return filename_;
}

QString FileIO::getContent()
{
    return content_;
}




