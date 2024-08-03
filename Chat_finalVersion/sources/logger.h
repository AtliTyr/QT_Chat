#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QString>
#include <QVector>
#include <QTextStream>
#include <QDataStream>

class Logger
{
private:
    QFile logs_f;
public:
    Logger();
    ~Logger();
    void addNewStringToLogs(std::string);
    QString getAllLogs();

    void clearPreviousLogs();
};

#endif // LOGGER_H
