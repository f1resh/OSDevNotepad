#ifndef MDIMAIN_H
#define MDIMAIN_H

#include "qtextedit.h"
#include <QWidget>
#include <QMdiArea>
#include <QPushButton>
#include <QMdiSubWindow>


class MdiMain : public QMdiArea
{
    Q_OBJECT
private:
    QString docNameText;

public:
    MdiMain(QWidget *parent = nullptr) : QMdiArea(parent)
    {
        this -> setViewMode(QMdiArea::TabbedView);
        this -> setActivationOrder(QMdiArea::StackingOrder);
        this -> setTabsClosable(true);
        this -> setTabsMovable(true);
        this -> addSubWindow(new QTextEdit(this));
        this -> nameDoc();
    }

public slots:
    void slotOpenNewDoc();

signals:

private:
    void nameDoc();
};

#endif // MDIMAIN_H
