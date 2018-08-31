#include<iostream>
#include "LogInController.h"
#include "userInfo.h"
//#include <string>
using namespace std;
userInfo userInfo1;
bool LogInController::CheckInputUserNameAndPassWord(string userName, string passWord)
{
	if (CheckPassWord( userName,passWord) == CheckUserName(userName) == true) {
		cout << "Class LogInController ___ " <<"login ok" << " ___ Class LogInController " << endl;
		//userInfo1.ChangeLogInStatus(userInfo1.TakeUserID(userName));
		userInfo1.ChangeLogInStatus("1234567890");
		cout << userInfo1.TakeUserID(userName);
		ChangeLogInStatus(userInfo1.TakeUserID(userName));
	  
		return true;
	}
	else
	{
		cout << "Class LogInController ___ " << "login KHONG ok" << " ___ Class LogInController " << endl;
		return false;
	}
}
bool LogInController::CheckUserName(string userName)
{
	cout << "Class LogInController ___ " << userInfo1.TakeUserID(userName) << " ___ Class LogInController " << endl;
	if (userInfo1.TakeUserID(userName) == "NOTHING") {
		return false;
	}
	else
	{
		return true;
	}
}
bool LogInController::CheckPassWord(string userName,string passWord)
{
	cout << "Class LogInController ___ " << userInfo1.TakeUserPassWord(userName) << " ___ Class LogInController " << endl;
	if (userInfo1.TakeUserPassWord(userName) == passWord) {
		return true;
	}
	else
	{
		return false;
	}
	
}

void LogInController::ChangeLogInStatus(std::string userID)
{
	userInfo1.ChangeLogInStatus(userID);


}

LogInController::LogInController()
{
}

LogInController::~LogInController()
{
}
