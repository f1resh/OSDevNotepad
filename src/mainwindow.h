#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

extern QString version;

/**
 * @class Класс MainWindow
 * @brief Главное окно приложения.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief Конструктор класса MainWindow.
     * @param parent Указатель на родительский виджет.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса MainWindow.
     */
    ~MainWindow();

private:
    Ui::MainWindow *ui;                          /**< Указатель на объект пользовательского интерфейса.*/
    class MdiMain *mdi;                          /**< Указатель на объект многодокументного окна для управления документами.*/
    class SaveLoad *saveload;                    /**< Указатель на объект класса сохранения и загрузки документов.*/
    class CopyPasteCut* copypastecut;            /**< Указатель на объект класса операций копирования, вставки и вырезания текста.*/
    class SearchController* searchcontroller;    /**< Указатель на объект контроллера для управления окном поиска и замены текста, окном перехода к строке.*/

    /**
     * @brief Метод инициализации сигналов и слотов приложения.
     */
    void initSignals();

private slots:

    /**
     * @brief Слот для отображения диалогового окна с информацией о приложении.
     */
    void slotShowAbout();
};
#endif // MAINWINDOW_H
