#pragma once
#include <string>
#include <ctime>
#include "UserMessInfo.h"
#include <iostream>
#include "userInfo.h"
#include "AddFriendGUI.h"

using namespace std;
class AddFriendController
{
public:
	void RequestAddFriend(string userID, string friendName);
	bool CheckFriendName(string userID,string friendName);
	bool CheckFriendList(string userID,string friendName);
	AddFriendController();
	~AddFriendController();
};

