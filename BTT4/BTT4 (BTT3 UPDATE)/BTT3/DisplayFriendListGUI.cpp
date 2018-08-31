#include "DisplayFriendListGUI.h"
#include "Controller.h"
#include <iostream>

void DisplayFriendListGUI::RequestFriendList(string userID)
{
	Controller Controller_GUI;
	cout << "RequestFriendList" <<endl;
//	Controller_GUI.RequestFriendList(userID).unique();
	list<string> lst = Controller_GUI.RequestFriendList(userID);
	for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
	cout  << "friend list (no sort): "<< *i <<  endl;
	cout << "if you want to see friend list for timw of sentting messege, press ctr+t or ctr+c to see for city !! " << endl;
	char key = getch();
	int value = key;
	if (value == 20) { 
		DisplayFriendListForTimeSentMess(userID);
	}
	if (value == 3) {
		DisplayFriendLisForCity(userID);
	}
}

void DisplayFriendListGUI::DisplayFriendListForTimeSentMess(string userID)
{
	Controller Controller_GUI;
	
	list<string> lst_temp1=Controller_GUI.TakeFriendListIDUserSentMess(userID);
	for (list<string>::iterator i = lst_temp1.begin(); i != lst_temp1.end(); ++i)
	{
		cout << *i << endl;
	//	string friendID(*i);
		
	}

}

void DisplayFriendListGUI::DisplayFriendLisForCity(string userID)
{
	Controller Controller_GUI;
	list<string> lst_temp1 = Controller_GUI.DisplayFriendLisForCity(userID);
	for (list<string>::iterator i = lst_temp1.begin(); i != lst_temp1.end(); ++i)
	{
		cout << *i << endl;
	}

}


DisplayFriendListGUI::DisplayFriendListGUI()
{
}


DisplayFriendListGUI::~DisplayFriendListGUI()
{
}
