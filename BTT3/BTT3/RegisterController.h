#pragma once
#include <string>
using namespace std;
class RegisterController
{
public:
	bool CheckPersonalInfo(string UserName,string FullName,string PassWord,string PassWordAgain,int DayOfBirth,int MonthOfBirth,int YearOfBirth,string Sex,string Address,string Other);
	bool CheckUserName(string userName);
	bool CheckPassWordAndPassWordAgain(string PassWord, string PassWordAgain);
	bool CheckDoB(int DayOfBirth, int MonthOfBirth, int YearOfBirth);

	
	RegisterController();
	~RegisterController();
};

