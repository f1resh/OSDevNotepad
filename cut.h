#pragma once
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QTextEdit.h>
#include <QDebug>

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
        activeTextEdit->cut();
    }
};