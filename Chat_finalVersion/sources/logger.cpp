#include "logger.h"
#include <QDateTime>

const char* lFILE_PATH = "logs.txt";

Logger::Logger()
{
    logs_f.setFileName(lFILE_PATH);
    //if(!logs_f.open(QIODeviceBase::ReadWrite | QIODeviceBase::Truncate))
       // return;
    //logs_f.close();
}

Logger::~Logger()
{
}

void Logger::addNewStringToLogs(std::string l)
{
    logs_f.open(QIODeviceBase::WriteOnly | QIODeviceBase::Append);
    QTextStream in(&logs_f);
    in << QString("[" + QDateTime::currentDateTime().toString() + "] ") << QString::fromStdString(l) << "\n";
    logs_f.close();
}

QString Logger::getAllLogs()
{
    logs_f.open(QIODeviceBase::ReadOnly | QIODeviceBase::Text);
    QString temp;
    QTextStream out(&logs_f);
    while (!out.atEnd()) {
        QString line = out.readLine();
        temp.append(line + '\n');
    }
    logs_f.close();
    return temp;
}

void Logger::clearPreviousLogs()
{
    logs_f.open(QIODeviceBase::WriteOnly | QIODeviceBase::Truncate);
    logs_f.close();
}


