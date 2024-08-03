#pragma once
#include <vector>
#include "User.h"
#include "Message.h"
#include <string>
#include <unordered_map>
#include "logger.h"

#include <QMainWindow>

struct SearchingFilters
{
    bool isBanned = false;
    bool status = false;
    bool isMuted = false;
    //SearchingFilters(): isBanned(false), isMuted(false), status(false) {}
    bool operator==(SearchingFilters& sf)
    {
        return (sf.isBanned == this->isBanned && sf.isMuted == this->isMuted && sf.status == this->status);
    }
};

struct RestrictionsAndStatuses
{
    std::string userName;
    SearchingFilters filts;
    RestrictionsAndStatuses(std::string _userName): userName(_userName), filts()
    {}
    SearchingFilters getRaS() const
    {
        return filts;
    }
};

/*struct usersConnections
{
    std::string userName;
    QMainWindow* connection;
};*/

class Database
{
    std::map<std::string, QMainWindow*> conns;
    std::vector<RestrictionsAndStatuses> _RaS;
    Logger logs;
    /////////////////////////////////
	vector<User> _users;
	vector<Message> _messages;
    unordered_map<string, int> _usersMapByName;
	int searchUserByName(string);
public:
    vector<string> getUserList() const;
    int getUsersCount() const;
    string getUserName(int userId) const;
	Database();
	int addUser(string username, string password);
	int checkPassword(string username, string password);
	void addChatMessage(string sender, string);
	bool addPrivateMessage(string sender, string target, string message);

    void addServerMessage(string);
    bool addServerPrivateMessage(string target, string message);

    vector<string> getChatMessages();//показать все сообщения
    vector<Message> getPrivateMessage(int userID = -1);//показать личные сообщения пользователю username
    ////////////////////////////////////
    SearchingFilters get_RaS_by_Username(std::string userName) const;
    void banUser(std::string userName);
    void muteUser(std::string userName);
    void kickUser(std::string userName);
    void unbanUser(std::string userName);
    void unmuteUser(std::string userName);
    void setUserOnline(std::string userName);
    void setUserOffline(std::string userName);
    ////////////////////////////////////
    void addNewConnection(string userName, QMainWindow* con);
    void disruptConnection(string userName);
    void disruptConnectionA(string userName);
    bool connectionExists(std::string userName);
    ////////////////////////////////////

};
