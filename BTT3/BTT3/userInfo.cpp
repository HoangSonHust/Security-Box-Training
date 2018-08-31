#define _CRT_SECURE_NO_WARNINGS
#include "userInfo.h"
#include<iostream>
#include <string>
#include "string.h"
#include "sqlite3.h" 
#include "ConnectSQLite.h"
using namespace std;
ConnecSQLite connectSQLite1;

string userInfo::TakeUserID(string userName)
{
	string strsql = "SELECT userId from userInfo where userName ='" + userName + "'";
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.TakeDataFromSQLite(sql);
	return connectSQLite1.TakeDataFromSQLite(sql);
}

string userInfo::TakeUserIDMAX()
{
	string strsql = "select max(userID) from userInfo";
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.TakeDataFromSQLite(sql);
	return connectSQLite1.TakeDataFromSQLite(sql);
}

string userInfo::TakeUserIDfromUserID(string userID)
{
	string strsql = "SELECT friendId from '"+ userID+ "'" ;
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.TakeDataFromSQLite(sql);
	return connectSQLite1.TakeDataFromSQLite(sql);
}

string userInfo::TakeUserPassWord(string userName)
{
	string strsql = "SELECT passWord from userInfo where userName ='" + userName + "'";
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.TakeDataFromSQLite(sql);
	return connectSQLite1.TakeDataFromSQLite(sql);
}

void userInfo::ChangeLogInStatus(string userID)
{
	string strsql = "UPDATE userInfo SET logInStatus = '1'  WHERE userID = '" + userID+"'"  ;
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
    connectSQLite1.UpdateDataFromSQLite(sql);
}

void userInfo::ChangeLogOutStatus(string userID)
{
	string strsql = "UPDATE userInfo SET logInStatus = '0'  WHERE userID = '" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.UpdateDataFromSQLite(sql);
}

void userInfo::UpdateNewUser(string userID, string UserName, string fullName,string PassWord, string PassWordAgain, string DayOfBirth, string Sex, string Address, string Other)
{
	string strsql = "INSERT INTO userInfo(userID, userName,fullName, passWord, Gender, address, dateOfBirth, Other)VALUES('" + userID +"'," + "'"+UserName+"',"+ "'"+ fullName +"',"+"'"+ PassWord+"',"+"'"+ Sex +"',"+ "'"+ Address + "',"+ "'"+ DayOfBirth +"',"+"'"+Other+"'" +")";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.PrintDataFromSQLite(sql);
}


