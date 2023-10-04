#pragma once

#include "qmdiarea.h"
#include "qobject.h"

enum class Tab
{
    Find,
    Replace
};

class SearchController: public QObject
{
    Q_OBJECT

public:
    SearchController(QMdiArea *mdi, QObject* parent = nullptr);

private:
    QMdiArea *mdiMain{nullptr};
    bool searchIsOpen{false};
    bool gotoIsOpen{false};
    void createSearch();
    void createGoTo();

signals:
    void openSearchTab(int);
    void openGoTo();
    void closeDialog();

public slots:
    void openFindTab();
    void openReplaceTab();
    void openGoToDialog();

private slots:
    void invertSearchIsOpen();
    void invertGoToIsOpen();
    void closeDialogWindow();
};
