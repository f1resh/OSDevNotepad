#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mdimain.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create an object of mdiMain class
    mdi = new MdiMain(this);

    //set object as a central widget
    MainWindow::setCentralWidget(mdi);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mdi;
}

