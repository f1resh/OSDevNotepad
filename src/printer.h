#pragma once

#include <QTextEdit>

class Printer
{
private:
    QTextEdit* tEdit;
public:
    Printer(QTextEdit* textEdit) : tEdit(textEdit) {};

    void Print();
};

