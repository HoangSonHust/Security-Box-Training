#pragma once
#pragma warning(disable : 4996)
#include <conio.h>
#include <string>
#include <list>
using namespace std;
class DisplayFriendListGUI
{
public:
	void RequestFriendList(string userID);
	void DisplayFriendListForTimeSentMess(string userID);
	void DisplayFriendLisForCity(string userID);
	DisplayFriendListGUI();
	~DisplayFriendListGUI();
};

