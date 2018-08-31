#define _CRT_SECURE_NO_WARNINGS
#include "UserMessInfo.h"
#include"ConnectSQLite.h"
#include <iostream>
#include "ConnectSQLite.h"
#include "userInfo.h"
userInfo userInfo_test;

ConnecSQLite ConnectSQLiteUserMessInfo;


void UserMessInfo::CreatUserTable(string userID)
{
	string strsql = "CREATE TABLE '" + userID + "' (`stt`INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, friendID TEXT,friendName TEXT,friendStatus TEXT,TimeAddFriend TEXT)";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
}

void UserMessInfo::RequestAddFriend(string userID, string friendID, string friendName, string TimeAddFriend)
{
	//string strsql = INSERT INTO userInfo(userID, userName, fullName, passWord, Gender, address, dateOfBirth, Other)VALUES('" + userID +"', " + "'"+UserName+"', "+ "'"+ fullName +"', "+"'"+ PassWord+"', "+"'"+ Sex +"', "+ "'"+ Address + "', "+ "'"+ DayOfBirth +"', "+"'"+Other+"'" +")";
	string strsql = "INSERT INTO '" + userID + "' (friendID, friendName, friendStatus,TimeAddFriend )VALUES('" + friendID + "',' " + friendName + "','1'," + "'" + TimeAddFriend + "'" + " )";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
}
string UserMessInfo::RequestFriendList(string userID)
{
	string strsql = "SELECT friendID, friendName from '" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
	//cout << ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
	//cout << ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql) << endl;
	return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}

void UserMessInfo::RequestBlockFriend(string userID, string friendID)
{
	string strsql = "UPDATE '" + userID + "'" + " SET friendStatus= '0'  WHERE friendID = '" + friendID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.UpdateDataFromSQLite(sql);
}

void UserMessInfo::RequestSentMess(string userID, string friendID, string Mess, string TimeMess, string MessID, string Seconds)
{
	string strsql = "INSERT INTO Messeger (messID,TimeReceiverMess,SecondsMess,Senter,Receiver,Mess,See)VALUES('" + MessID + "',' " + TimeMess + "','" + Seconds + "','" + userID + "'," + "'" + friendID + "','" + Mess + "','1'" + ")";
	cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
}

/*void UserMessInfo::UpdateSecondsSentMess(string userID, string friendID, string messID, string Seconds)
{

	string strsql = "UPDATE Messeger SET SecondsMess = '"+ Seconds +"'  WHERE Senter = '" + userID + "' and Receiver='"+friendID+"'and messID ='"+ messID+"'";
	cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.UpdateDataFromSQLite(sql);
}*/

/*void UserMessInfo::RequestRecieverMess(string userID, string friendID, string Mess, string TimeMess, string MessID)
{
	string strsql = "INSERT INTO '" + friendID + "' (messID,TimeReceiverMess,Senter,Receiver,Mess,Seen)VALUES('" + MessID + "',' " + TimeMess + "','" + userID + "'," + "'" + friendID + "','" + Mess + "','1'" + ")";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
}*/
void UserMessInfo::DisplayMessUserSentGUI(string userID)
{
	string strsql = "SELECT messID,TimeReceiverMess,Senter,Receiver,Mess from Messeger where Senter ='" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
}

void UserMessInfo::RequestDislayMesswithFriend(string userID, string friendID)
{

	string strsql = "SELECT messID,TimeReceiverMess,Senter,Receiver,Mess from Messeger where Senter = '" + userID + "'and Receiver= '" + friendID + "' or Senter = '" + friendID + "'and Receiver = '" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.PrintDataFromSQLite(sql);
}

string UserMessInfo::TakeMessIDMax(string userID, string Senter, string Receiver)
{
	string strsql = "select max(messID) from Messeger where Senter = '" + Senter + "' and Receiver ='" + Receiver + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}

string UserMessInfo::CheckHaveMessHaveNotSeen(string userID)
{
	string strsql = "select count(See)from Messeger where Receiver = '" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}



