#include "menu.h"
#include "SeenMessGUI.h"

using namespace std;

void menu::Displaymenu()
{
	LogInGUI LogInGUIMenu1;
	RegisterGUI RegisterGUIMenu1;

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
		//	cout << "please input again!!" << endl;
		Displaymenu();
	}
	if (choose != "1" && choose != "2") {

		exit(0);

	}
}



void menu::process(string userID)
{

	LogOutGUI LogOutGUIMenu1;
	RequestDislayMesswithFriendGUI RequestDislayMesswithFriendGUIMenu1;
	DisplayMessUserSentGUI DisplayDetailMessGUIMenu1;
	SentMessGUI SentMessGUIMenu1;
	AddFriendGUI AddFriendGUIMenu1;
	DisplayFriendListGUI DisplayFriendListGUIMenu1;
	BlockFriendGUI BlockFriendGUIMenu1;
	SeenMessGUI SeenMessGUIMenu1;
	int b=0;
	int n;
//	char key = getch();
//	int value = key;
	do {
	
/*		{
		case 2: {
			n = b;
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
				SeenMessGUIMenu1.RequestViewMess(userID);
				break;
			}
			case 8: {
				LogOutGUIMenu1.RequestLogOut(userID);
				break;
			}
			}


		}
		case 14: {*/
			cout << "your ID: " << userID << endl;
			cout << "please, choose: " << endl;
			cout << "press ctr+B to back view" << endl;
			cout << "press ctr+N to continue" << endl;
			cout << "0: exit" << endl;
			cout << "1: RequestDislayMesswithFriendGUI" << endl;
			cout << "2: DisplayDetailMessGUI" << endl;
			cout << "3: SentMessGUI" << endl;
			cout << "4: AddFriendGUI" << endl;
			cout << "5: DisplayFriendListGUI" << endl;
			cout << "6: BlockFriendGUI" << endl;
			cout << "7: see seen?" << endl;
			cout << "8: LogOut" << endl;
			//  char key = getch();
			//	int value = key;
			//	if (value == 14 || value != 2) {
			cin >> n;
			b = n;

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
				SeenMessGUIMenu1.RequestViewMess(userID);
				break;
			}
			case 8: {
				LogOutGUIMenu1.RequestLogOut(userID);
				break;
			}
			}
		//}
	//	}
	} while (n>0|| n<8);

}

void menu::Choose(string userID)
{
	int b;
	char key = getch();
	int value = key;
	do {
		switch (value)
		{


		case 2: {

		}

		case 14: {

		}
		}
	} while (value != 2 || value != 14);



}





menu::menu()
{
}


menu::~menu()
{
}

