#define _CRT_SECURE_NO_WARNINGS
#include "AddFriendController.h"
using namespace std;
userInfo userInfo_AddfriendController;
AddFriendGUI AddFriendGUI__Controller;
UserMessInfo UserMessInfo_AddfriendController;

void AddFriendController::RequestAddFriend(string userID, string friendName)
{
	if (CheckFriendName(userID,friendName) == true/* && CheckFriendList(userID, friendName) == true*/) {
		time_t time_t_TimeAddFriend = time(0);
		// chuyen doi hientai thanh dang chuoi
		char* char_TimeAddFriend = ctime(&time_t_TimeAddFriend);
		string str_TimeAddFriend(char_TimeAddFriend);
		UserMessInfo_AddfriendController.RequestAddFriend(userID, userInfo_AddfriendController.TakeUserID(friendName), friendName, str_TimeAddFriend);

	}
	if(CheckFriendName(userID, friendName) != true){
		cout << "No have acc, Input Again!!!" << endl;
		AddFriendGUI__Controller.InputFriendUserName(userID);

	}

	/*if (CheckFriendList(userID, friendName) != true) {
		cout << "acc was your friend!!! please input different name :))" << endl;
		AddFriendGUI__Controller.InputFriendUserName(userID);
	}*/
	
}

bool AddFriendController::CheckFriendName(string userID,string friendName)
{
	//cout << "Class LogInController ___ " << userInfo_AddfriendController.TakeUserID(friendName) << " ___ Class LogInController " << endl;
	if (userInfo_AddfriendController.TakeUserID(friendName) == "NOTHING") {
		return false;
	}
	
	else
	{
		if (userInfo_AddfriendController.TakeUserID(friendName) == userID) {
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}
/*
bool AddFriendController::CheckFriendList(string userID,string friendName)
{
	if (userInfo_AddfriendController.TakeUserIDfromUserID(userID) != userInfo_AddfriendController.TakeUserID(friendName) {
		return false;
	}
	else {
		return true;
	}
}*/

AddFriendController::AddFriendController()
{
}


AddFriendController::~AddFriendController()
{
}
