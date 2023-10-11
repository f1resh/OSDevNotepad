#ifndef MDIMAIN_H
#define MDIMAIN_H

#include <QWidget>
#include <QMdiArea>
#include <QTextEdit>
#include <QMdiSubWindow>

/**
 * @class Класс MdiMain
 * @brief Основное окно приложения с поддержкой множества документов.
 */
class MdiMain : public QMdiArea
{
    Q_OBJECT

public:

    /**
     * @brief Конструктор класса MdiMain.
     * @param parent Указатель на родительский виджет.
     */
    MdiMain(QWidget *parent = nullptr);

    /**
     * @brief Метод получения активного документа.
     * @return Указатель на активный документ.
     */
    QTextEdit* getActiveDocument();

public slots:

    /**
     * @brief Слот для открытия нового документа.
     */
    void slotOpenNewDoc();

    /**
     * @brief Слот для выполнения печати.
     */
    void slotPrint();

    /**
     * @brief Слот для выполнения отмены последнего действия.
     */
    void slotUndo();

    /**
     * @brief Слот для выполнения возврата последнего действия.
     */
    void slotRedo();

    /**
     * @brief Слот для закрытия активного документа.
     */
    void slotClose();
signals:

private:

    /**
     * @todo Метод для назначения имени документа.
     */
    void nameDoc();
};

#endif // MDIMAIN_H
