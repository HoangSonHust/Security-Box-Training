#pragma once
#include <string>
#include <iostream>
#include "LogInGUI.h"
#include "RegisterGUI.h"
#include "LogOutGUI.h"
#include "RequestDislayMesswithFriendGUI.h"
#include "DisplayMessUserSentGUI.h"
#include "SentMessGUI.h"
#include "AddFriendGUI.h"
#include "DisplayFriendListGUI.h"
#include "BlockFriendGUI.h"
#include <string>
using namespace std;

class menu
{
public:
	void Displaymenu();
	void process(string userID);
	void Choose(string userID);
	menu();
	~menu();
};

