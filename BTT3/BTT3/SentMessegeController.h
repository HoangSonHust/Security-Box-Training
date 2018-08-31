#pragma once
#include <string>
#include <iostream>
using namespace std;
class SentMessegeController
{
public:
	void SentMess(string userID, string friendName, string Mess);
	bool CheckFriend(string userID, string friendName);
	SentMessegeController();
	~SentMessegeController();
};

