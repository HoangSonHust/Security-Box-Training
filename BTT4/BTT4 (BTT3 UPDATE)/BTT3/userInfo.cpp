#define _CRT_SECURE_NO_WARNINGS
#include "userInfo.h"
#include<iostream>
#include <string>
#include "string.h"
#include "sqlite3.h" 
#include "ConnectSQLite.h"
using namespace std;
ConnecSQLite connectSQLite1;

string userInfo::TakeUserID(string userName)
{
	string strsql = "SELECT userId from userInfo where userName ='" + userName + "'";
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	return connectSQLite1.TakeDataFromSQLite(sql);
}

string userInfo::TakeUserIDMAX()
{
	string strsql = "select max(userID) from userInfo";
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.TakeDataFromSQLite(sql);
	return connectSQLite1.TakeDataFromSQLite(sql);
}

string userInfo::TakeUserIDfromUserID(string userID)
{
	string strsql = "SELECT friendId from '" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.TakeDataFromSQLite(sql);
	return connectSQLite1.TakeDataFromSQLite(sql);
}

string userInfo::TakeUserPassWord(string userName)
{
	string strsql = "SELECT passWord from userInfo where userName ='" + userName + "'";
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.TakeDataFromSQLite(sql);
	return connectSQLite1.TakeDataFromSQLite(sql);
}

void userInfo::ChangeLogInStatus(string userID)
{
	string strsql = "UPDATE userInfo SET logInStatus = '1'  WHERE userID = '" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.UpdateDataFromSQLite(sql);
}

void userInfo::ChangeLogOutStatus(string userID)
{
	string strsql = "UPDATE userInfo SET logInStatus = '0'  WHERE userID = '" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.UpdateDataFromSQLite(sql);
}

void userInfo::UpdateNewUser(string userID, string UserName, string fullName, string PassWord, string PassWordAgain, string DayOfBirth, string Sex, string Address, string Other)
{
	string strsql = "INSERT INTO userInfo(userID, userName,fullName, passWord, Gender, address, dateOfBirth,lOgInStatus ,Other)VALUES('" + userID + "'," + "'" + UserName + "'," + "'" + fullName + "'," + "'" + PassWord + "'," + "'" + Sex + "'," + "'" + Address + "'," + "'" + DayOfBirth + "'," + "'1','" + Other + "'" + ")";
	cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.PrintDataFromSQLite(sql);
}

string userInfo::TakeNameFromID(string userID)
{
	string strsql = "SELECT userName from userInfo where userID ='" + userID + "'";
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	return connectSQLite1.TakeDataFromSQLite(sql);
}

void userInfo::ChangeFriendDoB(string userID, string friendID, string newDoB)
{

	string strsql = "UPDATE userInfo SET dateOfBirth = '"+newDoB+"'  WHERE userID = '" + friendID + "'";
	cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.UpdateDataFromSQLite(sql);
}

void userInfo::ChangeFriendGender(string userID, string friendID, string newGender)
{

	string strsql = "UPDATE userInfo SET Gender = '"+newGender+"'  WHERE userID = '" + friendID + "'";
	cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.UpdateDataFromSQLite(sql);
}

void userInfo::ChangeFriendAddress(string userID, string friendID, string newAddress)
{

	string strsql = "UPDATE userInfo SET address = '"+newAddress+"'  WHERE userID = '" + friendID + "'";
	cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	connectSQLite1.UpdateDataFromSQLite(sql);
}

list<string> userInfo::select(string userID)
{
	list<string> userIDList;
	sqlite3 * db;
	//Cursor  cursor = db.rawQuery("select * from table", null);
	sqlite3_stmt * stmt;
	int nrecs;
	char * errmsg;
	int i;
	int row = 0;

	sqlite3_open("List.sqlite", &db);
	string strsql = "select stt, friendID from '" + userID + "' where stt and friendID";
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());

	sqlite3_prepare_v2(db, sql, strlen(sql)+1, &stmt, NULL);

	while (1) {
		int s;
		s = sqlite3_step(stmt);
		if (s == SQLITE_ROW) {
			int stt;
			const unsigned char * text;
			stt = sqlite3_column_int(stmt, 0);
			text = sqlite3_column_text(stmt, 1);
			stringstream ss;//create a stringstream
			ss << stt;//add number to the stream
			string str_stt= ss.str();
			//printf("%d: %s\n", row, text);
			std::string str;
			str.append(reinterpret_cast<const char*>(text));
			string strall = str_stt + ": " + str;
			cout << strall<< endl;
			userIDList.push_back(strall);
			row++;
		}
		else if (s == SQLITE_DONE) {
			break;
		}
		else {
			fprintf(stderr, "Failed.\n");
			exit(1);
		}

		//return userIDList;
	}
	list<string> lst = userIDList;
	for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
		//cout << "cho " << *i << " meo" << endl;
		return userIDList;

}

/*void userInfo::select()
{
	sqlite3 *db;
	sqlite3_stmt *res;
	int rc = sqlite3_open("List.sqlite", &db);
	rc = sqlite3_prepare_v2(db, "SELECT *from userInfo", -1, &res, 0);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(res);
	while (rc == SQLITE_ROW) {
		printf("%s\n", sqlite3_column_text(res, 0));
	}
	sqlite3_finalize(res);
	sqlite3_close(db);
}*/