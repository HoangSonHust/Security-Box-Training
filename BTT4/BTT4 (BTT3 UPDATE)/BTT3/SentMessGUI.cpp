#pragma warning(disable : 4996)
#include "SentMessGUI.h"
#include <conio.h>
#include <string>
//#include <iostream>
#define CTRL 12;



void SentMessGUI::RequestSentMess(string userID)
{
	Controller Controller_GUI;
	string friendName;
	string Mess;
	int Choose;
	cout << "input 0 to input your friend's name or 1 to press ctr+l to show list " << endl;
	cin >> Choose;
	if (Choose == 0) {
		cout << "Input userName of friend" << endl;
		cin >> friendName;
		cout << "Input Mess" << endl;
		cin >> Mess;
		Controller_GUI.SentMess(userID, friendName, Mess);
	}
	if (Choose == 1) {
		cout << "press ctr+l to show friend list!" << endl;
		flushall();
		char key = getch();
		int value = key;
		if (value == 12) {
			//Controller_GUI.TakeFriendList(userID);
			list<string> lst = Controller_GUI.TakeFriendList(userID);
			for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
				cout << *i << endl;
			int Position;
			cout << "in put position from friend list" << endl;
			cin >> Position;
			cout << "to: " << Controller_GUI.TakeNameFromID(Controller_GUI.TakeFriendID(userID, Position)) << endl;
			cout << "Input Mess" << endl;
			cin >> Mess;
			Controller_GUI.SentMess(userID, Controller_GUI.TakeNameFromID(Controller_GUI.TakeFriendID(userID, Position)), Mess);
			cout << "do you want to see detail messege with this friend? preess 1 " << endl;
			int Choose1;
			cin >> Choose1;
			if (Choose1 == 1) {
				Controller_GUI.RequestDislayMesswithFriend(userID, Controller_GUI.TakeNameFromID(Controller_GUI.TakeFriendID(userID, Position)));
				cout << "if you want to sent ";
			}
		}
		if (value != 12) {
			cout << "input wrong!!(12)" << endl;
			RequestSentMess(userID);
		}
	}
	if (Choose != 0 && Choose != 1) {
		cout << "input wrong!!" << endl;
		RequestSentMess(userID);
	}


}


SentMessGUI::SentMessGUI()
{
}


SentMessGUI::~SentMessGUI()
{
}
