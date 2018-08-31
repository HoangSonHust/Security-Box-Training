#include "DisplayFriendListGUI.h"
#include <iostream>
DisplayFriendListController DisplayFriendListControllerGUI;
void DisplayFriendListGUI::RequestFriendList(string userID)
{
	cout << "RequestFriendList" <<endl;
	DisplayFriendListControllerGUI.RequestFriendList(userID);
}

DisplayFriendListGUI::DisplayFriendListGUI()
{
}


DisplayFriendListGUI::~DisplayFriendListGUI()
{
}
