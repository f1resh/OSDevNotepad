#include <QDialog>
#include <QWidget>


class QPushButton;
class QGridLayout;
class QSpinBox;
class QLabel;
class QMdiArea;
class QTextEdit;

// Класс DialogGoToString для перехода к строке с указанным номером

class DialogGoToString : public QDialog
{
public:
    DialogGoToString(QMdiArea* area, QWidget *parent = nullptr); //Конструктор класса DialogGoToString
    ~DialogGoToString(); // Деструктор класса DialogGoToString
    int lineNumber() const; // Метод для получения номера строки к которой нужно перейти

private:
    QPushButton* goTo; // Кнопка для перехода к строке с указанным номером
    QPushButton* cancel; // Кнопка для закрытиф формы
    QSpinBox* m_lineNumber; // Поле для ввода номера строки
    QLabel* strNumber; // Подпись поля для ввода номера строки
    QMdiArea* mainArea; // Указатель на главное окно QMdiArea

    QTextEdit* getCurrentTextEdit(QMdiArea* mainArea = nullptr); // Метод для получения указателя на текущий QTextEdit в QMdiArea
    int getStringsNumbers(QTextEdit* currentTextEdit = nullptr); // Метод для получения количества строк в докуметне
    void init(); // Метод инициализации класса

private slots:
    void moveCursorToString(); // Слот для перемещения курсора в начало строки с указанным номером
};
