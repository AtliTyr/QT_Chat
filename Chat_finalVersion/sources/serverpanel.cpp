#include "serverpanel.h"
#include "ui_serverpanel.h"

bool ban = false;
bool mut = false;
bool onl = false;
QListWidgetItem* cU = nullptr;


ServerPanel::ServerPanel(std::shared_ptr<Database> db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServerPanel)
{
    ui->setupUi(this);

    logs.clearPreviousLogs();
    dbPtr = db;

    filters.status = true;

    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ServerPanel::updateServerInfo);
    timer->start(10);

}


ServerPanel::~ServerPanel()
{
    delete ui;
}

void ServerPanel::updateServerInfo()
{
    QString s = logs.getAllLogs();
    if(ui->LogsBrowser->toPlainText() != s)
    {
        ui->LogsBrowser->setText(s);
    }
    s.clear();

    //######################################

    /*if(!ui->updateBox->isChecked())
        return;
    */
    //return;
        bool rewrite = false;
        int size = ui->UsersList->count();

        auto uL = dbPtr->getUserList();
        if(size != dbPtr->getUsersCount())
        {
            ui->UsersList->clear();
            this->usersInfo.clear();

            for(const std::string& userName: uL)
            {
                auto i = new QListWidgetItem();
                i->setText(QString::fromStdString(userName));
                i->setBackground((dbPtr->get_RaS_by_Username(userName).status)
                                     ? QBrush(Qt::green)
                                     : QBrush(Qt::red));
                ui->UsersList->addItem(i);

                this->usersInfo[userName] = dbPtr->get_RaS_by_Username(userName);
            }
        }
        else
        {
            for(const std::string& userName: uL)
            {
                auto w = ui->UsersList->findItems(QString::fromStdString(userName), Qt::MatchFixedString);
                if(w.size())
                {
                    SearchingFilters tmp = usersInfo[userName];
                    SearchingFilters tmp2 = dbPtr->get_RaS_by_Username(userName);
                    if(!(tmp == tmp2))
                    {
                        rewrite = true;
                        break;
                    }
                }
            }

            if(rewrite)
            {
                ui->UsersList->clear();
                this->usersInfo.clear();

                for(const std::string& userName: uL)
                {
                    auto i = new QListWidgetItem();
                    i->setText(QString::fromStdString(userName));
                    i->setBackground((dbPtr->get_RaS_by_Username(userName).status)
                                         ? QBrush(Qt::green)
                                         : QBrush(Qt::red));
                    ui->UsersList->addItem(i);

                    this->usersInfo[userName] = dbPtr->get_RaS_by_Username(userName);
                }
            }
        }
}

void ServerPanel::setSearchFilter(bool isB, bool isM, bool stat)
{
    filters.isBanned = isB;
    filters.isMuted = isM;
    filters.status = stat;
}

void ServerPanel::actionButtonProcessing(QAction * act)
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
}

void ServerPanel::banButtonClicked()
{
    dbPtr->banUser(cU->text().toStdString());
}

void ServerPanel::unBanButtonClicked()
{
    dbPtr->unbanUser(cU->text().toStdString());
}

void ServerPanel::muteButtonClicked()
{
    dbPtr->muteUser(cU->text().toStdString());
}

void ServerPanel::unMuteButtonClicked()
{
    dbPtr->unmuteUser(cU->text().toStdString());
}

void ServerPanel::kickButtonClicked()
{
    dbPtr->kickUser(cU->text().toStdString());
}

void ServerPanel::on_TypeUserNameEdit_returnPressed()
{
    QString t = ui->TypeUserNameEdit->text();
    auto L = ui->UsersList->findItems(t, Qt::MatchContains);

    if(L.size() == 0)
    {
        QMessageBox::critical(this,
                              tr("Username search result"),
                              tr("NO USERS FOUND!"));
    }
    else
    {
        auto f = new SearchForm(L, dbPtr);
        f->setAttribute(Qt::WA_DeleteOnClose);
        f->show();
    }
}

void ServerPanel::on_UsersList_itemDoubleClicked(QListWidgetItem *item)
{
    cU = item;

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
    //connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(muteButtonClicked()));
    //connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(unBanButtonClicked()));
    //connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(unMuteButtonClicked()));

    QPoint point;
    point.setX(ui->centralwidget->cursor().pos().x());
    point.setY(ui->centralwidget->cursor().pos().y());
    menu->popup(point);



}

