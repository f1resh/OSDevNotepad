#include "search.h"
#include <QDebug>

Search::Search(QMdiArea *mdi, QWidget *parent): QWidget(parent), mdiMain(mdi)
{
    this->init();
}

void Search::findText()
{

    bool isFindNext = QObject::sender() == findNextButton;

    QTextEdit *currentTextEdit = this->getCurrentTextEdit();
    if (currentTextEdit == nullptr)
    {
        return;
    }

    if (currentTextEdit->document()->isEmpty())
    {
        return;
    }

    QString searchText = findLineEdit->text();
    if (searchText.isEmpty())
    {
        return;
    }
    resultLabel->clear();

    QTextCursor cursor = currentTextEdit->textCursor();

    QString resultString;

    if (isFindNext && cursor.atEnd())
    {
        cursor.movePosition(QTextCursor::Start);
    }
    if (!isFindNext && cursor.atStart()) {
        cursor.movePosition(QTextCursor::End);
    }

    while (!(isFindNext ? cursor.atEnd() : cursor.atStart()))
    {
        cursor = isFindNext ? currentTextEdit->document()->find(searchText, cursor) : currentTextEdit->document()->find(searchText, cursor, QTextDocument::FindBackward);
        if (!cursor.isNull())
        {
            currentTextEdit->setTextCursor(cursor);
            findStatus = true;
            break;
        }
        else {
            if (findStatus)
            {
                findStatus = false;
            }
            else
            {
                resultString = "Нет результатов. ";
            }
            cursor = currentTextEdit->textCursor();
            if (isFindNext)
            {
                if (replaceCounter)
                {
                    resultString = "Произведено замен: " + QString::number(replaceCounter)+ ". ";
                    replaceCounter = 0;
                }
                resultLabel->setText(resultString + "Достигнут конец документа.");
                cursor.movePosition(QTextCursor::End);
            }
            else
            {
                resultLabel->setText(resultString + "Достигнуто начало документа.");
                cursor.movePosition(QTextCursor::Start);
            }
            currentTextEdit->setTextCursor(cursor);
            break;
        }
    }
}

void Search::replaceAllText()
{
    QTextEdit *currentTextEdit = this->getCurrentTextEdit();
    if (currentTextEdit == nullptr)
    {
        return;
    }

    if (currentTextEdit->document()->isEmpty())
    {
        return;
    }

    QString searchText = findLineEdit->text();
    QString replaceText = replaceLineEdit->text();

    if (replaceText.isEmpty())
    {
        return;
    }

    QTextCursor cursor = currentTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Start);
    currentTextEdit->setTextCursor(cursor);
    if (cursor.selectedText() != searchText)
    {
        findNextButton->click();
    }

    if (!findStatus)
    {
        return;
    }

    while (findStatus)
    {
        replaceCounter++;
        replaceNextButton->click();
    }

}

void Search::replaceSelectedText()
{

    bool isReplaceNext = QObject::sender() == replaceNextButton;

    QTextEdit *currentTextEdit = this->getCurrentTextEdit();
    if (currentTextEdit == nullptr)
    {
        return;
    }

    if (currentTextEdit->document()->isEmpty())
    {
        return;
    }

    QString searchText = findLineEdit->text();
    QString replaceText = replaceLineEdit->text();

    if (replaceText.isEmpty())
    {
        return;
    }

    QTextCursor cursor = currentTextEdit->textCursor();
    if (cursor.selectedText() != searchText)
    {
        return;
    }

    cursor.insertText(replaceText);
    isReplaceNext ? findNextButton->click() : findPrevButton->click();

}

