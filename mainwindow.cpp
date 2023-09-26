#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "mdimain.h"
#include "saveload.h"
#include "copypastecut.h"

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



    connect(ui->actionNew,SIGNAL(triggered()),mdi,SLOT(slotOpenNewDoc()));
    connect(ui->actionLoad,SIGNAL(triggered()),saveload,SLOT(LoadTabFromFile()));
    connect(ui->actionSave,SIGNAL(triggered()),saveload,SLOT(SaveActiveTabToFile()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete mdi;
}

