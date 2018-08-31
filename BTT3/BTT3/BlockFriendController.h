#pragma once
#include <string>
using namespace std;
class BlockFriendController
{
public:
	void RequestBlockFriend(string userID, string FriendName);
	bool CheckFriendName(string userID, string friendName);
	BlockFriendController();
	~BlockFriendController();
};

