#include "AddFriendGUI.h"
#include "Controller.h"

void AddFriendGUI::InputFriendUserName(string userID)
{
	Controller Controller_GUI;
	cout << "input userName of friend" << endl;
	string friendName;
	cin >> friendName;
	Controller_GUI.RequestAddFriend(userID, friendName);
}

AddFriendGUI::AddFriendGUI()
{
}
AddFriendGUI::~AddFriendGUI()
{
}
