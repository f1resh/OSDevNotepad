#ifndef MDIMAIN_H
#define MDIMAIN_H

#include <QWidget>
#include <QMdiArea>
#include <QTextEdit>
#include <QMdiSubWindow>


class MdiMain : public QMdiArea
{
    Q_OBJECT

public:
    MdiMain(QWidget *parent = nullptr);

public slots:
    void slotOpenNewDoc();

signals:

private:
    void nameDoc();
};

#endif // MDIMAIN_H
