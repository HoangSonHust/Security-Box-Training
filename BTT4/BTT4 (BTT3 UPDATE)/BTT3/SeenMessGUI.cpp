#include "SeenMessGUI.h"




void SeenMessGUI::RequestViewMess(string userID)
{
	Controller Controller_GUI;
	cout << "Here is mumber of mess that you have not seen!! : ";
	if (Controller_GUI.TakeMumberOfMess(userID) == "0") {
		cout << "0";
	}
	
	if (Controller_GUI.TakeMumberOfMess(userID) != "0") {
		cout << Controller_GUI.TakeMumberOfMess(userID) << endl;
		cout << "And these are friend that sent you mess: " << endl;
		Controller_GUI.TakeSenter(userID);
		list<string> lst = Controller_GUI.TakeSenter(userID);
		lst.unique();
		for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i) {
			cout << *i << endl;
		}
		cout << "please input ID of friend to see number of mess and ID of mess: ";
		string friendID;
		cin >> friendID;
		list<string> lst1 = Controller_GUI.TakeMessIDFromFriendIDHaveNotSeen(userID, friendID);
		for (list<string>::iterator a = lst1.begin(); a != lst1.end(); ++a) {
			cout << *a << endl;
		}
		cout << "please input mess ID: ";
		string messID;
		cin >> messID;
		cout << Controller_GUI.SeenMessThatHaveNotSeen(userID, friendID, messID) << endl;
		Controller_GUI.ChangeMessStatus(userID, friendID, messID);
	}
}

SeenMessGUI::SeenMessGUI()
{
}


SeenMessGUI::~SeenMessGUI()
{
}
