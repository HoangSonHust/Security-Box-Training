#include "LogInGUI.h"
#include<iostream>
#include "userInfo.h"
#include "Menu.h"
menu menuLog;
userInfo userInfo_LogInGUI;
using namespace std;
string LogInGUI::InputUserNameandPassword(string userName, string passWord)
{

	if (logInController1.CheckInputUserNameAndPassWord(userName, passWord) == true) {
		//	cout << "LogIn sucsessfully!!!" << endl;
		//	cout << userInfo_LogInGUI.TakeUserID(userName);
		//	setUserID(userInfo_LogInGUI.TakeUserID(userName));
		return userInfo_LogInGUI.TakeUserID(userName);
	}
	else {
		cout << "LogIn NO sucsessfully, Input again!!!" << endl;
		menuLog.Displaymenu();
		return 0;
	}

}

/*string LogInGUI::InputUserNameandPassword(string a)
{
std::cout << "moi ban nhap userName: \n";
std::cin >> userName;
std::cout << "moi ban nhap passWord: \n";
std::cin >> passWord;
if (logInController1.CheckInputUserNameAndPassWord(userName, passWord) == true) {
//	cout << "LogIn sucsessfully!!!" << endl;

return userInfo_LogInGUI.TakeUserID(userName);
}
else {
cout << "LogIn NO sucsessfully, Input again!!!" << endl;
InputUserNameandPassword(1);
return 0;
}
}
*/


LogInGUI::LogInGUI()
{
}


LogInGUI::~LogInGUI()
{
}
