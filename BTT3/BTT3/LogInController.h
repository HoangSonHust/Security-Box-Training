#pragma once
#include<iostream>
#include <string>
class LogInController
{
private:
	std::string userName;
	std::string passWord;
public:
	
	std::string getuserName() {
		return userName;
	}
	void setuserName(std::string userName) {
		userName = userName;
	}
	std::string getpassWord() {
		return passWord;
	}
	void setpassWord(std::string passWord) {
		passWord = passWord;
	}
	bool CheckInputUserNameAndPassWord(std::string userName, std::string passWord);
	bool CheckUserName(std::string userName);
	bool CheckPassWord(std::string userName, std::string passWord);
	void ChangeLogInStatus(std::string userID);
	LogInController();
	~LogInController();
};

