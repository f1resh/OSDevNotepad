#pragma once
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QTextEdit.h>
#include <QtGui/QClipboard>
#include <QtWidgets/QApplication>
#include "mdimain.h"

class CopyPasteCut : public QObject
{
    Q_OBJECT

private:
    MdiMain* mdi;
public:
    CopyPasteCut(MdiMain* m) : mdi(m)
    {

    };

public slots:
    void slotCopyToClipboard();
    void slotPasteFromClipboard();
    void slotCutText();

};
