#ifndef MULTYDOC_H
#define MULTYDOC_H

#include <QWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QGridLayout>

class multyDoc : public QMdiArea
{
    Q_OBJECT
private:
    QMdiArea* mdiArea;
    QWidget* centralWidget;
    QGridLayout* gridLayout;


public slots:
    void openNewDoc();

public:
    explicit multyDoc(QMdiArea *parent = nullptr);
    ~multyDoc()
    {
        delete mdiArea;
    };
signals:

private:

};

#endif // MULTYDOC_H
