#ifndef MDIMAIN_H
#define MDIMAIN_H

#include <QWidget>
#include <QMdiArea>
#include <QPushButton>


class mdiMain : public QMdiArea
{
    Q_OBJECT
public:
    mdiMain(QMdiArea *parent = nullptr);
private:
    //mdiMain *mdi;

public slots:
    void slotOpenNewDoc();
signals:
    void signalOpenNewDoc();
};

#endif // MDIMAIN_H
