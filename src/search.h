#pragma once

#include <QObject>
#include <QDialog>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QTextCursor>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QTabWidget>
#include <QEventLoop>

/**
 * @class Search
 * @brief Класс для поиска и замены текста в QTextEdit с использованием QMdiArea. Все методы класса применяются к текущему на момент выполнения документу.
 */
class Search: public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief Конструктор класса Search.
     * @param mdi Указатель на QMdiArea, в котором выполняется поиск и замена текста.
     * @param parent Родительский виджет (по умолчанию nullptr).
     */
    Search(QMdiArea *mdi, QWidget *parent = nullptr);

private slots:

    /**
     * @brief Слот для поиска текста и отображения результатов.
     */
    void findText();

    /**
     * @brief Слот для замены выделенного текста.
     */
    void replaceSelectedText();

    /**
     * @brief Слот для замены всех найденных фрагментов текста.
     */
    void replaceAllText();

    /**
     * @brief Слот для инициализации макета (layout) вкладок.
     * @param index Индекс текущей вкладки.
     */
    void initLayout(int index);

public slots:

    /**
     * @brief Слот для открытия вкладок.
     * @param index Индекс текущей вкладки.
     */
    void showTab(int index);

    void exit();

private:

    QDialog* findDialog{nullptr};           ///< Диалоговое окно для поиска и замены текста.
    QTabWidget *tabWidget{nullptr};         ///< Виджет вкладок для функций поиска и замены.
    QMdiArea *mdiMain{nullptr};             ///< Указатель на главное окно QMdiArea.

    QLabel *findLabel{nullptr};             ///< Подпись поля ввода текста для поиска.
    QLineEdit* findLineEdit{nullptr};       ///< Поле ввода текста для поиска.
    QPushButton* findPrevButton{nullptr};   ///< Кнопка для поиска предыдущего фрагмента текста.
    QPushButton* findNextButton{nullptr};   ///< Кнопка для поиска следующего фрагмента текста.

    QLabel *replaceLabel{nullptr};          ///< Подпись поля ввода текста для замены.
    QLineEdit* replaceLineEdit{nullptr};    ///< Поле ввода текста для замены.
    QPushButton* replacePrevButton{nullptr};///< Кнопка для замены текущего результата и поиска предыдущего фрагмента текста.
    QPushButton* replaceNextButton{nullptr};///< Кнопка для замены текущего результата и поиска следующего фрагмента текста.
    QPushButton* replaceAllButton{nullptr}; ///< Кнопка для замены всех найденных фрагментов текста.

    QLabel* resultLabel{nullptr};           ///< Метка для отображения результатов поиска и замены.

    /**
     * @brief Метод для очистки макета вкладки.
     * @param layout Указатель на макет, который нужно очистить.
     */
    void clearTabLayout(QGridLayout* layout);

    /**
     * @brief Метод инициализации класса.
     */
    void init();

    /**
     * @brief Метод заполнения поля ввода текста для поиска выделенным фрагментом(если фрагмент не выделен, поле остается пустым при активации окна).
     */
    void findLineEditInit();

    bool findStatus{false};                 ///< Флаг состояния поиска (true, если найдено хотя бы одно совпадение).

    /**
     * @brief Метод для получения указателя на текущий QTextEdit в QMdiArea.
     * @return Указатель на текущий QTextEdit или nullptr, если такого нет.
     */
    QTextEdit* getCurrentTextEdit();

    quint32 replaceCounter{0};              ///< Счетчик замен.

};
