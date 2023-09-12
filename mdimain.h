#ifndef MDIMAIN_H
#define MDIMAIN_H

#include "qtextedit.h"
#include <QWidget>
#include <QMdiArea>
#include <QPushButton>


class MdiMain : public QMdiArea
{
    Q_OBJECT
private:
    QMdiArea *mdi;
public:
    MdiMain(QMdiArea *parent = nullptr)
    {
        mdi -> setViewMode(QMdiArea::TabbedView);
        mdi -> setActivationOrder(QMdiArea::StackingOrder);
        mdi -> setTabsClosable(true);
        mdi -> setTabsMovable(true);
        mdi -> addSubWindow(new QTextEdit());
    }
    //    explicit MdiMain(QMdiArea* m) : mdi(m)
//    {
//        mdi -> setViewMode(QMdiArea::TabbedView);
//        mdi -> setActivationOrder(QMdiArea::StackingOrder);
//        mdi -> setTabsClosable(true);
//        mdi -> setTabsMovable(true);
//        mdi -> addSubWindow(new QTextEdit());
//    }
public slots:
    void slotOpenNewDoc(MdiMain *mdi);
signals:

};

#endif // MDIMAIN_H
