#include "DisplayDetailMessController.h"
#include "UserMessInfo.h"
UserMessInfo UserMessInfo_DisplayDetailMessController;



void DisplayDetailMessController::RequestDisplay(string userID, string messID)
{
	UserMessInfo_DisplayDetailMessController.RequestDisplayDetailMess(userID, messID);
}

DisplayDetailMessController::DisplayDetailMessController()
{
}


DisplayDetailMessController::~DisplayDetailMessController()
{
}