void ServerPanel::on_typeCommandEdit_returnPressed()
{
    on_SendToEveryoneButton_clicked();
}

void ServerPanel::on_SendToEveryoneButton_clicked()
{
    dbPtr->addServerMessage(ui->typeCommandEdit->text().toStdString());
}

void ServerPanel::on_SendPrivateButton_clicked()
{
    QDialog dial(this);
    dial.setModal(true);
    auto *l = new QVBoxLayout();
    dial.setLayout(l);
    auto* userListWgt = new QListWidget(&dial);
    l->addWidget(userListWgt);
    auto buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dial);
    l->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, &dial, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dial, &QDialog::reject);

    auto userList = dbPtr->getUserList();
    for(auto user : userList)
    {
        userListWgt->addItem(QString::fromStdString(user));
    }

    userListWgt->setCurrentRow(0);

    auto result = dial.exec();

    if(result == QDialog::Accepted &&
        userListWgt->currentItem())
    {

        dbPtr->addServerPrivateMessage(userListWgt->currentItem()->text().toStdString(),
                                 ui->typeCommandEdit->text().toStdString());
    }
}

void ServerPanel::on_searchOptionsButton_clicked()
{
    ban = filters.isBanned;
    mut = filters.isMuted;
    onl = filters.status;

    auto menu = new QMenu(this);


    auto bannedQWidgA = new QWidgetAction(menu);
    auto bannedCheckB = new QCheckBox(menu);
    bannedCheckB->setText("Banned Users");
    bannedCheckB->setChecked(filters.isBanned);
    bannedQWidgA->setDefaultWidget(bannedCheckB);
    menu->addAction(bannedQWidgA);

    menu->addSeparator();

    auto mutedQWidgA = new QWidgetAction(menu);
    auto mutedCheckB = new QCheckBox(menu);
    mutedCheckB->setText("Muted Users");
    mutedCheckB->setChecked(filters.isMuted);
    mutedQWidgA->setDefaultWidget(mutedCheckB);
    menu->addAction(mutedQWidgA);

    menu->addSeparator();

    auto onlineQWidgA = new QWidgetAction(menu);
    auto onlineCheckB = new QCheckBox(menu);
    onlineCheckB->setText("Only Online Users");
    onlineCheckB->setChecked(filters.status);
    onlineQWidgA->setDefaultWidget(onlineCheckB);
    menu->addAction(onlineQWidgA);

    menu->addSeparator();

    auto setOptionsQWidgA = new QWidgetAction(menu);
    auto setOptionsBut = new QPushButton(menu);
    setOptionsBut->setText("Set filter");
    setOptionsQWidgA->setDefaultWidget(setOptionsBut);
    menu->addAction(setOptionsQWidgA);



    connect(bannedCheckB, &QCheckBox::checkStateChanged, this, [&ban](){ban = !ban;});
    connect(mutedCheckB, &QCheckBox::checkStateChanged, this, [&mut](){mut = !mut;});
    connect(onlineCheckB, &QCheckBox::checkStateChanged, this, [&onl](){onl = !onl;});

    connect(setOptionsBut,
            &QPushButton::clicked,
            this,
            [this, ban, mut, onl](){ this->setSearchFilter(ban, mut, onl); });

    QPoint point;
    point.setX(ui->centralwidget->cursor().pos().x());
    point.setY(ui->centralwidget->cursor().pos().y());
    menu->popup(point);
}

void ServerPanel::on_searchButton_clicked()
{
    QList<QListWidgetItem *> res;
    auto Ul = ui->UsersList->findItems(ui->TypeUserNameEdit->text(), Qt::MatchContains);
    for(QListWidgetItem* s : Ul)
    {
        if(dbPtr->get_RaS_by_Username(s->text().toStdString()) == filters)
            res.push_back(s);
    }

    if(res.size() == 0)
    {
        QMessageBox::critical(this,
                              tr("Username search result"),
                              tr("NO USERS FOUND!"));
    }
    else
    {
        auto f = new SearchForm(res, dbPtr);
        f->setAttribute(Qt::WA_DeleteOnClose);

        f->show();
    }
}

