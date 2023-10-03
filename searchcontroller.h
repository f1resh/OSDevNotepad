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
    void createSearch();

signals:
    void openTab(int);

public slots:
    void openFindTab();
    void openReplaceTab();

public slots:
    void invertSearchIsOpen();
};
