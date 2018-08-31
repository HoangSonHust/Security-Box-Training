#include "RequestDislayMesswithFriendGUI.h"
RequestDislayMesswithFriendController RequestDislayMesswithFriendController_RequestDislayMesswithFriendGUI1;
void RequestDislayMesswithFriendGUI::RequestDislayMesswithFriend(string userID)
{

	cout << "display mess with fr, input name of fr: " << endl;
	string friendName;
	cin >> friendName;
	RequestDislayMesswithFriendController_RequestDislayMesswithFriendGUI1.RequestDislayMesswithFriend(userID, friendName);
	//RequestDislayMesswithFriendGUIMenu1
	
}

RequestDislayMesswithFriendGUI::RequestDislayMesswithFriendGUI()
{
}


RequestDislayMesswithFriendGUI::~RequestDislayMesswithFriendGUI()
{
}
