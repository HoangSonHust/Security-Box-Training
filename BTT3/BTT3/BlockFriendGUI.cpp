#include <iostream>
#include "BlockFriendGUI.h"
#include "BlockFriendController.h"
BlockFriendController BlockGUI;

void BlockFriendGUI::RequestBlockFriendGUI(string userID)
{
	cout << "Input UserName of friend, you want to block" << endl;
	string friendName;
	cin >> friendName;
	//BlockFriendController_BlockFriendGUI.RequestBlockFriend(userID, friendName);
	//BlockFriendControllerRequestBlockFriend(userID, friendName);
	BlockGUI.RequestBlockFriend(userID, friendName);
}

BlockFriendGUI::BlockFriendGUI()
{
}


BlockFriendGUI::~BlockFriendGUI()
{
}
