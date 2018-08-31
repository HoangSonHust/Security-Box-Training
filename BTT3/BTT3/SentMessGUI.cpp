#include "SentMessGUI.h"
#include <iostream>
#include "SentMessegeController.h"
SentMessegeController SentMessegeController_SentMessGUI;


void SentMessGUI::RequestSentMess(string userID)
{
	string friendName;
	string Mess;
	cout << "Input userName of friend" << endl;
	cin >> friendName;
	cout << "Input Mess" << endl;
	cin >> Mess;
	SentMessegeController_SentMessGUI.SentMess(userID, friendName, Mess);

}

SentMessGUI::SentMessGUI()
{
}


SentMessGUI::~SentMessGUI()
{
}
