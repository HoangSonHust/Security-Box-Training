#pragma once
#include<iostream>
#include <string>
using namespace std;
class RegisterGUI
{
private:
	string UserName;
	string PassWord;
	string PassWordAgain;
	string FullName;
	int DayOfBirth;
	int MonthOfBirth;
	int YearOfBirth;
	string Sex;
	string Address;
	string Other;


public:
	string getUserName()
	{
		return UserName;
	}
	void setUserName(string UserName) //setter
	{
		UserName = UserName;

	}

	string getFullName()
	{
		return FullName;
	}
	void setFullName(string FullName) //setter
	{
		FullName = FullName;

	}

	string getPassWord()
	{
		return PassWord;
	}
	void setPassWord(string PassWord) //setter
	{
		PassWord = PassWord;

	}

	string getPassWordAgain()
	{
		return PassWordAgain;
	}
	void setPassWordAgain(string PassWordAgain) //setter
	{
		PassWordAgain = PassWordAgain;

	}


	int getDayOfBirth()
	{
		return DayOfBirth;
	}
	void setDayOfBirth(int DayOfBirth) //setter
	{
		DayOfBirth = DayOfBirth;

	}

	int getMonthOfBirth()
	{
		return MonthOfBirth;
	}
	void setMonthOfBirth(int MonthOfBirth) //setter
	{
		MonthOfBirth = MonthOfBirth;

	}

	int getYearOfBirth()
	{
		return YearOfBirth;
	}
	void setYearOfBirth(int YearOfBirth) //setter
	{
		YearOfBirth = YearOfBirth;

	}

	string getSex()
	{
		return Sex;
	}
	void setSex(string Sex) //setter
	{
		Sex = Sex;

	}

	string getAddress()
	{
		return Address;
	}
	void setAddress(string Address) //setter
	{
		Address = Address;

	}

	string getOther()
	{
		return Other;
	}
	void setOther(string Other) //setter
	{
		Other = Other;

	}

public:
	void InputPersonalInfo();

	RegisterGUI();
	~RegisterGUI();
};

