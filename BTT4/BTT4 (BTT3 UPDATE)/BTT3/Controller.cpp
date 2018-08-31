#define _CRT_SECURE_NO_WARNINGS
#include "Controller.h"
#include "BlockFriendGUI.h"
#include "RegisterGUI.h"
#include "SentMessGUI.h"
#include "AddFriendGUI.h"
SentMessGUI SentMessGUI_Controller;
RegisterGUI RegisterGUI_Controller;
BlockFriendGUI BlockFriendGUI_Contorller;
AddFriendGUI AddFriendGUI__Controller;
userInfo userInfo_Controller;
UserMessInfo UserMessInfo_Controller;
using namespace std;


bool Controller::CheckFriendList(string userID, string friendName)
{
	return false;
}
void Controller::RequestAddFriend(string userID, string friendName)
{
	if (CheckFriendNameToAddFriend(userID, friendName) == true) {
		time_t time_t_TimeAddFriend = time(0);
		// chuyen doi hientai thanh dang chuoi
		char* char_TimeAddFriend = ctime(&time_t_TimeAddFriend);
		string str_TimeAddFriend(char_TimeAddFriend);
		UserMessInfo_Controller.RequestAddFriend(userID, userInfo_Controller.TakeUserID(friendName), friendName, str_TimeAddFriend);
		UserMessInfo_Controller.RequestAddFriend(userInfo_Controller.TakeUserID(friendName), userID, userInfo_Controller.TakeNameFromID(userID), str_TimeAddFriend);

	}
	if (CheckFriendNameToAddFriend(userID, friendName) != true) {
		cout << "No have acc, Input Again!!!" << endl;
		AddFriendGUI__Controller.InputFriendUserName(userID);
	}
}

