#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtGui/QClipboard>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>

class MainWindow : public QMainWindow {

    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);

private slots:

    void copyToClipboard();

    void pasteFromClipboard();

private:

    QTextEdit *textEdit;

    QAction *copyAction;

    QAction *pasteAction;

    QClipboard *clipboard;

    void createMenu();

};
#endif // MAINWINDOW_H
