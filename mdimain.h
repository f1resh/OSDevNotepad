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

    QTextEdit* getActiveDocument();

public slots:
    void slotOpenNewDoc();
    void slotPrint();

signals:

private:
    void nameDoc();
};

#endif // MDIMAIN_H
