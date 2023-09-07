#pragma once
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QTextEdit.h>
#include <QtGui/QClipboard>
#include <QtWidgets/QApplication>

class CopyPasteCut : public QObject
{
    Q_OBJECT

private:
    QMdiArea* mdi;
public:
    CopyPasteCut(QMdiArea* m) : mdi(m)
    {

    };

public slots:
    void copyToClipboard();

    void pasteFromClipboard();

    void cutText();

};
