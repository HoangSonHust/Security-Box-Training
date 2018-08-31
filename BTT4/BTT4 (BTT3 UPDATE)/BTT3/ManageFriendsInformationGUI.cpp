#include "ManageFriendsInformationGUI.h"
#include "Controller.h"
#pragma warning(disable : 4996)
#include "SentMessGUI.h"
#include <conio.h>
#include <string>


void ManageFriendsInformationGUI::RequestChangeFriendInfo(string userID)
{
	Controller Controller_GUI;
	cout << "welcome to change friend's info GUI!! " << endl;
	cout << "press ctr+l to show friend list!" << endl;

	char key = getch();

	int value = key;

	if (value == 12) {
		//	Controller_GUI.TakeFriendList(userID);
		list<string> lst = Controller_GUI.TakeFriendList(userID);
		for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
			cout << *i << endl;
		int positionOfFriendList;
		cout << "in put position from friend list" << endl;
		cin >> positionOfFriendList;
		ChangeInfo(userID, positionOfFriendList);
	}
}

void ManageFriendsInformationGUI::ChangeInfo(string userID, int positionOfFriendList)
{
	Controller Controller_GUI;
	string friendID=Controller_GUI.TakeFriendID(userID, positionOfFriendList);
	cout << "you can change Gender, DoB, Address press 1 to change Gender, 2 to change DoB and 3 to change Address or 4 to exit!!" << endl;
	int choose;
	cin >> choose;
	if (choose == 1) {

		string newGender;
		cout << "in change GenderInput Gender, if Input is 0, sex will be male, is 1 sex will be female, is 2 sex will be orther and is not 0,1 or2 sex will be Orther " << endl;
		int choose;
		cin >> choose;
		if (choose == 0) {
			newGender = "male";
		}
		if (choose == 1) {
			newGender = "female";
		}
		if (choose == 2) {
			newGender = "Orther";
		}
		if (choose != 0 && choose != 1 && choose != 2) {
			newGender = "Orther";
		}
		cout << "you change to " << newGender << endl;
		Controller_GUI.ChangeFriendGender(userID, friendID, newGender);
		cout << "ok" << endl;
		ChangeInfo(userID, positionOfFriendList);

	}
	if (choose == 2) {
		cout << "in change DoB, input new DoB" << endl;
		int DayOfBirth;
		int MonthOfBirth;
		int YearOfBirth;
		cout << "Input day of birth" << endl;
		cin >> DayOfBirth;
		cout << "Input month of birth" << endl;
		cin >> MonthOfBirth;
		cout << "Input year of birth" << endl;
		cin >> YearOfBirth;
		if (Controller_GUI.CheckDoB(DayOfBirth, MonthOfBirth, YearOfBirth) == true) {
			Controller_GUI.ChangeFriendDoB(userID, friendID, DayOfBirth, MonthOfBirth, YearOfBirth);
			ChangeInfo(userID, positionOfFriendList);
		}
		else {
			cout << "input wrong!! " << endl;
			ChangeInfo(userID, positionOfFriendList);
		}
	}
	if (choose == 3) {
		cout << "in change Address, Input new Address" << endl;
		string newAddress;
		cin >> newAddress;
		Controller_GUI.ChangeFriendAddress(userID, friendID, newAddress);
		cout << "ok" << endl;
		ChangeInfo(userID, positionOfFriendList);
	}
	if (choose == 4) {
		exit(0);
	}
	if (choose != 1 || choose != 2 || choose != 3) {
		cout << "input wrong!! " << endl;
		ChangeInfo(userID, positionOfFriendList);
	}
}

ManageFriendsInformationGUI::ManageFriendsInformationGUI()
{
}


ManageFriendsInformationGUI::~ManageFriendsInformationGUI()
{
}
