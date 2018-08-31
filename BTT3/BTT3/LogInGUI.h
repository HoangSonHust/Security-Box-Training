#pragma once
#include <string>
#include "LogInController.h"
using namespace std;
class LogInGUI
{
	LogInController logInController1;

private:
	std::string userName;
	std::string passWord;
	std::string userID;
public:
	std::string getUserID() {
		return userID;
	}
	void setUserID(std::string userID) {
		userID = userID;
	}
	std::string getUserName() {
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
	string InputUserNameandPassword(string userName, string passWord);

	LogInGUI();
	~LogInGUI();
};

