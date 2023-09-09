#include "copypastecut.h"

void CopyPasteCut::copyToClipboard()
{
    QWidget* wgt = mdi->currentSubWindow()->widget();
    if (wgt != nullptr)
    {
        QTextEdit* activeTextEdit = qobject_cast<QTextEdit*>(wgt);
        if (activeTextEdit != nullptr)
        {
            QClipboard *clipboard;
            clipboard = QApplication::clipboard();
            QString selectedText = activeTextEdit->textCursor().selectedText();
            if (!selectedText.isEmpty())
            {
                clipboard->setText(selectedText);
            }
        }
    }
}

void CopyPasteCut::pasteFromClipboard()
{
    QWidget* wgt = mdi->currentSubWindow()->widget();
    if (wgt != nullptr)
    {
        QTextEdit* activeTextEdit = qobject_cast<QTextEdit*>(wgt);
        if (activeTextEdit != nullptr)
        {
            QClipboard *clipboard;
            clipboard = QApplication::clipboard();
            QString clipboardText = clipboard->text();
            if (!clipboardText.isEmpty())
            {
                activeTextEdit->insertPlainText(clipboardText);
            }
        }
    }
}

void CopyPasteCut::cutText()
{
    QWidget* wgt = mdi->currentSubWindow()->widget();
    if (wgt != nullptr)
    {
        QTextEdit* activeTextEdit = qobject_cast<QTextEdit*>(wgt);
        if (activeTextEdit != nullptr)
        {
            QClipboard *clipboard;
            clipboard = QApplication::clipboard();
            QString selectedText = activeTextEdit->textCursor().selectedText();
            if (!selectedText.isEmpty())
            {
                clipboard->setText(selectedText);
                activeTextEdit->cut();
            }
        }
    }
}
