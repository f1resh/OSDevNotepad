#include "dialoggotostring.h"

dialogGoToString::dialogGoToString(QWidget *parent)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    m_lineNumber = new QSpinBox;

    strNumber = new QLabel("String number:");
    strNumber->setBuddy(m_lineNumber);

    goTo   = new QPushButton("&Go");
    cancel = new QPushButton("&Cancel");

    connect(goTo, SIGNAL(clicked()), SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), SLOT(reject()));

    //Layout setup
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(strNumber, 4, 0);
    ptopLayout->addWidget(m_lineNumber, 4, 1);
    ptopLayout->addWidget(goTo, 10, 0);
    ptopLayout->addWidget(cancel, 10, 1);
    setLayout(ptopLayout);
}

dialogGoToString::~dialogGoToString() {}

int dialogGoToString::lineNumber() const
{
    return m_lineNumber->value();
}
