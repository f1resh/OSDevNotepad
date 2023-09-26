#ifndef DIALOGGOTOSTRING_H
#define DIALOGGOTOSTRING_H

#include <QDialog>
#include <QWidget>


    class QPushButton;
    class QGridLayout;
    class QSpinBox;
    class QLabel;
    class QMdiArea;


class DialogGoToString : public QDialog
{
public:
    DialogGoToString(QMdiArea* mainArea, QWidget *parent = nullptr);
    ~DialogGoToString();
    int lineNumber() const;

private:
    QPushButton* goTo;
    QPushButton* cancel;
    QSpinBox* m_lineNumber;
    QLabel* strNumber;
};

#endif // DIALOGGOTOSTRING_H
