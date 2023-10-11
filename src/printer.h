#pragma once

#include <QTextEdit>

/**
 * @class Класс Printer
 * @brief Класс для печати содержимого активного документа.
 */
class Printer
{
private:
    QTextEdit* tEdit; /**< Указатель на документ, содержимое которого будет отправлено на печать.*/
public:

    /**
     * @brief Конструктор класса Printer.
     * @param textEdit Указатель на документ для печати.
     */
    Printer(QTextEdit* textEdit) : tEdit(textEdit) {};

    /**
     * @brief Метод для выполнения печати содержимого документа.
     */
    void Print();
};