void Search::initLayout(int index)
{
    QGridLayout* layout = qobject_cast<QGridLayout*>(tabWidget->widget(index)->layout());
    if (!layout)
    {
        layout = new QGridLayout(tabWidget);
        tabWidget->widget(index)->setLayout(layout);
    }
    else
    {
        this->clearTabLayout(layout);
    }

    if (index)
    {
        layout->addWidget(findLabel, 0, 0, 1, 1, Qt::AlignRight);
        layout->addWidget(findLineEdit, 0, 1, 1 , 3);
        layout->addWidget(findPrevButton, 0, 4, 1, 1);
        layout->addWidget(findNextButton, 0, 5, 1, 1);
        layout->addWidget(replaceLabel, 1, 0, 1, 1, Qt::AlignRight);
        layout->addWidget(replaceLineEdit, 1, 1, 1, 3);
        layout->addWidget(replacePrevButton, 1, 4, 1, 1);
        layout->addWidget(replaceNextButton, 1, 5, 1, 1);
        layout->addWidget(replaceAllButton, 2, 4, 1, 2);
        layout->addWidget(resultLabel, 3, 0, 1, 6);
        replaceLineEdit->setFocus();
    }
    else
    {
        layout->addWidget(findLabel, 0, 0, 1, 1, Qt::AlignRight);
        layout->addWidget(findLineEdit, 0, 1, 1 , 4);
        layout->addWidget(findPrevButton, 1, 3, 1, 1);
        layout->addWidget(findNextButton, 1, 4, 1, 1);
        layout->addWidget(resultLabel, 2, 0, 1, 5);
        findLineEdit->setFocus();
    }
}

void Search::showTab(int index)
{
    if (index >= tabWidget->count())
    {
        return;
    }
    this->findLineEditInit();
    findDialog->activateWindow();
    if (index != tabWidget->currentIndex())
    {
        this->initLayout(index);
        tabWidget->setCurrentIndex(index);
    }

    findDialog->show();
}

void Search::clearTabLayout(QGridLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr)
    {
        layout->removeWidget(item->widget());
        layout->removeItem(item);
    }
}

void Search::init()
{
    if (mdiMain == nullptr)
    {
        return;
    }

    QTextEdit *currentTextEdit = this->getCurrentTextEdit();
    if (currentTextEdit == nullptr)
    {
        return;
    }

    findDialog = new QDialog(this);
    findDialog->setWindowTitle("Поикс и замена");
    findDialog->setWindowFlags(findDialog->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);//bugfix

    connect(findDialog, &QDialog::finished, this, &Search::deleteLater);

    tabWidget = new QTabWidget(findDialog);
    connect(tabWidget, &QTabWidget::tabBarClicked, this, &Search::initLayout);

    findLabel = new QLabel("Найти", tabWidget);
    replaceLabel = new QLabel("Заменить на", tabWidget);

    QWidget* findTab = new QWidget(tabWidget);
    QWidget* replaceTab = new QWidget(tabWidget);

    findLineEdit = new QLineEdit(tabWidget);

    replaceLineEdit = new QLineEdit(tabWidget);

    findNextButton = new QPushButton("Искать далее",tabWidget);
    connect(findNextButton, &QPushButton::clicked, this, &Search::findText);
    findNextButton->setDefault(true);

    findPrevButton = new QPushButton("Искать назад",tabWidget);
    connect(findPrevButton, &QPushButton::clicked, this, &Search::findText);

    replacePrevButton = new QPushButton("Заменить и " + findPrevButton->text(),this);
    connect(replacePrevButton, &QPushButton::clicked, this, &Search::replaceSelectedText);

    replaceNextButton = new QPushButton("Заменить и " + findNextButton->text(),this);
    connect(replaceNextButton, &QPushButton::clicked, this, &Search::replaceSelectedText);

    replaceAllButton = new QPushButton("Заменить все",this);
    connect(replaceAllButton, &QPushButton::clicked, this, &Search::replaceAllText);

    resultLabel = new QLabel(tabWidget);

    QGridLayout* layout = new QGridLayout(findDialog);

    tabWidget->addTab(findTab, "Поиск");
    tabWidget->addTab(replaceTab, "Замена");


    layout->addWidget(tabWidget);
    findDialog->setLayout(layout);

    int tabCount = tabWidget->count();
    while (tabCount)
    {
        this->showTab(--tabCount);
    }

}

void Search::findLineEditInit()
{
    QTextEdit *currentTextEdit = this->getCurrentTextEdit();
    if (currentTextEdit == nullptr)
    {
        return;
    }
    QTextCursor currentCursor = currentTextEdit->textCursor();
    QString selectedText = currentCursor.selectedText();
    if (!selectedText.isEmpty())
    {
        findLineEdit->setText(selectedText);
    }
}



QTextEdit *Search::getCurrentTextEdit()
{
    if (!mdiMain->subWindowList().isEmpty())
    {
        QWidget* currentWidget = mdiMain->currentSubWindow()->widget();
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
