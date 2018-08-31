#pragma once
#include <string>
#include <ctime>
#include "UserMessInfo.h"
#include <iostream>
#include "userInfo.h"
using namespace std;
class Controller
{
public:
	void RequestAddFriend(string userID, string friendName);
	bool CheckFriendNameToAddFriend(string userID,string friendName);
	bool CheckFriendList(string userID,string friendName);

	void RequestBlockFriend(string userID, string FriendName);
	bool CheckFriendName(string userID, string friendName);

	void RequestDisplay(string userID);

	list<string> RequestFriendList(string userID);
	list<string> TakeFriendListIDUserSentMess(string userID);
	list<string> DisplayFriendLisForCity(string userID);

	bool CheckInputUserNameAndPassWord(std::string userName, std::string passWord);
	bool CheckUserName(std::string userName);
	bool CheckPassWord(std::string userName, std::string passWord);
	void ChangeLogInStatus(std::string userID);

	bool CheckPersonalInfo(string UserName, string FullName, string PassWord, string PassWordAgain, int DayOfBirth, int MonthOfBirth, int YearOfBirth, string Sex, string Address, string Other);
	bool CheckUserNameToRegister(string userName);
	bool CheckPassWordAndPassWordAgain(string PassWord, string PassWordAgain);
	bool CheckDoB(int DayOfBirth, int MonthOfBirth, int YearOfBirth);

	void RequestLogOut(string userID);

	void RequestDislayMesswithFriend(string userID, string FriendName);

	list<string> TakeFriendList(string userID);
	string TakeFriendID(string userID, int int_Position);
	string TakeNameFromID(string userID);
	void SentMess(string userID, string friendName, string Mess);
	bool CheckFriend(string userID, string friendName);

	string TakeMumberOfMess(string userID);
	list<string> TakeSenter(string userID);
	//string TakeNameFromID(string userID);
	list<string> TakeMessIDFromFriendIDHaveNotSeen(string userID, string friendID);
	string SeenMessThatHaveNotSeen(string userID, string friendID, string messID);
	void ChangeMessStatus(string userID, string friendID, string messID);
	void ChangeFriendInfo(string userID, string positionOfFriendList);



	void ChangeFriendDoB(string userID, string friendID, int DayOfBirth, int MonthOfBirth, int YearOfBirth);
	void ChangeFriendGender(string userID, string friendID, string newGender);
	void ChangeFriendAddress(string userID, string friendID, string newAddress);
	Controller();
	~Controller();
};

