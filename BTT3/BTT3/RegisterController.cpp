#include "RegisterController.h"
#include <sstream>
#include "userInfo.h"
#include "RegisterGUI.h"
#include "UserMessInfo.h"
userInfo userInfoRegiserController;
UserMessInfo UserMessInfoRegister;
RegisterGUI RegisterGUI_RegisterController;
bool RegisterController::CheckPersonalInfo(string UserName, string FullName, string PassWord, string PassWordAgain, int DayOfBirth, int MonthOfBirth, int YearOfBirth, string Sex, string Address, string Other)
{
	if (CheckUserName(UserName) == CheckPassWordAndPassWordAgain(PassWord, PassWordAgain) == CheckDoB(DayOfBirth, MonthOfBirth, YearOfBirth) == true) {
		userInfoRegiserController.TakeUserIDMAX();
	
		int intUserID;
		//chuyen string sang int
		intUserID = atoi(userInfoRegiserController.TakeUserIDMAX().c_str());
		intUserID++;
		// chuyen int sang string
		std::stringstream sstrUserID;
		sstrUserID << intUserID;
		std::string strUserID = sstrUserID.str();
		//
		stringstream sstrDay;
		sstrDay << DayOfBirth;
		string strDay = sstrDay.str();

		stringstream sstrMonth;
		sstrMonth << MonthOfBirth;
		string strMonth = sstrMonth.str();

		stringstream sstrYear;
		sstrYear << YearOfBirth;
		string strYear = sstrYear.str();

		string DoB = strDay + "/" + strMonth + "/" + strYear;

		userInfoRegiserController.UpdateNewUser(strUserID, UserName, FullName, PassWord, PassWordAgain, DoB, Sex, Address, Other);
		UserMessInfoRegister.CreatUserTable(strUserID);
		return true;
	}
	else {
		cout << "sai";
		RegisterGUI_RegisterController.InputPersonalInfo();
		return false;
	}


	return false;
}

bool RegisterController::CheckUserName(string userName)
{
	if (userInfoRegiserController.TakeUserID(userName) == "NOTHING") {
		return true;
	}
	else {
		return false;
	}


}

bool RegisterController::CheckPassWordAndPassWordAgain(string PassWord, string PassWordAgain)
{
	if (PassWord == PassWordAgain) {
		return true;
	}
	else
		return false;
}

bool RegisterController::CheckDoB(int DayOfBirth, int MonthOfBirth, int YearOfBirth)
{
	/*int NamNhuan;
	if (YearOfBirth % 4 == 0 && YearOfBirth % 100 != 0 || YearOfBirth % 400 == 0)
	{
		NamNhuan = 1;
	}
	else
	{
		NamNhuan = 0;
	}

	int CheckMonth = 0;
	if (MonthOfBirth == 1 || MonthOfBirth == 3 || MonthOfBirth == 5 || MonthOfBirth == 7 || MonthOfBirth == 8 || MonthOfBirth == 10 || MonthOfBirth == 12) {
		if (DayOfBirth <= 31) {

			CheckMonth = 1;
		}

		if (DayOfBirth > 31) {

			CheckMonth = 0;
		}
	}

	if (MonthOfBirth == 4 || MonthOfBirth == 6 || MonthOfBirth == 9 || MonthOfBirth == 10 || MonthOfBirth == 11) {
		if (DayOfBirth <= 30) {

			CheckMonth = 1;
		}
		if (DayOfBirth > 30) {

			CheckMonth = 0;
		}
	}


	if (MonthOfBirth == 2) {
		if (DayOfBirth <= 29 && NamNhuan == 1) {
			CheckMonth = 1;
		}
		if (DayOfBirth <= 28 && NamNhuan == 0) {
			CheckMonth = 1;
		}

		if ((DayOfBirth > 29) && (NamNhuan == 1 || NamNhuan == 0)) {

			CheckMonth = 0;
		}
	}
	if (CheckMonth == 0) {
		return false;
	}
	if (CheckMonth == 1 && NamNhuan == 1) {
		return true;
	}
	if (CheckMonth == 1 && NamNhuan == 0) {
		return true;
	}*/

	int ngaymax;
	if (YearOfBirth < 0 || MonthOfBirth < 0 || MonthOfBirth> 12 || DayOfBirth < 0 || DayOfBirth> 31)
	{
		return false;
	}
	else
	{
		switch (MonthOfBirth)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			ngaymax = 31;
			break;
		case 2:
			if ((YearOfBirth % 4 == 0 && YearOfBirth % 100 != 0) || (YearOfBirth % 400 == 0))
				ngaymax = 29;
			else
				ngaymax = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			ngaymax = 30;
			break;
		}
		if (DayOfBirth <= ngaymax)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

RegisterController::RegisterController()
{
}


RegisterController::~RegisterController()
{
}
