#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qmdisubwindow.h"
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
    QTextEdit* plainTextEdit = new QTextEdit(this);
    MainWindow::setCentralWidget(plainTextEdit);

    mdi = new mdiMain();
    mdi -> setViewMode(QMdiArea::TabbedView);
    mdi -> setActivationOrder(QMdiArea::StackingOrder);
    mdi -> setTabsClosable(true);
    mdi -> setTabsMovable(true);
    MainWindow::setCentralWidget(mdi);
    mdi -> addSubWindow(new QTextEdit(this));
    mdi -> currentSubWindow()->setWindowTitle("Новый 1");


    testButton = new QPushButton(this);
    testButton -> setText("New");
    testButton -> show();
    testButton -> raise();
    QObject::connect(testButton, SIGNAL(clicked()), mdi,SLOT(&mdiMain::slotOpenNewDoc()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

