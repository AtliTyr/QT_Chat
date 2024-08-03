#include "Database.h"
#include "Parsing.h"
#include "sha1.h"
#include <memory>
#include <QDateTime>
//'Ανθρωπος

int Database::searchUserByName(string username)
{
	auto uit = _usersMapByName.find(username);
	if (uit != _usersMapByName.end()) return uit->second;
  return -1;
}

vector<string> Database::getUserList() const
{
  vector<string> userList;
  for(auto user : _usersMapByName)
  {
    userList.push_back(user.first);
  }
  return userList;
}

int Database::getUsersCount() const
{
    return _users.size();
}

string Database::getUserName(int userId) const
{
  for (auto it = _usersMapByName.begin(); it != _usersMapByName.end(); ++it) {
    if (it->second == userId)
      return it->first;
  }
  return "";
}

Database::Database() : _users(), _messages()
{
}

int Database::addUser(string username, string password)
{
	if (!correctName(username)) return -1;
	auto uit = _usersMapByName.find(username);
	if (uit != _usersMapByName.end()) return -2;
	User newUser = User(username, sha1(password));
	_users.push_back(newUser);
  _usersMapByName.insert({ username, newUser.getUserID() });

    logs.addNewStringToLogs("User \"" + username + "\" has registered");
    //logs.addNewStringToLogs("User \"" + username + "\" is logged in");

    _RaS.emplace_back(RestrictionsAndStatuses(username));
	return newUser.getUserID();
}

int Database::checkPassword(string username, string password)
{
	int result = -1;
	Hash passHash = sha1(password);
	for (const auto &u : _users)
	{
		result = u.checklogin(username, passHash);
        if (result != -1)
        {
            logs.addNewStringToLogs("User \"" + username + "\" is trying to log in");
            return result;
        }
    }
	return result;
}

void Database::addChatMessage(string sender, string text)
{
    auto ras = get_RaS_by_Username(sender);
    if(!ras.isMuted)
    {
        _messages.push_back(Message(sender, text));
        logs.addNewStringToLogs("User <" + sender + "> messages to everyone: " + text);
    }
}

bool Database::addPrivateMessage(string sender, string target, string message)
{
	int targetUser = searchUserByName(target);
	if (targetUser < 0)
	{
		return false;
	}
    auto ras = get_RaS_by_Username(sender);
    if(!ras.isMuted)
    {
        _messages.push_back(Message(sender, targetUser, message));
        logs.addNewStringToLogs("User <" + sender + "> messages to <" + target + "> : " + message);
        return true;
    }
    return false;
}

void Database::addServerMessage(string text)
{
    _messages.push_back(Message("!!!!!!!!!SERVER MESSAGE!!!!!!!!! ", text));
    logs.addNewStringToLogs("!!!!!!!!!SERVER MESSAGE!!!!!!!!! " + text);
}

bool Database::addServerPrivateMessage(string target, string message)
{
    int targetUser = searchUserByName(target);
    if (targetUser < 0)
    {
        return false;
    }

    _messages.push_back(Message("!!!!!!!!!!!SERVER MESSAGE!!!!!!!!!!", targetUser, message));
    logs.addNewStringToLogs("!!!!!!!!!!!SERVER MESSAGE!!!!!!!!!! to <" + target + "> : " + message);
    return true;
}

vector<string> Database::getChatMessages()
{
	vector<string> strings;
	for (auto &m: _messages)
	{
		if (m.getDest() == -1)
		{
			strings.push_back("<" + m.getSender() + ">: " + m.getText());
		}
	}
	return strings;
}

vector<Message> Database::getPrivateMessage(int userID)
{
	vector<Message> strings;
	//int userID = searchUserByName(username);
	for (auto &m : _messages)
  {
    if(userID == -1 && m.getDest() != -1)
      strings.push_back(m);
    else if(userID != -1 && m.getDest() == userID)
      strings.push_back(m);
	}
	return strings;
}


////////////////////////////////////////////////

