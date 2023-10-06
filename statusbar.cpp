#include "qtextedit.h"
#include "qstatusbar.h"
#include "qlabel.h"
#include "statusbar.h"
#include "mdimain.h"
#include "qlocale.h"

StatusBar::StatusBar(MdiMain* mdi): mdiMain(mdi)
{
    this->init();
}

void StatusBar::check()
{
    QString selectedText = txt->textCursor().selectedText();

    QFont font(symbolsAndLinesLabel->font());
    font.setBold(true);
    QString string = "";
    QString string2 = "";
    if (!selectedText.isEmpty())
    {
        QTextEdit tempTxt(selectedText);
        string = " | " +QString::number(selectedText.length());
        string2 = " | " + QString::number(tempTxt.document()->blockCount());
    }
    symbolsAndLinesLabel->setText("Символов: " + QString::number(txt->toPlainText().length()) + string
                                + "  Строк: " + QString::number(txt->document()->blockCount()) + string2 + "  ");

    cursorPosLabel->setText("Курсор: " + QString::number(txt->textCursor().position() + 1) +
                        + "  Строка: " + QString::number(txt->textCursor().blockNumber() + 1)
                        + "  Столбец: " + QString::number(txt->textCursor().positionInBlock() + 1) + "  ");

                                langInfoLabel->setText(QLocale::system().name());

    this->addLabels();
}

void StatusBar::init()
{
    symbolsAndLinesLabel = new QLabel(mdiMain);
    cursorPosLabel = new QLabel(mdiMain);
    langInfoLabel = new QLabel(mdiMain);
    connect(mdiMain, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(changeTxt()));
    connect(mdiMain, &MdiMain::destroyed, this, &StatusBar::deleteLater);
}

void StatusBar::addLabels()
{
    if (isActive)
    {
        return;
    }
    this->addWidget(symbolsAndLinesLabel, 2);
    this->addWidget(cursorPosLabel, 6);
    this->addWidget(langInfoLabel, 1);
    this->showLabels();
    this->isActive = true;
}

void StatusBar::removeLabels()
{
    this->removeWidget(symbolsAndLinesLabel);
    this->removeWidget(cursorPosLabel);
    this->removeWidget(langInfoLabel);
    this->isActive = false;
}

void StatusBar::showLabels()
{
    symbolsAndLinesLabel->show();
    cursorPosLabel->show();
    langInfoLabel->show();
}

void StatusBar::changeTxt()
{
    if (!mdiMain->subWindowList().isEmpty())
    {
        txt = mdiMain->getActiveDocument();
        if (txt != nullptr)
        {
            connect(txt, SIGNAL(textChanged()), this, SLOT(check()));
            connect(txt, SIGNAL(cursorPositionChanged()), this, SLOT(check()));
            this->check();
            return ;
        }
    }
    this->removeLabels();
}
