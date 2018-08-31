#pragma once
#include <string>
#include <iostream>
using namespace std;
class ManageFriendsInformationGUI
{
public:
	void RequestChangeFriendInfo(string userID);
	void ChangeInfo(string userID, int positionOfFriendList);
	
	ManageFriendsInformationGUI();
	~ManageFriendsInformationGUI();
};

