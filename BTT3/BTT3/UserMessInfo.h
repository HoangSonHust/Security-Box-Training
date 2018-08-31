#pragma once
#include <string>
using namespace std;
class UserMessInfo
{
private:
	string userID; 
	string friendID; 
	string friendStatus; 
	string TimeAddFriend; 
	string messID; 
	string TimeReceiverMess; 
	string Senter; 
	string Receiver; 
	string Mess;
public:
	//void CreatUserTable(string userID, string friendID, string friendStatus, string TimeAddFriend, string messID, string Time,string Senter, string Receiver, string Mess);
	void CreatUserTable(string userID);
	void RequestAddFriend(string userID, string friendID, string friendName, string TimeAddFriend);
	string RequestFriendList(string userID);
	void RequestBlockFriend(string userID,string friendID);
	void RequestSentMess(string userID, string friendID, string Mess, string TimeMess, string MessID);
	void RequestDisplayDetailMess(string userID, string messID);
	void RequestDislayMesswithFriend(string userID, string friendID);
	UserMessInfo();
	~UserMessInfo();
};

	
