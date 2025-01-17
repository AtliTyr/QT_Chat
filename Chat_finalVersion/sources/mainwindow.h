#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "Database.h"
#include "logger.h"
#include <QMessageBox>
#include "serverpanel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int userId,
                        QString userName,
                        std::shared_ptr<Database> = nullptr,
                        QWidget *parent = nullptr);
    ~MainWindow();

    static MainWindow* createClient(std::shared_ptr<Database> dbPtr = nullptr);

    static int kInstanceCount;

private slots:
    void on_messageLineEdit_returnPressed();
    void on_sendMessageButton_clicked();
    void on_privateMessageSendButton_clicked();
    void on_actionOpen_another_client_triggered();
    void on_actionCloseClient_triggered();
    void updateChats();
    void on_actionOpen_panel_triggered();

private:
    Logger logs;
    Ui::MainWindow *ui;
    std::shared_ptr<Database> m_dbPtr;
    int m_userId;
    QString m_userName;
};

#endif // MAINWINDOW_H
