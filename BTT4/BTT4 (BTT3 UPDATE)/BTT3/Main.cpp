#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include <iostream>
#include "Menu.h"
#include "userInfo.h"
#include "UserMessInfo.h"
#include "Controller.h"
#include "SeenMessGUI.h"
#include "SentMessGUI.h"
#include "RequestDislayMesswithFriendGUI.h"
#include "ManageFriendsInformationGUI.h"
#include "DisplayFriendListGUI.h"
#include <string>
#include <ctime>
#include <iostream>
#include "RegisterGUI.h"


using namespace std;
void main() {
	SentMessGUI SentMessGUITest;
	SeenMessGUI SeenMessGUItest;
	Controller Controller;
	UserMessInfo UserMessInfoTest;
	userInfo usertest;
	RequestDislayMesswithFriendGUI RequestDislayMesswithFriendGUItest;
	ManageFriendsInformationGUI ManageFriendsInformationGUItest;
	DisplayFriendListGUI DisplayFriendListGUItest;
	RegisterGUI RegisterGUItest;
	menu menu;
	//DisplayFriendListGUItest.RequestFriendList("1");
	menu.Displaymenu();
	//DisplayFriendListGUItest.DisplayFriendLisForCity("1");
//	Controller.DisplayFriendLisForCity("1");
	//UserMessInfoTest.TakeFriendIDforCity("1", "HN");
//	Controller.TakeFriendListIDUserSentMess("1");
	//Controller.TakeFriendListIDUserSentMess("1");
	//DisplayFriendListGUItest.RequestFriendList("1");
	
	//UserMessInfoTest.TakeFriendUserSentMess("1");
//	UserMessInfoTest.TakeFriendListSentMessToUser("1");
	//UserMessInfoTest.CheckHaveReceiver("1", "4");
	//UserMessInfoTest.TakeALLFriendIDlist("1");
//	RegisterGUItest.InputPersonalInfo();
	system("PAUSE");
}
