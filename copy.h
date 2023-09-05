#pragma once
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QTextEdit.h>
#include <QDebug>
#include <QtGui/QClipboard>
#include <QApplication>
#include <QMessageBox>

class copy : public QObject
{
	Q_OBJECT

private:
    QMdiArea* mdi;
    
public:
    Functions(QMdiArea* m)
	{
		mdi = m;
	};

public slots:
    void copyToClipboard()
    {
        qDebug() << mdi->isActiveWindow();
        QMdiSubWindow* active = mdi->currentSubWindow();
        QWidget* wgt = active->widget();
        QTextEdit* activeTextEdit = qobject_cast<QTextEdit*>(wgt);
        clipboard = QApplication::clipboard();
    	QString selectedText = activeTextEdit->textCursor().selectedText();
    	if (selectedText.isEmpty())
    	{
        	QMessageBox::warning(this, "Clipboard", "No text selected!");
        	return;
    	}
    	clipboard->setText(selectedText);
    }
};
