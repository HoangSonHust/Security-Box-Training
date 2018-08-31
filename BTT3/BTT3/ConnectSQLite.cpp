// testSQLite.cpp : Defines the entry point for the console application.
//
/*
#include "stdafx.h"
#include <iostream>
#include "sqlite3.h"
#include "ConnectSQLite.h"
static int callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	printf("chôccacnaicnakcnsakcnsackasncakscas \n");

	//fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i < argc; i++) {
		//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		printf(argv[i]);
	}

	printf("\n");

	return 0;
}
int ConnecSQLite::TakeDataFromSQLite(char *sql)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char* data = "Callback function called";

	/* Open database */
	/*rc = sqlite3_open("List.sqlite", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
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
	system("PAUSE");
	return 0;
}

*/
