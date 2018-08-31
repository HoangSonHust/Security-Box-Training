#pragma once
#include <string>
#include <list>
#include <iterator>
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
	void RequestSentMess(string userID, string friendID, string Mess, string TimeMess, string MessID, string Seconds);
	
	//void RequestRecieverMess(string userID, string friendID, string Mess, string TimeMess, string MessID);
	void DisplayMessUserSentGUI(string userID);
	void RequestDislayMesswithFriend(string userID, string friendID);
	string TakeMessIDMax(string userID,string Senter, string Receiver);
	string CheckHaveMessHaveNotSeen(string userID);
	string TakeMumberOfMess(string userID);
	string CheckHaveReceiver(string userID, string ReveiverID);
	list<string> TakeSenter(string userID);
	list<string> TakeMessIDFromFriendIDHaveNotSeen(string userID, string friendID);
	string SeenMessThatHaveNotSeen(string userID, string friendID, string messID);
	void ChangeSeenStatus(string userID, string friendID, string messID);
	list<string> TakeFriendList(string userID);
	list<string> TakeFriendListIDUserSentMess(string userID);
	list<string> TakeFriendListSentMessToUser(string userID);
	string TakeSecondSentMess(string userID, string friendID);
	string takefriendIDFromTimeMaxSentMessFromSenter(string userID, string Second);
	string takefriendIDFromTimeMaxSentMessFromReceiver(string userID, string Second);
	list<string> TakeALLFriendIDlist(string userID);
	list<string> TakeCityOfFriend(string userID);
	list<string> TakeFriendIDforCity(string userID,string Address);
	string TakeFriendID(string userID, string Position);
	UserMessInfo();
	~UserMessInfo();
};

	
