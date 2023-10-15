#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mdimain.h"
#include "qobjectdefs.h"
#include "saveload.h"
#include "copypastecut.h"
#include "dialoggotostring.h"
#include "searchcontroller.h"
#include "statusbar.h"
#include <QMessageBox>

#define RELEASE(p) if (p) {delete p; p = NULL;}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mdi = new MdiMain(this);
    //ToDo: setup the default directory and filemask
    saveload = new SaveLoad(mdi);
    copypastecut = new CopyPasteCut(mdi);
    searchcontroller = new SearchController(mdi, mdi);

    setCentralWidget(mdi);
    setStatusBar(new StatusBar(mdi));
    initSignals();

}

MainWindow::~MainWindow()
{
    RELEASE(saveload);
    RELEASE(copypastecut);
    RELEASE(searchcontroller);
    RELEASE(ui);
    RELEASE(mdi);
}

void MainWindow::initSignals()
{
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionNew,SIGNAL(triggered()),mdi,SLOT(slotOpenNewDoc()));
    connect(ui->actionLoad,SIGNAL(triggered()),saveload,SLOT(LoadTabFromFile()));
    connect(ui->actionSave,SIGNAL(triggered()),saveload,SLOT(SaveActiveTabToFile()));
    connect(ui->actionUndo,SIGNAL(triggered()),mdi,SLOT(slotUndo()));
    connect(ui->actionRedo,SIGNAL(triggered()),mdi,SLOT(slotRedo()));
    connect(ui->actionClose,SIGNAL(triggered()),mdi,SLOT(slotClose()));
    connect(ui->actionCopy,SIGNAL(triggered()),copypastecut,SLOT(slotCopyToClipboard()));
    connect(ui->actionCut,SIGNAL(triggered()),copypastecut,SLOT(slotCutText()));
    connect(ui->actionSelectAll,SIGNAL(triggered()),copypastecut,SLOT(slotSelectAll()));
    connect(ui->actionDelete,SIGNAL(triggered()),copypastecut,SLOT(slotDeleteText()));
    connect(ui->actionPaste,SIGNAL(triggered()),copypastecut,SLOT(slotPasteFromClipboard()));
    connect(ui->actionGoto, SIGNAL(triggered()),searchcontroller,SLOT(openGoToDialog()));
    connect(ui->actionSearch,SIGNAL(triggered()),searchcontroller,SLOT(openFindTab()));
    connect(ui->actionReplace,SIGNAL(triggered()),searchcontroller,SLOT(openReplaceTab()));
    connect(ui->actionPrint,SIGNAL(triggered()),mdi,SLOT(slotPrint()));
    connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(slotShowAbout()));
}

void MainWindow::slotShowAbout()
{
    QMessageBox::about(this,"About OSDevNotepad","OSDevNotepad v."+version+" by Boring Programmers");
}

