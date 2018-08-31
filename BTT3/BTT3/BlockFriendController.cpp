#include "BlockFriendController.h"
#include "userInfo.h"
#include "BlockFriendGUI.h"
#include "UserMessInfo.h"
userInfo userInfo_BlockFriendController;
BlockFriendGUI BlockFriendGUI_BlockFriendController;
UserMessInfo UserMessInfo_BlockFriendController;

void BlockFriendController::RequestBlockFriend(string userID, string friendName)
{

	if (CheckFriendName(userID, friendName) == true) {

		UserMessInfo_BlockFriendController.RequestBlockFriend(userID, userInfo_BlockFriendController.TakeUserID(friendName));

	}
	else {
		cout << "Input Again";
		BlockFriendGUI_BlockFriendController.RequestBlockFriendGUI(userID);

	}
}

bool BlockFriendController::CheckFriendName(string userID, string friendName)
{
	//cout << "Class LogInController ___ " << userInfo_AddfriendController.TakeUserID(friendName) << " ___ Class LogInController " << endl;
	if (userInfo_BlockFriendController.TakeUserID(friendName) == "NOTHING") {
		return false;
	}

	if (userInfo_BlockFriendController.TakeUserIDfromUserID(userID) != "NOTHING")
	{
		if (userInfo_BlockFriendController.TakeUserID(friendName) == userID) {
			return false;
		}
		else {
			return true;
		}
	}
	
}

  

BlockFriendController::BlockFriendController()
{
}


BlockFriendController::~BlockFriendController()
{
}
