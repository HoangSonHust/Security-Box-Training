#pragma once
#include "stdafx.h"
#include <iostream>
#include "sqlite3.h"
#include "ConnectSQLite.h"
#include <sstream>
using namespace std;
class ConnecSQLite
{
private:
public:
	//static int NumCol;
	static int callback(void *data, int argc, char **argv, char **azColName) {
		int i;
		//	NumCol = argc;
		fprintf(stderr, "%s: \n", (const char*)data);
		for (i = 0; i < argc; i++) {
			printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
			//printf(argv[i]);

		}
		printf("\n");


		return 0;
	}
	int PrintDataFromSQLite(char *sql)
	{
		sqlite3 *db;
		char *zErrMsg = 0;
		int rc;
		const char* data = "Callback function called ";

		/* Open database */
		rc = sqlite3_open("List.sqlite", &db);

		if (rc) {
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			return (0);
		}
		else {
			fprintf(stderr, "Opened database successfully\n");
			//return 1;
		}
		rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);

		}
		else {
			fprintf(stdout, "Operation done successfully\n");
		}

		sqlite3_close(db);
		//system("PAUSE");
		return 0;
	}

	string TakeDataFromSQLite(char *sql) {

		int rc;
		sqlite3 *db;
		sqlite3_stmt *stmt;
		char *zErrMsg = 0;
		rc = sqlite3_open("List.sqlite", &db);
		std::string Nothing = "NOTHING";
		rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
		if (rc == SQLITE_OK) {
			sqlite3_bind_text(stmt, 1, "meo", strlen("meo"), SQLITE_STATIC);
			if (sqlite3_step(stmt) == SQLITE_ROW) {
				std::string strsql;
				std::stringstream str;
				str << sqlite3_column_text(stmt, 0);
				str >> strsql;
				sqlite3_close(db);
				sqlite3_finalize(stmt);
				return strsql;


			}
			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Nothing;
		}
		else {
			char *zErrMsg = 0;
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);

			sqlite3_close(db);
			return Nothing;
		}
		sqlite3_finalize(stmt);
		sqlite3_close(db);

	}


	string UpdateDataFromSQLite(char *sql) {

		//	std::string	strSQL = "SELECT userId from userInfo where userName ='user1_pass@gmail.com'";
		int rc;
		sqlite3 *db;
		sqlite3_stmt *stmt;
		rc = sqlite3_open("List.sqlite", &db);
		std::string Nothing = "NOTHING";
		//char *SQL = new char[strSQL.length() + 1];
		//std::strcpy(SQL, strSQL.c_str());

		rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

		if (rc == SQLITE_OK) {
			sqlite3_bind_text(stmt, 1, "meo", strlen("meo"), SQLITE_STATIC);
			if (sqlite3_step(stmt) == SQLITE_ROW) {
				std::string strsql;
				std::stringstream str;
				str << sqlite3_column_text(stmt, 0);
				str >> strsql;
				return strsql;
				sqlite3_finalize(stmt);
				sqlite3_close(db);
			}
			sqlite3_finalize(stmt);

			sqlite3_close(db);
			return Nothing;
		}
		else {
			char *zErrMsg = 0;

			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Nothing;
		}
		sqlite3_finalize(stmt);
		sqlite3_close(db);

	}

};

























