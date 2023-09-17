#ifndef DIALOGGOTOSTRING_H
#define DIALOGGOTOSTRING_H

//#include <QObject>
#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QSpinBox>
#include <QLabel>

class dialogGoToString : public QDialog
{
public:
    dialogGoToString(QWidget *parent = nullptr);
    ~dialogGoToString();
    int lineNumber() const;

private:
    QPushButton* goTo;
    QPushButton* cancel;
    QSpinBox* m_lineNumber;
    QLabel* strNumber;
};

#endif // DIALOGGOTOSTRING_H
