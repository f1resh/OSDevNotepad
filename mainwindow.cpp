#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mdimain.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mdi = new MdiMain(this);
    MainWindow::setCentralWidget(mdi);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mdi;
}

