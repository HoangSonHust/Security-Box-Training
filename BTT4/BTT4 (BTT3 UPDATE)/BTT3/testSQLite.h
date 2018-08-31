#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include "sqlite3.h"
#include "ConnectSQLite.h"
#include <string>
#include <sstream>

class testSQLite
{
public:

	void test() {
		
			std::string	strSQL = "SELECT userId from userInfo where userName ='user1_pass@gmail.com'";
			int rc;
			sqlite3 *db;
			rc = sqlite3_open("List.sqlite", &db);
			char *SQL = new char[strSQL.length() + 1];
			std::strcpy(SQL, strSQL.c_str());
			sqlite3_stmt *stmt;
		rc = sqlite3_prepare_v2(db, SQL, strlen(SQL), &stmt, NULL);

		if (rc == SQLITE_OK) {
			sqlite3_bind_text(stmt, 1, "meo", strlen("meo"), SQLITE_STATIC);
			if (sqlite3_step(stmt) == SQLITE_ROW) {
				std::string strsql;
				std::stringstream str;
				str << sqlite3_column_text(stmt, 0);
				str >> strsql;
				//str = sqlite3_column_text(stmt, 0);
				//str >> id2;
				//printf("choahaasj %s kahcaihaksak", sqlite3_column_text(stmt, 0));
				std::cout << strsql;
			}
			sqlite3_finalize(stmt);
		}
		else {
			char *zErrMsg = 0;
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}

	}
	testSQLite();
	~testSQLite();
};
