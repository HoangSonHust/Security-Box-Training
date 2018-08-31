#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include "userInfo.h"
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include "string.h"
#include "sqlite3.h" 
#include "ConnectSQLite.h"
class userInfo
{
public:
	//string TakeUserID(string userName);
	string TakeUserID(string userName);
	string TakeUserIDMAX();
	string TakeUserIDfromUserID(string userName);
	string TakeUserPassWord(string userName);
	void ChangeLogInStatus(string userID);
	void ChangeLogOutStatus(string userID);
	void UpdateNewUser(string userID, string UserName, string fullName, string PassWord, string PassWordAgain, string DayOfBirth, string Sex, string Address, string Other);
	string TakeNameFromID(string userID);
	void ChangeFriendDoB(string userID, string friendID, string newDoB);
	void ChangeFriendGender(string userID, string friendID, string newGender);
	void ChangeFriendAddress(string userID, string friendID, string newAddress);
	list<string> select(string userID);

};

