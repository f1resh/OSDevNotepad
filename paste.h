#pragma once
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QTextEdit.h>
#include <QDebug>
#include <QtGui/QClipboard>
#include <QApplication>
#include <QMessageBox>

class paste : public QObject
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
    void pasteFromClipboard()
    {
        qDebug() << mdi->isActiveWindow();
        QMdiSubWindow* active = mdi->currentSubWindow();
        QWidget* wgt = active->widget();
        QTextEdit* activeTextEdit = qobject_cast<QTextEdit*>(wgt);
        lipboard = QApplication::clipboard();
    	QString clipboardText = clipboard->text();
    	if (clipboardText.isEmpty())
    	{
        	QMessageBox::warning(this, "Clipboard", "The buffer is empty!");
        	return;
    	}
    	activeTextEdit->insertPlainText(clipboardText);
    }
};