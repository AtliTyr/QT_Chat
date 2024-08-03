#include "searchform.h"
#include "ui_searchform.h"
#include <QMenu>

QListWidgetItem* curU;

SearchForm::SearchForm(QList<QListWidgetItem*> usersList,
                       std::shared_ptr<Database> db,
                       QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchForm)
{
    ui->setupUi(this);

    dbPtr = db;

    for(auto w = usersList.begin(); w != usersList.end(); w++)
    {
        ui->listWidget->addItem((*(w))->text());
    }

}

SearchForm::~SearchForm()
{
    delete ui;
}

void SearchForm::actionButtonProcessing(QAction * act)
{
    QString clckdButtonName = act->text();
    if(clckdButtonName == "Ban")
    {
        banButtonClicked();
    }
    else if(clckdButtonName == "Mute")
    {
        muteButtonClicked();
    }
    else if(clckdButtonName == "Kick")
    {
        kickButtonClicked();
    }
    else if(clckdButtonName == "Unban")
    {
        unBanButtonClicked();
    }
    else if(clckdButtonName == "Unmute")
    {
        unMuteButtonClicked();
    }
    on_pushButton_clicked();
}

void SearchForm::banButtonClicked()
{
    dbPtr->banUser(curU->text().toStdString());
}

void SearchForm::unBanButtonClicked()
{
    dbPtr->unbanUser(curU->text().toStdString());
}

void SearchForm::muteButtonClicked()
{
    dbPtr->muteUser(curU->text().toStdString());
}

void SearchForm::unMuteButtonClicked()
{
    dbPtr->unmuteUser(curU->text().toStdString());
}

void SearchForm::kickButtonClicked()
{
    dbPtr->kickUser(curU->text().toStdString());
}

void SearchForm::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    curU = item;

    auto menu = new QMenu(this);
    menu->addAction(new QAction("Kick"));

    auto tmp = dbPtr->get_RaS_by_Username(item->text().toStdString());

    auto b = new QAction("Ban");
    b->setEnabled((tmp.isBanned) ? false : true);
    menu->addAction(b);

    auto m = new QAction("Mute");
    m->setEnabled((tmp.isMuted) ? false : true);
    menu->addAction(m);

    auto unB = new QAction("Unban");
    unB->setEnabled((tmp.isBanned) ? true : false);
    menu->addAction(unB);

    auto unM = new QAction("Unmute");
    unM->setEnabled((tmp.isMuted) ? true : false);
    menu->addAction(unM);

    connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(actionButtonProcessing(QAction*)));

    QPoint point;
    point.setX(this->cursor().pos().x());
    point.setY(this->cursor().pos().y());
    menu->popup(point);
}


void SearchForm::on_pushButton_clicked()
{
    this->close();
}

