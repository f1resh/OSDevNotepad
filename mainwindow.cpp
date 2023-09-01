#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPlainTextEdit* plainTextEdit = new QPlainTextEdit(this);
    MainWindow::setCentralWidget(plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

