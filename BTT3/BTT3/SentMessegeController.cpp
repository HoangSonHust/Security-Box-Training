#define _CRT_SECURE_NO_WARNINGS
#include "SentMessegeController.h"
#include <ctime>
#include <sstream>
#include <string>
#include "userInfo.h"
#include "UserMessInfo.h"
#include "SentMessGUI.h"
SentMessGUI SentMessGUIcontroller;
UserMessInfo UserMessInfo_SentMessController;
userInfo userInfo_SentMessController;



void SentMessegeController::SentMess(string userID, string friendName, string Mess)
{
	if (CheckFriend(userID, friendName) == true) {
		string MessID;
		MessID = "V" + userInfo_SentMessController.TakeUserID(friendName);
		time_t TimeSent_time_t = time(0);

		// chuyen doi hientai thanh dang chuoi
		char* TimeSent = ctime(&TimeSent_time_t);
		string strTimeSent(TimeSent);
		/*stringstream ss;
		ss << TimeSent;
		ss >> strTimeSent;

		{
			time_t time_t_TimeAddFriend = time(0);
			// chuyen doi hientai thanh dang chuoi
			char* char_TimeAddFriend = ctime(&time_t_TimeAddFriend);
			string str_TimeAddFriend(char_TimeAddFriend);

		}*/
		UserMessInfo_SentMessController.RequestSentMess(userID, userInfo_SentMessController.TakeUserID(friendName),Mess, strTimeSent,MessID);
	}
	if (CheckFriend(userID, friendName) == false)
	{
		cout << "no have account!!!" << endl;
		SentMessGUIcontroller.RequestSentMess(userID);
	}

}

bool SentMessegeController::CheckFriend(string userID, string friendName)
{
	if (userInfo_SentMessController.TakeUserIDfromUserID(userID) != "NOTHING") {
		return true;

	}
	else
	{
		return false;
	}
}
SentMessegeController::SentMessegeController()
{
}


SentMessegeController::~SentMessegeController()
{
}
