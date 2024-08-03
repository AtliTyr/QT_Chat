#ifndef SERVERPANEL_H
#define SERVERPANEL_H

#include <QMainWindow>
#include <QListWidget>
#include "Database.h"
#include <QTimer>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QString>
#include <QVector>
#include <QDateTime>
#include <QDialogButtonBox>
#include <string>
#include "logger.h"
#include <vector>
#include <QMenuBar>
#include <QMessageBox>
#include <QCheckBox>
#include <QWidgetAction>
#include "searchform.h"
#include <map>
#include <QMainWindow>

namespace Ui {
class ServerPanel;
}

class ServerPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerPanel(std::shared_ptr<Database> db, QWidget *parent = nullptr);
    ~ServerPanel();

    void updateServerInfo();
    void setSearchFilter(bool isB, bool isM, bool status);

public slots:

    void actionButtonProcessing(QAction*);
    void banButtonClicked();
    void unBanButtonClicked();
    void muteButtonClicked();
    void unMuteButtonClicked();
    void kickButtonClicked();

private slots:

    void on_TypeUserNameEdit_returnPressed();

    void on_UsersList_itemDoubleClicked(QListWidgetItem *item);

    void on_typeCommandEdit_returnPressed();

    void on_SendToEveryoneButton_clicked();

    void on_SendPrivateButton_clicked();

    void on_searchOptionsButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::ServerPanel *ui;
    std::shared_ptr<Database> dbPtr;
    Logger logs;
    map<std::string, SearchingFilters> usersInfo;
    SearchingFilters filters;
    QVector<QMainWindow*> connectionsList;
};

#endif // SERVERPANEL_H
