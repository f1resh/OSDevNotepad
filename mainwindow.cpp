#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
    createMenu();
    setWindowTitle("Clipboard");
}

void MainWindow::copyToClipboard()
{
    clipboard = QApplication::clipboard();
    QString selectedText = textEdit->textCursor().selectedText();
    if (selectedText.isEmpty())
    {
        QMessageBox::warning(this, "Clipboard", "No text selected!");
        return;
    }
    clipboard->setText(selectedText);
}

void MainWindow::pasteFromClipboard()
{
    clipboard = QApplication::clipboard();
    QString clipboardText = clipboard->text();
    if (clipboardText.isEmpty())
    {
        QMessageBox::warning(this, "Clipboard", "The buffer is empty!");
        return;
    }
    textEdit->insertPlainText(clipboardText);
}

void MainWindow::cutText()
{
    textEdit->cut();
}

void MainWindow::createMenu()
{
    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
    copyAction = new QAction(tr("Copy"), this);
    copyAction->setShortcuts(QKeySequence::Copy);
    connect(copyAction, &QAction::triggered, this, &MainWindow::copyToClipboard);
    editMenu->addAction(copyAction);
    pasteAction = new QAction(tr("Paste"), this);
    pasteAction->setShortcuts(QKeySequence::Paste);
    connect(pasteAction, &QAction::triggered, this, &MainWindow::pasteFromClipboard);
    editMenu->addAction(pasteAction);
    cutAction = new QAction(tr("cut text"), this);
    cutAction->setShortcuts(QKeySequence::Cut);
    connect(cutAction, &QAction::triggered, this, &MainWindow::cutText);
    editMenu->addAction(cutAction);
}
