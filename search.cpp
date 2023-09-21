#include "search.h"

Search::Search(QMdiArea *mdi, QWidget *parent): QWidget(parent), mdiMain(mdi)
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
    findDialog->setWindowTitle("Find and Replace");

    tabWidget = new QTabWidget(findDialog);
    connect(tabWidget, &QTabWidget::tabBarClicked, this, &Search::initLayout);

    findLabel = new QLabel("Find", tabWidget);
    replaceLabel = new QLabel("Replace with", tabWidget);

    QWidget* findTab = new QWidget(tabWidget);
    QWidget* replaceTab = new QWidget(tabWidget);

    findLineEdit = new QLineEdit(tabWidget);

    QTextCursor currentCursor = currentTextEdit->textCursor();
    QString selectedText = currentCursor.selectedText();
    if (!selectedText.isEmpty())
    {
        findLineEdit->setText(selectedText);
    }

    replaceLineEdit = new QLineEdit(tabWidget);

    findNextButton = new QPushButton("Find next",tabWidget);
    connect(findNextButton, &QPushButton::clicked, this, &Search::findText);
    findNextButton->setDefault(true);

    findPrevButton = new QPushButton("Find prev",tabWidget);
    connect(findPrevButton, &QPushButton::clicked, this, &Search::findText);

    replacePrevButton = new QPushButton("Replace and " + findPrevButton->text(),this);
    connect(replacePrevButton, &QPushButton::clicked, this, &Search::replaceSelectedText);

    replaceNextButton = new QPushButton("Replace and " + findNextButton->text(),this);
    connect(replaceNextButton, &QPushButton::clicked, this, &Search::replaceSelectedText);

    replaceAllButton = new QPushButton("Replace All",this);
    connect(replaceAllButton, &QPushButton::clicked, this, &Search::replaceAllText);

    resultLabel = new QLabel(tabWidget);

    QGridLayout* layout = new QGridLayout(findDialog);

    tabWidget->addTab(findTab, "Find");
    tabWidget->addTab(replaceTab, "Replace");

    int tabCount = tabWidget->count();
    while (tabCount)
    {
        this->initLayout(--tabCount);
    }

    layout->addWidget(tabWidget);
    findDialog->setLayout(layout);
    findDialog->show();

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
                resultString = "Not found. ";
            }
            cursor = currentTextEdit->textCursor();
            if (isFindNext)
            {
                if (replaceCounter)
                {
                    resultLabel->setText("Replaced " + QString::number(replaceCounter)+ " results. End of document reached.");
                    replaceCounter = 0;
                }
                else
                {
                    resultLabel->setText(resultString + "End of document reached.");
                }
                cursor.movePosition(QTextCursor::End);
            }
            else
            {
                resultLabel->setText(resultString + "Start of document reached.");
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

void Search::clearTabLayout(QGridLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr)
    {
        layout->removeWidget(item->widget());
        layout->removeItem(item);
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
