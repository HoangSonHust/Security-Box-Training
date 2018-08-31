#define _CRT_SECURE_NO_WARNINGS
#include "UserMessInfo.h"
#include"ConnectSQLite.h"
#include <iostream>
#include "ConnectSQLite.h"


ConnecSQLite ConnectSQLiteUserMessInfo;


void UserMessInfo::CreatUserTable(string userID)
{
	string strsql = "CREATE TABLE '"+  userID+"'"+ " (friendID TEXT, friendName TEXT, friendStatus TEXT, TimeAddFriend TEXT, messID TEXT,TimeReceiverMess TEXT,Senter TEXT,Receiver TEXT,Mess TEXT)";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
}

void UserMessInfo::RequestAddFriend(string userID, string friendID,string friendName, string TimeAddFriend)
{
	//string strsql = INSERT INTO userInfo(userID, userName, fullName, passWord, Gender, address, dateOfBirth, Other)VALUES('" + userID +"', " + "'"+UserName+"', "+ "'"+ fullName +"', "+"'"+ PassWord+"', "+"'"+ Sex +"', "+ "'"+ Address + "', "+ "'"+ DayOfBirth +"', "+"'"+Other+"'" +")";
	string strsql = "INSERT INTO '"+ userID+"' (friendID, friendName, friendStatus,TimeAddFriend )VALUES('" + friendID + "',' "+ friendName + "','1'," + "'" + TimeAddFriend + "'" +" )";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
}

string UserMessInfo::RequestFriendList(string userID)
{
	string strsql = "SELECT friendID, friendName from '" +userID+ "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
	//cout << ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
	cout << ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql) << endl;
	return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}

void UserMessInfo::RequestBlockFriend(string userID, string friendID)
{
	string strsql = "UPDATE '" +userID + "'"+  " SET friendStatus= '0'  WHERE friendID = '" + friendID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.UpdateDataFromSQLite(sql);
}

void UserMessInfo::RequestSentMess(string userID, string friendID, string Mess, string TimeMess, string MessID)
{
	string strsql = "INSERT INTO '" + userID + "' (messID,TimeReceiverMess,Senter,Receiver,Mess )VALUES('" + MessID + "',' " + TimeMess + "','"+userID+"'," + "'" + friendID + "','" +Mess +"' )";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
}

void UserMessInfo::RequestDisplayDetailMess(string userID, string messID)
{
	string strsql = "SELECT messID,TimeReceiverMess,Senter,Receiver,Mess from '" + userID + "' where messID= '"+ messID +"'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
}

void UserMessInfo::RequestDislayMesswithFriend(string userID, string friendID)
{

	string strsql = "SELECT messID,TimeReceiverMess,Senter,Receiver,Mess from '" + userID + "' where = Receiver '" + friendID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
}


UserMessInfo::UserMessInfo()
{
}


UserMessInfo::~UserMessInfo()
{
}

void RequestFriendList(string userID)
{
}