bool Controller::CheckFriendNameToAddFriend(string userID, string friendName)
{
	//cout << "Class LogInController ___ " << userInfo_AddfriendController.TakeUserID(friendName) << " ___ Class LogInController " << endl;
	if (userInfo_Controller.TakeUserID(friendName) == "NOTHING") {
		return false;
	}

	else
	{
		if (userInfo_Controller.TakeUserID(friendName) == userID) {
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}
void Controller::RequestBlockFriend(string userID, string friendName)
{

	if (CheckFriendName(userID, friendName) == true) {

		UserMessInfo_Controller.RequestBlockFriend(userID, userInfo_Controller.TakeUserID(friendName));

	}
	else {
		cout << "Input Again";
		BlockFriendGUI_Contorller.RequestBlockFriendGUI(userID);

	}
}

bool Controller::CheckFriendName(string userID, string friendName)
{

	if (userInfo_Controller.TakeUserID(friendName) == "NOTHING") {
		return false;
	}

	if (userInfo_Controller.TakeUserIDfromUserID(userID) != "NOTHING")
	{
		if (userInfo_Controller.TakeUserID(friendName) == userID) {
			return false;
		}
		else {
			return true;
		}
	}
}

void Controller::RequestDisplay(string userID)
{
	UserMessInfo_Controller.DisplayMessUserSentGUI(userID);
}

list<string> Controller::RequestFriendList(string userID)
{
	//UserMessInfo_Controller.TakeFriendList(userID).unique();
	/*list<string> lst = UserMessInfo_Controller.TakeFriendList(userID);
	for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
		cout << *i << endl;*/
	return UserMessInfo_Controller.TakeFriendList(userID);
}

list<string> Controller::TakeFriendListIDUserSentMess(string userID)
{
	list<string> MaxSecondSentMess;
	list<string> sortFriendID;
	list<string> sortFriendIDAndName;
	list<string> allFriendIDList = UserMessInfo_Controller.TakeALLFriendIDlist(userID);
	list<string> temp1 = UserMessInfo_Controller.TakeFriendListIDUserSentMess(userID);
	list<string> temp2 = UserMessInfo_Controller.TakeFriendListSentMessToUser(userID);
	temp1.unique();
	temp2.unique();
	temp1.merge(temp2);
	temp1.unique();
	list<string> lst = temp1;
	for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i) {

		string friendID(*i);
	
		MaxSecondSentMess.push_back(UserMessInfo_Controller.TakeSecondSentMess(userID, friendID));
	}
	MaxSecondSentMess.sort();
	MaxSecondSentMess.reverse();
	for (list<string>::iterator a = MaxSecondSentMess.begin(); a != MaxSecondSentMess.end(); ++a) {
	
		string seconds(*a);
	
		sortFriendID.push_back(UserMessInfo_Controller.takefriendIDFromTimeMaxSentMessFromSenter(userID, seconds));
	
		sortFriendID.push_back(UserMessInfo_Controller.takefriendIDFromTimeMaxSentMessFromReceiver(userID, seconds));
	   
	}
	
	sortFriendID.remove(userID);
	for (list<string>::iterator b = sortFriendID.begin(); b != sortFriendID.end(); ++b) {
	//	cout << *b << endl;
		string friendID(*b);
		allFriendIDList.remove(friendID);
		
	}
	for (list<string>::iterator c = allFriendIDList.begin(); c != allFriendIDList.end(); ++c) {
		//cout << *c << endl;
		string friendID1(*c);
		sortFriendID.push_back(friendID1);
	}
	for (list<string>::iterator d = sortFriendID.begin(); d != sortFriendID.end(); ++d) {
		//cout << *c << endl;
		string friendID1(*d);
		
		string FriendIDAndName = friendID1 +": "+ userInfo_Controller.TakeNameFromID(friendID1);
		sortFriendIDAndName.push_back(FriendIDAndName);
	}
		return sortFriendIDAndName;
	
}

list<string> Controller::DisplayFriendLisForCity(string userID)
{
	list<string> friendCity = UserMessInfo_Controller.TakeCityOfFriend(userID);
	list<string> cityAndFriendIDAndFriendName;
	//friendCity.sort();
	//friendCity.unique();
	for (list<string>::iterator a = friendCity.begin(); a != friendCity.end(); ++a) {
		//cout << *a << endl;
		string str_friendCity(*a);
		//cout << str_friendCity << endl;
		cityAndFriendIDAndFriendName.push_back(str_friendCity);
		list<string> friendIDFromCity=UserMessInfo_Controller.TakeFriendIDforCity(userID, str_friendCity);
		for (list<string>::iterator b = friendIDFromCity.begin(); b != friendIDFromCity.end(); ++b) {
		//	cout << *b << endl;
			string str_friendID(*b);
			string friendIDAndFriendName= "friendID: "+str_friendID+" and friendName: "+ userInfo_Controller.TakeNameFromID(str_friendID);
			cityAndFriendIDAndFriendName.push_back(friendIDAndFriendName);
		}
	}

	return cityAndFriendIDAndFriendName;
}

bool Controller::CheckInputUserNameAndPassWord(string userName, string passWord)
{
	if (CheckPassWord(userName, passWord) == CheckUserName(userName) == true) {
		///	userInfo_Controller.ChangeLogInStatus("1234567890");

		ChangeLogInStatus(userInfo_Controller.TakeUserID(userName));

		return true;
	}
	else
	{
		return false;
	}
}
bool Controller::CheckUserName(string userName)
{
	if (userInfo_Controller.TakeUserID(userName) == "NOTHING") {
		return false;
	}
	else
	{
		return true;
	}
}
bool Controller::CheckPassWord(string userName, string passWord)
{
	if (userInfo_Controller.TakeUserPassWord(userName) == passWord) {
		return true;
	}
	else
	{
		return false;
	}

}

void Controller::ChangeLogInStatus(std::string userID)
{
	userInfo_Controller.ChangeLogInStatus(userID);


}

void Controller::RequestLogOut(string userID)
{
	userInfo_Controller.ChangeLogOutStatus(userID);
}

bool Controller::CheckPersonalInfo(string UserName, string FullName, string PassWord, string PassWordAgain, int DayOfBirth, int MonthOfBirth, int YearOfBirth, string Sex, string Address, string Other)
{
	if (CheckUserNameToRegister(UserName) == CheckPassWordAndPassWordAgain(PassWord, PassWordAgain) == CheckDoB(DayOfBirth, MonthOfBirth, YearOfBirth) == true) {
		userInfo_Controller.TakeUserIDMAX();

		int intUserID;
		//chuyen string sang int
		intUserID = atoi(userInfo_Controller.TakeUserIDMAX().c_str());
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

		userInfo_Controller.UpdateNewUser(strUserID, UserName, FullName, PassWord, PassWordAgain, DoB, Sex, Address, Other);
		UserMessInfo_Controller.CreatUserTable(strUserID);
		return true;
	}
	else {
		cout << "sai";
		RegisterGUI_Controller.InputPersonalInfo();
		return false;
	}


	return false;
}

bool Controller::CheckUserNameToRegister(string userName)
{
	if (userInfo_Controller.TakeUserID(userName) == "NOTHING") {
		return true;
	}
	else {
		return false;
	}

}

bool Controller::CheckPassWordAndPassWordAgain(string PassWord, string PassWordAgain)
{
	if (PassWord == PassWordAgain) {
		return true;
	}
	else
		return false;
}

bool Controller::CheckDoB(int DayOfBirth, int MonthOfBirth, int YearOfBirth)
{
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


void Controller::RequestDislayMesswithFriend(string userID, string FriendName)
{
	UserMessInfo_Controller.RequestDislayMesswithFriend(userID, userInfo_Controller.TakeUserID(FriendName));

}



list<string> Controller::TakeFriendList(string userID)
{
	return UserMessInfo_Controller.TakeFriendList(userID);
}

string Controller::TakeFriendID(string userID, int int_Position)
{

	stringstream Position;//create a stringstream
	Position << int_Position;//add number to the stream
	return UserMessInfo_Controller.TakeFriendID(userID, Position.str());

}

string Controller::TakeNameFromID(string userID)
{
	return userInfo_Controller.TakeNameFromID(userID);
}

void Controller::SentMess(string userID, string friendName, string Mess)
{
	if (CheckFriend(userID, friendName) == true) {
		int int_MessID;
		string friendID = userInfo_Controller.TakeUserID(friendName);
		if (UserMessInfo_Controller.CheckHaveReceiver(userID, friendID) == "0") {
			int_MessID = 0;
		}
		else {
			int_MessID = atoi(UserMessInfo_Controller.TakeMessIDMax(userID, userID, friendID).c_str());
			//cout << int_MessID;
			int_MessID++;
		}
		std::stringstream sstrMessID;
		sstrMessID << int_MessID;
		string MessID = sstrMessID.str();
		time_t TimeSent_time_t = time(0);
		// chuyen doi hientai thanh dang chuoi
		char* TimeSent = ctime(&TimeSent_time_t);
		string strTimeSent(TimeSent);
		time_t Seconds_time_t = time(0);
		//cout << Seconds_t;
		// chuyen doi hientai thanh dang chuoi
		time_t timer;
		struct tm y2k = { 0 };
		int int_seconds;

		y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
		y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
		time(&timer);  /* get current time; same as: timer = time(NULL)  */
		int_seconds = difftime(timer, mktime(&y2k));
		auto str_seconds = std::to_string(int_seconds);
		UserMessInfo_Controller.RequestSentMess(userID, friendID, Mess, strTimeSent, MessID, str_seconds);

		//	UserMessInfo_Controller.UpdateSecondsSentMess(userID, friendID, MessID)
	}
	if (CheckFriend(userID, friendName) == false)
	{
		//cout << "no have account!!!" << endl;
		SentMessGUI_Controller.RequestSentMess(userID);
	}

}
bool Controller::CheckFriend(string userID, string friendName)
{
	if (userInfo_Controller.TakeUserIDfromUserID(userID) != "NOTHING") {
		return true;

	}
	else
	{
		return false;
	}
}


/*
*xem tin nhan da doc hay chua
*
*
*
*
*
*/
// lay so tin nhan chua doc 
string Controller::TakeMumberOfMess(string userID)
{
	if (UserMessInfo_Controller.CheckHaveMessHaveNotSeen(userID) == "0") {
		return UserMessInfo_Controller.CheckHaveMessHaveNotSeen(userID);
	}
	else {
		return UserMessInfo_Controller.TakeMumberOfMess(userID);
	}
}

list<string> Controller::TakeSenter(string userID)
{
	return UserMessInfo_Controller.TakeSenter(userID);
}


list<string> Controller::TakeMessIDFromFriendIDHaveNotSeen(string userID, string friendID)
{
	return UserMessInfo_Controller.TakeMessIDFromFriendIDHaveNotSeen(userID, friendID);
}

string Controller::SeenMessThatHaveNotSeen(string userID, string friendID, string messID)
{
	return UserMessInfo_Controller.SeenMessThatHaveNotSeen(userID, friendID, messID);
}

void Controller::ChangeMessStatus(string userID, string friendID, string messID)
{
	// thay doi mess status tai bang minhf
	UserMessInfo_Controller.ChangeSeenStatus(userID, friendID, messID);
	//thay doi mess status tai bang cua nguoi gui
//	UserMessInfo_Controller.ChangeSeenStatus(friendID, friendID, messID);
}

void Controller::ChangeFriendInfo(string userID, string positionOfFriendList)
{
}

void Controller::ChangeFriendDoB(string userID, string friendID, int DayOfBirth, int MonthOfBirth, int YearOfBirth)
{
	stringstream sstrDay;
	sstrDay << DayOfBirth;
	string strDay = sstrDay.str();

	stringstream sstrMonth;
	sstrMonth << MonthOfBirth;
	string strMonth = sstrMonth.str();

	stringstream sstrYear;
	sstrYear << YearOfBirth;
	string strYear = sstrYear.str();

	string newDoB = strDay + "/" + strMonth + "/" + strYear;
	userInfo_Controller.ChangeFriendDoB(userID, friendID, newDoB);
}

void Controller::ChangeFriendGender(string userID, string friendID, string newGender)
{
	userInfo_Controller.ChangeFriendGender(userID, friendID, newGender);
}

void Controller::ChangeFriendAddress(string userID, string friendID, string newAddress)
{
	userInfo_Controller.ChangeFriendAddress(userID, friendID, newAddress);
}

Controller::Controller()
{
}

Controller::~Controller()
{
}
