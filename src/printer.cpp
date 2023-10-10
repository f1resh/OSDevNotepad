#include "printer.h"

#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>

void Printer::Print()
{
    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Печать");

    if (dialog->exec() != QDialog::Accepted) return;

    QPainter painter;
    painter.begin(&printer);

    QString text = tEdit->toPlainText();
    painter.drawText(100, 100, 500, 500, Qt::AlignLeft|Qt::AlignTop, text);

    painter.end();
}
