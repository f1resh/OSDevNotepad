#include "searchcontroller.h"
#include "search.h"

SearchController::SearchController(QMdiArea *mdi, QObject* parent) : QObject(parent), mdiMain(mdi)
{

}

void SearchController::createSearch()
{
    if (mdiMain->subWindowList().isEmpty())
    {
        return;
    }
    Search *search = new Search(mdiMain);
    this->invertSearchIsOpen();
    connect(this, &SearchController::destroyed, search, &Search::deleteLater);
    connect(search, &Search::destroyed, this, &SearchController::invertSearchIsOpen);
    connect(this, &SearchController::openTab, search, &Search::showTab);
}

void SearchController::openFindTab()
{
    if (!searchIsOpen)
    {
        this->createSearch();
    }
    emit openTab((int)Tab::Find);
}

void SearchController::openReplaceTab()
{
    if (!searchIsOpen)
    {
        this->createSearch();
    }
    emit openTab((int)Tab::Replace);
}

void SearchController::invertSearchIsOpen()
{
    searchIsOpen = !searchIsOpen;
}
