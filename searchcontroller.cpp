#include "searchcontroller.h"
#include "search.h"
#include "dialoggotostring.h"

SearchController::SearchController(QMdiArea *mdi, QObject* parent) : QObject(parent), mdiMain(mdi)
{
    connect(mdiMain, &QMdiArea::subWindowActivated, this, &SearchController::closeDialogWindow);
}

void SearchController::createSearch()
{
    if (mdiMain->subWindowList().isEmpty())
    {
        return;
    }
    Search *search = new Search(mdiMain, mdiMain);
    this->invertSearchIsOpen();
    connect(this, &SearchController::destroyed, search, &Search::deleteLater);
    connect(search, &Search::destroyed, this, &SearchController::invertSearchIsOpen);
    connect(this, &SearchController::openSearchTab, search, &Search::showTab);
    connect(this, &SearchController::closeDialog, search, &Search::exit);
}

void SearchController::createGoTo()
{
    if (mdiMain->subWindowList().isEmpty())
    {
        return;
    }
    DialogGoToString *gotostring = new DialogGoToString(mdiMain, mdiMain);
    this->invertGoToIsOpen();
    connect(this, &SearchController::destroyed, gotostring, &Search::deleteLater);
    connect(gotostring, &DialogGoToString::destroyed, this, &SearchController::invertGoToIsOpen);
    connect(this, &SearchController::openGoTo, gotostring, &DialogGoToString::activateWindow);
    connect(this, &SearchController::closeDialog, gotostring, &DialogGoToString::close);
}

void SearchController::openFindTab()
{
    if (!searchIsOpen)
    {
        this->createSearch();
    }
    emit openSearchTab((int)Tab::Find);
}

void SearchController::openReplaceTab()
{
    if (!searchIsOpen)
    {
        this->createSearch();
    }
    emit openSearchTab((int)Tab::Replace);
}

void SearchController::openGoToDialog()
{
    if (!gotoIsOpen)
    {
        this->createGoTo();
        return;
    }
    emit openGoTo();
}

void SearchController::invertSearchIsOpen()
{
    searchIsOpen = !searchIsOpen;
}

void SearchController::invertGoToIsOpen()
{
    gotoIsOpen = !gotoIsOpen;
}

void SearchController::closeDialogWindow()
{
    if (mdiMain->subWindowList().isEmpty())
    {
        emit closeDialog();
    }
}
