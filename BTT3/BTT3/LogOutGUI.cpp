#include "LogOutGUI.h"
#include <string>
#include "LogOutController.h"
using namespace std;
LogOutController LogOutController1;



void LogOutGUI::RequestLogOut(string userID)
{
	LogOutController1.RequestLogOut(userID);
}

LogOutGUI::LogOutGUI()
{
}


LogOutGUI::~LogOutGUI()
{
}
