#include "copypastecut.h"

void CopyPasteCut::slotCopyToClipboard()
{
    QTextEdit* activeTextEdit = mdi->getActiveDocument();
    if (activeTextEdit){
        QClipboard *clipboard;
        clipboard = QApplication::clipboard();
        QString selectedText = activeTextEdit->textCursor().selectedText();
        if (!selectedText.isEmpty())
        {
            clipboard->setText(selectedText);
        }
    }
}

void CopyPasteCut::slotPasteFromClipboard()
{
    QTextEdit* activeTextEdit = mdi->getActiveDocument();
    if (activeTextEdit){
        QClipboard *clipboard;
        clipboard = QApplication::clipboard();
        QString clipboardText = clipboard->text();
        if (!clipboardText.isEmpty())
        {
            activeTextEdit->insertPlainText(clipboardText);
        }
    }
}

void CopyPasteCut::slotCutText()
{
    QTextEdit* activeTextEdit = mdi->getActiveDocument();
    if (activeTextEdit){
        QClipboard *clipboard;
        clipboard = QApplication::clipboard();
        QString selectedText = activeTextEdit->textCursor().selectedText();
        if (!selectedText.isEmpty())
        {
            clipboard->setText(selectedText);
            activeTextEdit->textCursor().removeSelectedText();
        }
    }
}

void CopyPasteCut::slotSelectAll()
{
    QTextEdit* activeTextEdit = mdi->getActiveDocument();
    if (activeTextEdit){
        activeTextEdit->selectAll();
    }
}

void CopyPasteCut::slotDeleteText()
{
    QTextEdit* activeTextEdit = mdi->getActiveDocument();
    if (activeTextEdit){
        QTextCursor cursor = activeTextEdit->textCursor();
        if (cursor.hasSelection())
        {
            cursor.removeSelectedText();
        }
        else
        {
            cursor.deleteChar();
        }
    }
}
