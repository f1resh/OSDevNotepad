#include "copypastecut.h"

void CopyPasteCut::copyToClipboard()
{
    qDebug() << mdi->isActiveWindow();
    QMdiSubWindow* active = mdi->currentSubWindow();
    QWidget* wgt = active->widget();
    QTextEdit* activeTextEdit = qobject_cast<QTextEdit*>(wgt);
    QClipboard *clipboard;
    clipboard = QApplication::clipboard();
    QString selectedText = activeTextEdit->textCursor().selectedText();
    if (selectedText.isEmpty())
    {
        QMessageBox::warning(0, "Clipboard", "No text selected!");
        return;
    }
    clipboard->setText(selectedText);
}

void CopyPasteCut::pasteFromClipboard()
{
    qDebug() << mdi->isActiveWindow();
    QMdiSubWindow* active = mdi->currentSubWindow();
    QWidget* wgt = active->widget();
    QTextEdit* activeTextEdit = qobject_cast<QTextEdit*>(wgt);
    QClipboard *clipboard;
    clipboard = QApplication::clipboard();
    QString clipboardText = clipboard->text();
    if (clipboardText.isEmpty())
    {
        QMessageBox::warning(0, "Clipboard", "The buffer is empty!");
        return;
    }
    activeTextEdit->insertPlainText(clipboardText);
}

void CopyPasteCut::cutText()
{
    qDebug() << mdi->isActiveWindow();
    QMdiSubWindow* active = mdi->currentSubWindow();
    QWidget* wgt = active->widget();
    QTextEdit* activeTextEdit = qobject_cast<QTextEdit*>(wgt);
    activeTextEdit->cut();
}
