#include "LogOutGUI.h"
#include <string>
#include "Controller.h"
using namespace std;




void LogOutGUI::RequestLogOut(string userID)
{
	Controller Controller_GUI;
	Controller_GUI.RequestLogOut(userID);
}

LogOutGUI::LogOutGUI()
{
}


LogOutGUI::~LogOutGUI()
{
}
