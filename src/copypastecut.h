#pragma once
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QTextEdit.h>
#include <QtGui/QClipboard>
#include <QtWidgets/QApplication>
#include "mdimain.h"

/**
 * @class Класс CopyPasteCut
 * @brief Класс функций копирования, вставки, вырезания и удаления текста.
 */
class CopyPasteCut : public QObject
{
    Q_OBJECT

private:
    MdiMain* mdi;        /**< Указатель на объект многодокументного окна MdiMain.*/
public:

    /**
     * @brief Конструктор класса CopyPasteCut.
     * @param m Указатель на объект многодокументного окна.
     */
    CopyPasteCut(MdiMain* m) : mdi(m)
    {

    };

public slots:

    /**
     * @brief Слот для копирования выделенного текста в буфер обмена.
     */
    void slotCopyToClipboard();

    /**
     * @brief Слот для вставки текста из буфера обмена.
     */
    void slotPasteFromClipboard();

    /**
     * @brief Слот для вырезания выделенного текста и копирования его в буфер обмена.
     */
    void slotCutText();

    /**
     * @brief Слот для выделения всего текста в активном документе.
     */
    void slotSelectAll();

    /**
     * @brief Слот для удаления выделенного текста либо символа после курсора при отсутвии выделенного фрагмента.
     */
    void slotDeleteText();

};
