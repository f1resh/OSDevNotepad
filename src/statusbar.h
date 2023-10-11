#pragma once

#include <QStatusBar>

/**
 * @class Класс StatusBar
 * @brief Виджет для отображения информации в строке состояния.
 *
 * Этот класс наследует функциональность QStatusBar и предоставляет дополнительные метки для отображения
 * информации о символах, строках и текущей позиции курсора в текстовом редакторе.
 */
class StatusBar: public QStatusBar
{
    Q_OBJECT
public:
    /**
     * @brief Конструктор класса StatusBar.
     * @param mdi Указатель на объект многодокументного окна.
     */
    StatusBar(class MdiMain* mdi);

private slots:
    /**
     * @brief Слот для проверки состояния меток.
     */
    void check();

    /**
     * @brief Слот для обновления информации при смене документа.
     */
    void changeTxt();

private:
    MdiMain *mdiMain;                       /**< Указатель на объект многодокументного окна. */
    class QTextEdit *txt;                   /**< Указатель на текущий документ. */

    class QLabel *symbolsAndLinesLabel;     /**< Метка для отображения информации о символах и строках. */
    QLabel *cursorPosLabel;                 /**< Метка для отображения текущей позиции курсора. */
    QLabel *langInfoLabel;                  /**< Метка для отображения информации о языке. */
    bool isActive{false};                   /**< Флаг активности меток. */

    /**
     * @brief Метод для инициализации виджета.
     */
    void init();

    /**
     * @brief Метод для добавления меток в строку состояния.
     */
    void addLabels();

    /**
     * @brief Метод для удаления меток из строки состояния.
     */
    void removeLabels();

    /**
     * @brief Метод для отображения меток в строке состояния.
     */
    void showLabels();
};
