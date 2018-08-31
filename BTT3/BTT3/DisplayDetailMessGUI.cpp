#include "DisplayDetailMessGUI.h"
DisplayDetailMessController DisplayDetailMessController__DisplayDetailMessGUI;

void DisplayDetailMessGUI::RequestDisplay(string userID)
{
	cout << "input messID: " << endl;
	string messID;
	cin >> messID;
	DisplayDetailMessController__DisplayDetailMessGUI.RequestDisplay(userID, messID);
}

DisplayDetailMessGUI::DisplayDetailMessGUI()
{
}


DisplayDetailMessGUI::~DisplayDetailMessGUI()
{
}
