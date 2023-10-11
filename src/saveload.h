#pragma once
#include <QMdiArea>
#include <QDir>
#include "mdimain.h"

/**
 * @class Класс SaveLoad
 * @brief Класс для сохранения и загрузки данных в приложении.
 */
class SaveLoad : public QObject
{
    Q_OBJECT
private:
    MdiMain* mdi;               /**< Указатель на объект многодокументного окна.*/
    QString filters;            /**< Фильтры файлов для диалога сохранения и загрузки.*/
    QString path;               /**< Путь к каталогу по умолчанию для сохранения и загрузки файлов.*/
public:

    /**
     * @brief Конструктор класса SaveLoad.
     * @param m Указатель на объект многодокументного окна.
     */
    SaveLoad(MdiMain* m) : mdi(m)
    {
        filters = tr("Text file(*.txt)");
        path = QDir::homePath();
    };

public slots:

    /**
     * @brief Слот для сохранения текста активного документа в файл.
     */
    void SaveActiveTabToFile();

    /**
     * @brief Слот для загрузки данных из файла в активный документ.
     */
    void LoadTabFromFile();
};

