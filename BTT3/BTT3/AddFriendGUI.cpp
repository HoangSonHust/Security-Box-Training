#include "AddFriendGUI.h"
AddFriendController AddFriendController_AddFriendGUI;
void AddFriendGUI::InputFriendUserName(string userID)
{
	cout << "input userName of friend" << endl;
	string friendName;
	cin >> friendName;
	AddFriendController_AddFriendGUI.RequestAddFriend(userID, friendName);

}

AddFriendGUI::AddFriendGUI()
{
}


AddFriendGUI::~AddFriendGUI()
{
}
