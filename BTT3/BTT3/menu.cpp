#include "menu.h"
#include <string>
#include <iostream>
#include "LogInGUI.h"
#include "RegisterGUI.h"
#include "LogOutGUI.h"
#include "RequestDislayMesswithFriendGUI.h"
#include "DisplayDetailMessGUI.h"
#include "SentMessGUI.h"
#include "AddFriendGUI.h"
#include "DisplayFriendListGUI.h"
#include "BlockFriendGUI.h"
LogInGUI LogInGUIMenu1;
RegisterGUI RegisterGUIMenu1;
LogOutGUI LogOutGUIMenu1;
RequestDislayMesswithFriendGUI RequestDislayMesswithFriendGUIMenu1;
DisplayDetailMessGUI DisplayDetailMessGUIMenu1;
SentMessGUI SentMessGUIMenu1;
AddFriendGUI AddFriendGUIMenu1;
DisplayFriendListGUI DisplayFriendListGUIMenu1;
BlockFriendGUI BlockFriendGUIMenu1;
using namespace std;

void menu::Displaymenu()
{
	cout << "Hello and Welcom to my project" << endl;
	cout << "if you have account, plesase input 1 and input 2 if you want to register account :)) if input differ 1 or 2 program will be out " << endl;
	//	system("PAUSE");

	string choose;
	cin >> choose;
	if (choose == "1") {
		string userName;
		string passWord;
		std::cout << "moi ban nhap userName: \n";
		std::cin >> userName;
		std::cout << "moi ban nhap passWord: \n";
		std::cin >> passWord;
		if (LogInGUIMenu1.InputUserNameandPassword(userName, passWord) != "NOTHING") {
			process(LogInGUIMenu1.InputUserNameandPassword(userName, passWord));
		}
		else {
			cout << "no have account!!!, please input again!!" << endl;
			Displaymenu();
		}

		//	process(LogInGUIMian.InputUserNameandPassword());
	}if (choose == "2") {
		RegisterGUIMenu1.InputPersonalInfo();
		cout << "please input again!!" << endl;
		Displaymenu();
	}
	if (choose != "1" && choose != "2") {

		exit(0);

	}
}

void menu::process(string userID) {
	cout << "your ID is " << userID << endl;

	int n;
	do {
		cout << "your ID: " << userID << endl;
		cout << "please, choose: " << endl;
		cout << "0: exit" << endl;
		cout << "1: RequestDislayMesswithFriendGUI" << endl;
		cout << "2: DisplayDetailMessGUI" << endl;
		cout << "3: SentMessGUI" << endl;
		cout << "4: AddFriendGUI" << endl;
		cout << "5: DisplayFriendListGUI" << endl;
		cout << "6: BlockFriendGUI" << endl;
		cout << "7: LogOut" << endl;
		cin >> n;
		switch (n)
		{
		case 0: {
			exit(0);
		}
		case 1: {
			RequestDislayMesswithFriendGUIMenu1.RequestDislayMesswithFriend(userID);
			break;
		}
		case 2: {
			DisplayDetailMessGUIMenu1.RequestDisplay(userID);
			break;
		}
		case 3: {
			SentMessGUIMenu1.RequestSentMess(userID);
			break;
		}
		case 4: {
			AddFriendGUIMenu1.InputFriendUserName(userID);
			break;
		}
		case 5: {
			DisplayFriendListGUIMenu1.RequestFriendList(userID);
			break;
		}
		case 6: {
			BlockFriendGUIMenu1.RequestBlockFriendGUI(userID);
			break;
		}
		case 7: {
			LogOutGUIMenu1.RequestLogOut(userID);
			break;

		}

		}


	} while (n > 0 || n <7);



}


menu::menu()
{
}


menu::~menu()
{
}
