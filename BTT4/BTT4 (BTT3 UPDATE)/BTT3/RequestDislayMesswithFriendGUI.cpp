#include "RequestDislayMesswithFriendGUI.h"
#include "Controller.h"
#pragma warning(disable : 4996)
#include "SentMessGUI.h"
#include <conio.h>
#include <string>

void RequestDislayMesswithFriendGUI::RequestDislayMesswithFriend(string userID)
{
	Controller Controller_GUI;
	cout << "display mess with fr, input name of fr: " << endl;
	string friendName;
	cin >> friendName;
	Controller_GUI.RequestDislayMesswithFriend(userID, friendName);
	cout << "if you want to sent messege with this friend, press ctr+l!! " << endl;
	char key = getch();

	int value = key;

	if (value == 18) {
		cout << "input mess: ";
		string mess; 
		cin >> mess;
		cout << "ok!" << endl;
		Controller_GUI.SentMess(userID, friendName, mess);
	}
	
	
}

RequestDislayMesswithFriendGUI::RequestDislayMesswithFriendGUI()
{
}


RequestDislayMesswithFriendGUI::~RequestDislayMesswithFriendGUI()
{
}
