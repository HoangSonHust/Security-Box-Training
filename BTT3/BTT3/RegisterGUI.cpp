#include "RegisterGUI.h"
#include <string>
#include <iostream>
#include "RegisterController.h"
using namespace std;
RegisterController RegisterController1;
void RegisterGUI::InputPersonalInfo()
{
	cout << "welcom to register GUI " << endl;
	cout << "Input userName" << endl;
	cin >> UserName;
	cout << "Input full name" << endl;
	cin >> FullName;
	cout << "Input passWord" << endl;
	cin >> PassWord;
	cout << "Input passWord again" << endl;
	cin >> PassWordAgain;
	cout << "Input day of birth" << endl;
	cin >> DayOfBirth;
	cout << "Input month of birth" << endl;
	cin >> MonthOfBirth;

	cout << "Input year of birth" << endl;
	cin >> YearOfBirth;
	cout << "Input Sex, if Input is 0, sex will be male, is 1 sex will be female, is 2 sex will be orther and is not 0,1 or2 sex will be Orther " << endl;
	int choose;
	cin >> choose;
	if (choose == 0) {
		Sex = "male";
	}
	if (choose == 1) {
		Sex = "female";
	}
	if (choose == 2) {
		Sex = "Orther";
	}
	if (choose != 0 && choose != 1 && choose != 2) {
		Sex = "Orther";
	}
	cout << "Input Address" << endl;
	cin >> Address;
	cout << "Input Orther" << endl;
	cin >> Other;
	RegisterController1.CheckPersonalInfo(UserName, FullName,PassWord, PassWordAgain, DayOfBirth, MonthOfBirth, YearOfBirth, Sex, Address, Other);
}

RegisterGUI::RegisterGUI()
{
}


RegisterGUI::~RegisterGUI()
{
}
