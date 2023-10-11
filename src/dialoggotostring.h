#include <QDialog>
#include <QWidget>


class QPushButton;
class QGridLayout;
class QSpinBox;
class QLabel;
class QMdiArea;
class QTextEdit;

/**
 * @class Класс DialogGoToString
 * @brief Диалоговое окно перехода к строке с указанным номером.
 */
class DialogGoToString : public QDialog
{
public:

    /**
     * @brief Конструктор класса DialogGoToString.
     * @param area Указатель на объект многодокументного окна.
     * @param parent Родительский виджет(по умолчанию nullptr).
     */
    DialogGoToString(QMdiArea* area, QWidget *parent = nullptr); //Конструктор класса DialogGoToString

    /**
     * @brief Деструктор класса DialogGoToString.
     */
    ~DialogGoToString();

    /**
     * @brief Метод для получения номера строки, к которой нужно перейти.
     * @return Номер строки.
     */
    int lineNumber() const;

private:
    QPushButton* goTo;              /**< Кнопка для перехода к строке с указанным номером.*/
    QPushButton* cancel;            /**< Кнопка для закрытия формы.*/
    QSpinBox* m_lineNumber;         /**< Поле для ввода номера строки.*/
    QLabel* strNumber;              /**< Подпись поля для ввода номера строки.*/
    QMdiArea* mainArea;             /**< Указатель на объект многодокументного окна.*/

    /**
     * @brief Метод для получения указателя на активный документ.
     * @param mainArea Указатель на объект многодокументного окна(по умолчанию nullptr).
     * @return Указатель на активный документ.
     */
    QTextEdit* getCurrentTextEdit(QMdiArea* mainArea = nullptr);

    /**
     * @brief Метод для получения количества строк в документе.
     * @param currentTextEdit Указатель на активный документ(по умолчанию nullptr).
     * @return Количество строк в документе.
     */
    int getStringsNumbers(QTextEdit* currentTextEdit = nullptr);

    /**
     * @brief Метод инициализации класса.
     */
    void init();

private slots:

    /**
     * @brief Слот для перемещения курсора в начало строки с указанным номером.
     */
    void moveCursorToString();

    /**
     * @brief Слот для обновления количества строк в текущем документе при изменении количества строк или переходе на новую вкладку.
     */
    void updateLinesCount();
};
