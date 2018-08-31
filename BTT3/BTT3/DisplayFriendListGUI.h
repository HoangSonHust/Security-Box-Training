#pragma once
#include "DisplayFriendListController.h"
#include <string>
using namespace std;
class DisplayFriendListGUI
{
public:
	void RequestFriendList(string userID);
	DisplayFriendListGUI();
	~DisplayFriendListGUI();
};