SearchingFilters Database::get_RaS_by_Username(std::string userName) const
{
    for(auto it = _RaS.begin(); it != _RaS.end(); it++)
        if(it->userName == userName)
        {
            return it->getRaS();
        }
}

void Database::banUser(string uName)
{
    for(auto it = _RaS.begin(); it != _RaS.end(); it++)
        if(it->userName == uName)
        {
            if(it->filts.isBanned != true)
            {
                logs.addNewStringToLogs("User \"" + uName + "\" is banned");
                it->filts.isBanned = true;
                this->disruptConnection(uName);
            }
            else
            {
                logs.addNewStringToLogs("User \"" + uName + "\" is already banned!");
            }
            break;
        }
}

void Database::muteUser(string userName)
{
    for(auto it = _RaS.begin(); it != _RaS.end(); it++)
        if(it->userName == userName)
        {
            if(it->filts.isMuted != true)
            {
                logs.addNewStringToLogs("User \"" + userName + "\" is muted");
                it->filts.isMuted = true;
            }
            else
                logs.addNewStringToLogs("User \"" + userName + "\" is already muted!");
            break;
        }
}

void Database::kickUser(string userName)
{
    if(this->connectionExists(userName))
    {
        this->disruptConnection(userName);
        logs.addNewStringToLogs("User \"" + userName + "\" is kicked");
    }
    else
        logs.addNewStringToLogs("User \"" + userName + "\" is offline!");
}

void Database::unbanUser(string userName)
{
    for(auto it = _RaS.begin(); it != _RaS.end(); it++)
        if(it->userName == userName)
        {
            if(it->filts.isBanned)
            {
                logs.addNewStringToLogs("User \"" + userName + "\" is unbanned");
                it->filts.isBanned = false;
            }
            else
                logs.addNewStringToLogs("User \"" + userName + "\" is not banned!");
            break;
        }
}

void Database::unmuteUser(string userName)
{
    for(auto it = _RaS.begin(); it != _RaS.end(); it++)
        if(it->userName == userName)
        {
            if(it->filts.isMuted)
            {
                logs.addNewStringToLogs("User \"" + userName + "\" is unmuted");
                it->filts.isMuted = false;
            }
            else
                logs.addNewStringToLogs("User \"" + userName + "\" is not muted!");
            break;
        }
}

void Database::setUserOnline(string userName)
{
    for(auto it = _RaS.begin(); it != _RaS.end(); it++)
        if(it->userName == userName)
        {
            it->filts.status = true;
            logs.addNewStringToLogs("User \"" + userName + "\" is logged in");
            break;
        }
}

void Database::setUserOffline(string userName)
{
    for(auto it = _RaS.begin(); it != _RaS.end(); it++)
        if(it->userName == userName)
        {
            it->filts.status = false;
            logs.addNewStringToLogs("User \"" + userName + "\" is disconnected");
            break;
        }
}
//////////////////////////////////////////////////

void Database::addNewConnection(string userName, QMainWindow *con)
{
    this->setUserOnline(userName);
    conns[userName] = con;
}

void Database::disruptConnection(string userName)
{
    auto tmp = conns.find(userName);
    //QMainWindow* tmp = conns[userName];
    if(tmp != conns.end())
        tmp->second->~QMainWindow();
        //tmp->~QMainWindow();
    /*for(auto it = conns.begin(); it != conns.end(); it++)
    {
        if(it->userName == userName)
        {
            if(it->connection)
                it->connection->~QMainWindow();
            return;
        }
    }*/
}

void Database::disruptConnectionA(string userName)
{
    this->setUserOffline(userName);
    auto it = conns.find(userName);
    conns.erase(it);
    /*for(auto it = conns.begin(); it != conns.end(); it++)
    {
        if(it->userName == userName)
        {

            conns.erase(it);
            return;
        }
    }*/
}

bool Database::connectionExists(string userName)
{
    auto it = conns.find(userName);
    if(it != conns.end())
        return true;
    return false;
}
