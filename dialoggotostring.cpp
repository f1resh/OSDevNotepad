#include "dialoggotostring.h"
#include <QPushButton>
#include <QGridLayout>
#include <QSpinBox>
#include <QLabel>
#include <QMdiArea>


DialogGoToString::DialogGoToString(QMdiArea* mainArea, QWidget *parent)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    m_lineNumber = new QSpinBox;
    m_lineNumber->setMinimum(1);

    strNumber = new QLabel(this);
    strNumber->setBuddy(m_lineNumber);

    goTo   = new QPushButton(this);
    cancel = new QPushButton(this);

    connect(goTo, SIGNAL(clicked()), SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), SLOT(reject()));


    goTo->setText(tr("Перейти"));
    cancel->setText(tr("Отмена"));
    strNumber->setText(tr("№ строки:"));


    //Layout setup
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(strNumber, 4, 0);
    ptopLayout->addWidget(m_lineNumber, 4, 1);
    ptopLayout->addWidget(goTo, 10, 0);
    ptopLayout->addWidget(cancel, 10, 1);
    setLayout(ptopLayout);


}

DialogGoToString::~DialogGoToString() {}

int DialogGoToString::lineNumber() const
{
    return m_lineNumber->value();
}
