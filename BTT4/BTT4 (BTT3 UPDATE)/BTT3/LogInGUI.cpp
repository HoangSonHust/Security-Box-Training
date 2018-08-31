#include "LogInGUI.h"
#include<iostream>
#include "userInfo.h"
#include "Menu.h"
#include "Controller.h"

using namespace std;
string LogInGUI::InputUserNameandPassword(string userName, string passWord)
{
	Controller Controller_GUI;
	menu menuLog;
	userInfo userInfo_LogInGUI;
	if (Controller_GUI.CheckInputUserNameAndPassWord(userName, passWord) == true) {
		return userInfo_LogInGUI.TakeUserID(userName);
	}
	else {
		cout << "LogIn NO sucsessfully, Input again!!!" << endl;
		menuLog.Displaymenu();
		return 0;
	}

}
LogInGUI::LogInGUI()
{
}


LogInGUI::~LogInGUI()
{
}
