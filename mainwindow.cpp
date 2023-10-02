#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "mdimain.h"
#include "saveload.h"
#include "copypastecut.h"
#include "searchcontroller.h"

#define RELEASE(p) if (p) {delete p; p = NULL;}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create an object of mdiMain class
    mdi = new MdiMain(this);
    MainWindow::setCentralWidget(mdi);

    //ToDo: setup the default directory and filemask
    saveload = new SaveLoad(mdi);
    copypastecut = new CopyPasteCut(mdi);
    searchcontroller = new SearchController(mdi, mdi);

    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionNew,SIGNAL(triggered()),mdi,SLOT(slotOpenNewDoc()));
    connect(ui->actionLoad,SIGNAL(triggered()),saveload,SLOT(LoadTabFromFile()));
    connect(ui->actionSave,SIGNAL(triggered()),saveload,SLOT(SaveActiveTabToFile()));
    connect(ui->actionSearch,SIGNAL(triggered()),searchcontroller,SLOT(openFindTab()));
    connect(ui->actionReplace,SIGNAL(triggered()),searchcontroller,SLOT(openReplaceTab()));
}

MainWindow::~MainWindow()
{
    RELEASE(saveload);
    RELEASE(copypastecut);
    RELEASE(searchcontroller);
    RELEASE(ui);
    RELEASE(mdi);
}

