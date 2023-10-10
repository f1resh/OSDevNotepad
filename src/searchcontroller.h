#pragma once

#include "qmdiarea.h"
#include "qobject.h"

/**
 * @enum Tab
 * @brief Перечисление для определения текущей вкладки (Поиск или Замена).
 */
enum class Tab
{
    Find,                               /**< Вкладка "Поиск". */
    Replace                             /**< Вкладка "Замена". */
};

/**
 * @class SearchController
 * @brief Класс SearchController представляет контроллер для управления диалогами поиска и замены текста и перехода к строке.
 *
 * Этот класс обеспечивает создание и управление диалоговыми окнами для поиска, замены и перехода к определенной позиции в тексте.
 */
class SearchController: public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса SearchController.
     * @param[in] mdi Указатель на объект многодокоментного окна QMdiArea.
     * @param[in] parent Указатель на родительский объект.
     */
    SearchController(QMdiArea *mdi, QObject* parent = nullptr);

private:
    QMdiArea *mdiMain{nullptr};         /**< Указатель на объект класса QMdiArea. */
    bool searchIsOpen{false};           /**< Флаг открытия диалога поиска. */
    bool gotoIsOpen{false};             /**< Флаг открытия диалога перехода к определенной строке. */

    /**
     * @brief Метод для создания диалога поиска и замены текста.
     */
    void createSearch();

    /**
     * @brief Метод для создания диалога перехода к определенной строке в тексте.
     */
    void createGoTo();

signals:
    /**
     * @brief Сигнал для открытия вкладки поиска или замены текста.
     * @param[in] int Текущая вкладка (Tab::Find или Tab::Replace).
     */
    void openSearchTab(int);

    /**
     * @brief Сигнал для открытия диалога перехода к определенной строке в тексте.
     */
    void openGoTo();

    /**
     * @brief Сигнал для закрытия диалоговых окон.
     */
    void closeDialog();

public slots:
    /**
     * @brief Слот для открытия вкладки "Поиск".
     */
    void openFindTab();

    /**
     * @brief Слот для открытия вкладки "Замена".
     */
    void openReplaceTab();

    /**
     * @brief Слот для открытия диалога перехода к определенной строке в тексте.
     */
    void openGoToDialog();

private slots:
    /**
     * @brief Слот для инвертирования флага открытия диалога поиска и замены текста.
     */
    void invertSearchIsOpen();

    /**
     * @brief Слот для инвертирования флага открытия диалога перехода к определенной строке.
     */
    void invertGoToIsOpen();

    /**
     * @brief Слот для закрытия диалоговых окон.
     */
    void closeDialogWindow();
};
