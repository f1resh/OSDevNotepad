#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "mdimain.h"
#include "saveload.h"
#include "copypastecut.h"
#include "dialoggotostring.h"
#include "searchcontroller.h"

#define RELEASE(p) if (p) {delete p; p = NULL;}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    connect(ui->actionUndo,SIGNAL(triggered()),mdi,SLOT(slotUndo()));
    connect(ui->actionRedo,SIGNAL(triggered()),mdi,SLOT(slotRedo()));
    connect(ui->actionClose,SIGNAL(triggered()),mdi,SLOT(slotClose()));
    connect(ui->actionGoto, SIGNAL(triggered()),searchcontroller,SLOT(openGoToDialog()));
    connect(ui->actionSearch,SIGNAL(triggered()),searchcontroller,SLOT(openFindTab()));
    connect(ui->actionReplace,SIGNAL(triggered()),searchcontroller,SLOT(openReplaceTab()));
    connect(ui->actionPrint,SIGNAL(triggered()),mdi,SLOT(slotPrint()));
}

MainWindow::~MainWindow()
{
    RELEASE(saveload);
    RELEASE(copypastecut);
    RELEASE(searchcontroller);
    RELEASE(ui);
    RELEASE(mdi);
}

