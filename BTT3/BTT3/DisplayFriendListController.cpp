#include "DisplayFriendListController.h"
#include "UserMessInfo.h"
UserMessInfo UserMessInfo_DisplayFriendListController;
string DisplayFriendListController::RequestFriendList(string userID)
{
	return UserMessInfo_DisplayFriendListController.RequestFriendList(userID);
}

DisplayFriendListController::DisplayFriendListController()
{
}


DisplayFriendListController::~DisplayFriendListController()
{
}
