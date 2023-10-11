#pragma once

#include <QString>
#include <QDir>

/**
 * @class Класс FileIO
 * @brief Класс для работы с файлами (чтение и запись).
 */
class FileIO
{
private:
    QString content_ = "";      /**< Содержимое файла.*/
    QDir path_;                 /**< Путь к файлу.*/
    QString filters_;           /**< Фильтры для выбора файлов при сохранении.*/
    QString filename_;          /**< Имя текущего файла.*/
public:

    /**
     * @brief Конструктор класса FileIO.
     * @param filters Фильтры для выбора файлов при сохранении.
     * @param path Путь к файлу.
     */
    FileIO(const QString& filters, const QDir& path) : filters_(filters), path_(path) {};

    /**
     * @brief Конструктор по умолчанию класса FileIO.
     */
    FileIO();

    /**
     * @brief Деструктор класса FileIO.
     */
    ~FileIO();

    /**
     * @brief Метод загрузки содержимого файла.
     * @return true в случае успешной загрузки, иначе false.
     */
    bool Load();

    /**
     * @brief Метод сохранения текста в файл.
     * @param text Текст для сохранения.
     * @return true в случае успешного сохранения, иначе false.
     */
    bool Save(QString&);

    /**
     * @brief Возвращает имя текущего файла.
     * @return Имя файла.
     */
    QString getFileName();

    /**
     * @brief Возвращает содержимое текущего файла.
     * @return Содержимое файла.
     */
    QString getContent();
};


