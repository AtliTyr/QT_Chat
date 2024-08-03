#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QWidget>
#include <QListWidget>
#include "Database.h"
#include "logger.h"

namespace Ui {
class SearchForm;
}

class SearchForm : public QWidget
{
    Q_OBJECT

public:
    explicit SearchForm(QList<QListWidgetItem*>, std::shared_ptr<Database>, QWidget *parent = nullptr);
    ~SearchForm();

public slots:

    void actionButtonProcessing(QAction*);
    void banButtonClicked();
    void unBanButtonClicked();
    void muteButtonClicked();
    void unMuteButtonClicked();
    void kickButtonClicked();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Logger logs;
    Ui::SearchForm *ui;
    std::shared_ptr<Database> dbPtr;
};

#endif // SEARCHFORM_H