string UserMessInfo::TakeMumberOfMess(string userID)
{
	//SELECT sum(seen) FROM "1234567915" where Receiver = "1234567915"
	string strsql = "select sum(See) from Messeger where Receiver = '" + userID + "' and See ='1'";
	//cout <<strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}

string UserMessInfo::CheckHaveReceiver(string userID, string ReceiverID)
{
	string strsql = "select count(Receiver)from Messeger where Receiver = '" + ReceiverID + "' and Senter='" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}


list<string> UserMessInfo::TakeSenter(string userID)
{
	string strsql = "select Senter from Messeger where See = '1' and Receiver = '" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());

	list<string> FriendIDList;
	sqlite3 * db;
	//char * sql;
	sqlite3_stmt * stmt;
	int nrecs;
	char * errmsg;
	int i;
	int row = 0;

	sqlite3_open("List.sqlite", &db);
	//sql = "SELECT * FROM t";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	while (1) {
		int s;
		s = sqlite3_step(stmt);
		if (s == SQLITE_ROW) {
			int bytes;
			const unsigned char * text;
			bytes = sqlite3_column_bytes(stmt, 0);
			text = sqlite3_column_text(stmt, 0);
			stringstream ss;
			string s;
			std::string str;
			str.append(reinterpret_cast<const char*>(text));
			FriendIDList.push_back(str);
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
	list<string> lst = FriendIDList;
	for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
		//cout << "cho " << *i << " meo" << endl;
		return FriendIDList;

	//return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}

list<string> UserMessInfo::TakeMessIDFromFriendIDHaveNotSeen(string userID, string friendID)
{
	string strsql = "select messID from Messeger where See = '1' and Senter = '" + friendID + "'";
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());

	list<string> messIDList;
	sqlite3 * db;
	//char * sql;
	sqlite3_stmt * stmt;
	int nrecs;
	char * errmsg;
	int i;
	int row = 0;

	sqlite3_open("List.sqlite", &db);
	//sql = "SELECT * FROM t";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	while (1) {
		int s;
		s = sqlite3_step(stmt);
		if (s == SQLITE_ROW) {
			int bytes;
			const unsigned char * text;
			bytes = sqlite3_column_bytes(stmt, 0);
			text = sqlite3_column_text(stmt, 0);
			stringstream ss;
			string s;
			std::string str;
			str.append(reinterpret_cast<const char*>(text));
			messIDList.push_back(str);
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
	list<string> lst = messIDList;
	for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
		//cout << "cho " << *i << " meo" << endl;
		return messIDList;
}

string UserMessInfo::SeenMessThatHaveNotSeen(string userID, string friendID, string messID)
{
	string strsql = "select Mess from Messeger where See = '1' and Senter = '" + friendID + "' and messID = '" + messID + "'";
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}

void UserMessInfo::ChangeSeenStatus(string userID, string friendID, string messID)
{
	string strsql = "UPDATE Messeger SET See = '0'  WHERE messID = '" + messID + "' and Senter ='" + friendID + "' and Receiver ='" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	ConnectSQLiteUserMessInfo.UpdateDataFromSQLite(sql);
}

list<string> UserMessInfo::TakeFriendList(string userID)
{

	list<string> friendListAndPosition;
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

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

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
			string str_stt = ss.str();
			//printf("%d: %s\n", row, text);
			std::string str;
			str.append(reinterpret_cast<const char*>(text));
			//userInfo_test.TakeNameFromID(str);
			string strall = str_stt + ": " + userInfo_test.TakeNameFromID(str);
			//cout << strall << endl;
			friendListAndPosition.push_back(strall);
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
	//list<string> lst = friendListAndPosition;
	//for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
		//cout << "cho " << *i << " meo" << endl;
	return friendListAndPosition;

}

list<string> UserMessInfo::TakeFriendListIDUserSentMess(string userID)
{
	list<string> FriendUserSentMess;
	sqlite3 * db;
	//Cursor  cursor = db.rawQuery("select * from table", null);
	sqlite3_stmt * stmt;
	int nrecs;
	char * errmsg;
	int i;
	int row = 0;

	sqlite3_open("List.sqlite", &db);
	string strsql = "select Receiver from Messeger where Senter ='" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	while (1) {
		int s;
		s = sqlite3_step(stmt);
		if (s == SQLITE_ROW) {

			const unsigned char * ReceiverList;

			ReceiverList = sqlite3_column_text(stmt, 0);
			std::string str;
			str.append(reinterpret_cast<const char*>(ReceiverList));
			FriendUserSentMess.push_back(str);
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
	/*	list<string> lst = FriendUserSentMess;
		for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
		cout << "cho " << *i << " meo" << endl;*/
	return FriendUserSentMess;

}

/*
lấy danh sách bạn mà đã gửi tin nhắn cho mình
*/
list<string> UserMessInfo::TakeFriendListSentMessToUser(string userID)
{
	list<string> FriendListSentMessToUser;
	sqlite3 * db;
	//Cursor  cursor = db.rawQuery("select * from table", null);
	sqlite3_stmt * stmt;
	int nrecs;
	char * errmsg;
	int i;
	int row = 0;

	sqlite3_open("List.sqlite", &db);
	string strsql = "select Senter from Messeger where Receiver ='" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	while (1) {
		int s;
		s = sqlite3_step(stmt);
		if (s == SQLITE_ROW) {

			const unsigned char * ReceiverList;

			ReceiverList = sqlite3_column_text(stmt, 0);
			std::string str;
			str.append(reinterpret_cast<const char*>(ReceiverList));
			FriendListSentMessToUser.push_back(str);
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
	/*list<string> lst = FriendListSentMessToUser;
for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
cout << "cho " << *i << " meo" << endl;*/
	return FriendListSentMessToUser;
}

string UserMessInfo::TakeSecondSentMess(string userID, string friendID)
{
	string strsql = "select max(SecondsMess) from Messeger where Senter = '" + userID + "' and Receiver ='" + friendID + "'or Senter = '" + friendID + "' and Receiver ='" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}

string UserMessInfo::takefriendIDFromTimeMaxSentMessFromSenter(string userID, string Second)
{

	string strsql = "select Senter from Messeger where Senter = '" + userID + "' and SecondsMess ='" + Second + "'or Receiver ='" + userID + "' and SecondsMess ='" + Second + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}

string UserMessInfo::takefriendIDFromTimeMaxSentMessFromReceiver(string userID, string Second)
{
	string strsql = "select Receiver from Messeger where Senter = '" + userID + "' and SecondsMess ='" + Second + "'or Receiver ='" + userID + "' and SecondsMess ='" + Second + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}

list<string> UserMessInfo::TakeALLFriendIDlist(string userID)
{
	list<string> friendList;
	sqlite3 * db;
	//Cursor  cursor = db.rawQuery("select * from table", null);
	sqlite3_stmt * stmt;
	int nrecs;
	char * errmsg;
	int i;
	int row = 0;

	sqlite3_open("List.sqlite", &db);
	string strsql = "select friendID from '" + userID + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	while (1) {
		int s;
		s = sqlite3_step(stmt);
		if (s == SQLITE_ROW) {
			int stt;
			const unsigned char * text;
			//stt = sqlite3_column_int(stmt, 0);
			text = sqlite3_column_text(stmt, 0);
			std::string str;
			str.append(reinterpret_cast<const char*>(text));
			friendList.push_back(str);
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
	//list<string> lst = friendListAndPosition;
	//for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
	//cout << "cho " << *i << " meo" << endl;
	return friendList;
}

list<string> UserMessInfo::TakeCityOfFriend(string userID)
{
	list<string> friendCityList;
	sqlite3 * db;
	//Cursor  cursor = db.rawQuery("select * from table", null);
	sqlite3_stmt * stmt;
	int nrecs;
	char * errmsg;
	int i;


	sqlite3_open("List.sqlite", &db);
	// select userInfo.address from userInfo, '1' where userInfo.userID = '1'.friendID
	string strsql = "select userInfo.address from userInfo, '" + userID + "'where userInfo.userID = '" + userID + "'.friendID";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	while (1) {
		int s;
		s = sqlite3_step(stmt);
		if (s == SQLITE_ROW) {
			int stt;
			const unsigned char * text;
			//stt = sqlite3_column_int(stmt, 0);
			text = sqlite3_column_text(stmt, 0);
			std::string str;
			str.append(reinterpret_cast<const char*>(text));
			friendCityList.push_back(str);

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
	friendCityList.sort();
	friendCityList.unique();
	/*list<string> lst = friendCityList;
	lst.unique();
	for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
	cout << "cho " << *i << " meo" << endl;*/
	return friendCityList;
}

list<string> UserMessInfo::TakeFriendIDforCity(string userID, string Address)
{
	list<string> friendCityList;
	sqlite3 * db;
	//Cursor  cursor = db.rawQuery("select * from table", null);
	sqlite3_stmt * stmt;
	int nrecs;
	char * errmsg;
	int i;
	int row = 0;

	sqlite3_open("List.sqlite", &db);
	//               select '1'.friendID from userInfo, '1' where '1'.friendID = userInfo.userID and userInfo.address = "HN"
	string strsql = "select '" + userID + "'.friendID from userInfo,'" + userID + "'where'" + userID + "'.friendID = userInfo.userID and userInfo.address = '" + Address + "'";
	//cout << strsql;
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	while (1) {
		int s;
		s = sqlite3_step(stmt);
		if (s == SQLITE_ROW) {
			int stt;
			const unsigned char * text;
			//stt = sqlite3_column_int(stmt, 0);
			text = sqlite3_column_text(stmt, 0);
			std::string str;
			str.append(reinterpret_cast<const char*>(text));
			friendCityList.push_back(str);
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
	list<string> lst = friendCityList;
	/*for (list<string>::iterator i = lst.begin(); i != lst.end(); ++i)
	cout << "cho " << *i << " meo" << endl;*/
	return friendCityList;
}

string UserMessInfo::TakeFriendID(string userID, string Position)
{
	string strsql = "select friendID from '" + userID + "' where stt = '" + Position + "'";
	char *sql = new char[strsql.length() + 1];
	std::strcpy(sql, strsql.c_str());
	return ConnectSQLiteUserMessInfo.TakeDataFromSQLite(sql);
}





UserMessInfo::UserMessInfo()
{
}


UserMessInfo::~UserMessInfo()
{
}

void RequestFriendList(string userID)
{
}
