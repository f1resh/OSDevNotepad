#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextEdit>
#include <QMdiArea>
#include <QGridLayout>
#include <QObject>
#include <QWindow>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    //QMdiArea m = new QMdiArea(this);
    mdi = new MdiMain();
    MainWindow::setCentralWidget(mdi);

//    mdi -> addSubWindow(new QTextEdit(this));
//    mdi -> currentSubWindow()->setWindowTitle("Новый 1");

    testButton = new QPushButton(this);
    testButton -> setText("New");
    testButton -> show();
    testButton -> raise();
    QObject::connect(testButton, SIGNAL(clicked()), mdi,SLOT(&MdiMain::slotOpenNewDoc(&mdi)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

