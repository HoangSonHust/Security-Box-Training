#include "DisplayMessUserSentGUI.h"
#include "Controller.h"

void DisplayMessUserSentGUI::RequestDisplay(string userID)
{
	Controller Controller_GUI;
//	cout << "input messID: " << endl;
	//string messID;
	//cin >> messID;
	Controller_GUI.RequestDisplay(userID);
}

DisplayMessUserSentGUI::DisplayMessUserSentGUI()
{
}


DisplayMessUserSentGUI::~DisplayMessUserSentGUI()
{
}
