#include "LogOutController.h"
#include "userInfo.h"
userInfo userInfo3;

void LogOutController::RequestLogOut(string userID)
{
	userInfo3.ChangeLogOutStatus(userID);
}

LogOutController::LogOutController()
{
}


LogOutController::~LogOutController()
{
}
