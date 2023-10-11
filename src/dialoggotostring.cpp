#include "dialoggotostring.h"
#include <QPushButton>
#include <QGridLayout>
#include <QSpinBox>
#include <QLabel>
#include <QMdiArea>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QMdiSubWindow>


DialogGoToString::DialogGoToString(QMdiArea* area, QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint), mainArea(area)
{
    this->init();
}

DialogGoToString::~DialogGoToString() {}

void DialogGoToString::init() {

    if (mainArea == nullptr) {
        return;
    }

    QTextEdit *currentTextEdit = this->getCurrentTextEdit(mainArea);
    if (currentTextEdit == nullptr) {
        return;
    }

    connect(this, &DialogGoToString::finished, this, &DialogGoToString::deleteLater);
    connect(mainArea, &QMdiArea::subWindowActivated, this, &DialogGoToString::updateLinesCount);
    connect(currentTextEdit, &QTextEdit::cursorPositionChanged, this, &DialogGoToString::updateLinesCount);
    int strCount = getStringsNumbers(currentTextEdit);

    m_lineNumber = new QSpinBox;
    m_lineNumber->setMinimum(1);
    m_lineNumber->setMaximum(strCount);

    strNumber = new QLabel(this);
    strNumber->setBuddy(m_lineNumber);

    goTo   = new QPushButton(this);
    cancel = new QPushButton(this);

    connect(goTo, &QPushButton::clicked, this, &DialogGoToString::moveCursorToString);
    connect(cancel, SIGNAL(clicked()), SLOT(reject()));

    goTo->setText(tr("Перейти"));
    cancel->setText(tr("Отмена"));
    strNumber->setText(tr("№ строки:"));

    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(strNumber, 4, 0);
    ptopLayout->addWidget(m_lineNumber, 4, 1);
    ptopLayout->addWidget(goTo, 10, 0);
    ptopLayout->addWidget(cancel, 10, 1);
    setLayout(ptopLayout);

    this->show();
}

int DialogGoToString::lineNumber() const
{
    return m_lineNumber->value();
}

QTextEdit *DialogGoToString::getCurrentTextEdit(QMdiArea* mArea) {

    if (!mArea->subWindowList().isEmpty())
    {
        QWidget* currentWidget = mArea->currentSubWindow()->widget();
        if (currentWidget != nullptr)
        {
            QTextEdit *textEdit = qobject_cast<QTextEdit*>(currentWidget);
            if (textEdit != nullptr)
            {
                return textEdit;
            }
        }
    }
    return nullptr;
}

int DialogGoToString::getStringsNumbers(QTextEdit* currentTextEdit) {

    if (mainArea == nullptr) {
        return 0;
    }

    if (currentTextEdit == nullptr) {
        return 0;
    }

    return currentTextEdit->document()->blockCount();
}

void DialogGoToString::moveCursorToString() {

    QTextEdit *currentTextEdit = this->getCurrentTextEdit(mainArea);

    QTextCursor cursor = currentTextEdit->textCursor();
    int stringNumber = lineNumber();

    cursor.movePosition(QTextCursor::Start);

    if (stringNumber == 1) {
        currentTextEdit->setTextCursor(cursor);
    } else if (stringNumber > getStringsNumbers(currentTextEdit)) {
        cursor.movePosition(QTextCursor::End);
        currentTextEdit->setTextCursor(cursor);
    } else {
        int i = 0;
        while (i != stringNumber - 1) {
            cursor.movePosition(QTextCursor::Down);
            i = cursor.blockNumber();
        }        
        currentTextEdit->setTextCursor(cursor);
    }
    currentTextEdit->activateWindow();

}

void DialogGoToString::updateLinesCount()
{
    QTextEdit *currentTextEdit = this->getCurrentTextEdit(mainArea);
    if (currentTextEdit == nullptr)
    {
        return;
    }
    if (sender() != currentTextEdit)
    {
        connect(currentTextEdit, &QTextEdit::cursorPositionChanged, this, &DialogGoToString::updateLinesCount);
    }
    int strCount = currentTextEdit->document()->blockCount();
    m_lineNumber->setMaximum(strCount);
}
