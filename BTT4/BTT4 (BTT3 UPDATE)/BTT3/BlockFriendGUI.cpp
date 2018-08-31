#include <iostream>
#include "BlockFriendGUI.h"
#include "Controller.h"


void BlockFriendGUI::RequestBlockFriendGUI(string userID)
{
	Controller Controller_GUI;
	cout << "Input UserName of friend, you want to block" << endl;
	string friendName;
	cin >> friendName;
	Controller_GUI.RequestBlockFriend(userID, friendName);
}

BlockFriendGUI::BlockFriendGUI()
{
}


BlockFriendGUI::~BlockFriendGUI()
{
}
