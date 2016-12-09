#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

#define VBUFSIZE 128
#define ORTSIZE 20
#define KUNRSIZE 10
#define NAMESIZE 20
#define BERUFSIZE 20


int getBerufe(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *beruf);
int getKunden(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *beruf);

int main(int argc, char *argv[]) {
	// sql vars
	SQLHENV henv = SQL_NULL_HENV; // environment
	SQLHDBC hdbc = SQL_NULL_HDBC; // connection
	SQLHSTMT hstmt = SQL_NULL_HSTMT; // statement

	// input vars
	char beruf[BERUFSIZE + 1];

	// sql connect
	sqlConnect(&henv, &hdbc, &hstmt);

	// program logic
	while (getBerufe(&henv, &hdbc, &hstmt, beruf)) {
		getKunden(&henv, &hdbc, &hstmt, beruf);
	}

	puts("");

	// sql disconnect
	sqlDisconnect(&henv, &hdbc, &hstmt);

	return 0;
}

int getBerufe(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *beruf) {
	// sql vars
	SQLCHAR kBeruf[BERUFSIZE + 1];
	SQLLEN bindLen;
	SQLRETURN rc;

	// input buffer
	char vBuf[VBUFSIZE];

	// SQL statement
	char *sqlStatement = "SELECT DISTINCT(Beruf) FROM Kunde";
	if (DEBUGINFO) printf("sqlStatement: \"%s\"\n", sqlStatement);

	// perform the SQL statement
	rc = SQLExecDirect(*hstmt, (SQLCHAR *)sqlStatement, SQL_NTS);
	if (!checkReturnCode("SQLExecDirect [hstmt, sqlStatement]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	// bind columns
	rc = SQLBindCol(*hstmt, 1, SQL_C_CHAR, kBeruf, BERUFSIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 1, kBeruf]", rc, *hstmt, SQL_HANDLE_STMT);

	puts("");

	// fetch and print each row of data
	int i = 0;
	while ((rc = SQLFetch(*hstmt)) != SQL_NO_DATA) {
		// check error and warning
		if (rc == SQL_ERROR) {
			printf("SQLFetch [hstmt]: SQL_ERROR\n");
			break;
		}
		if (rc == SQL_SUCCESS_WITH_INFO) {
			printf("SQLFetch [hstmt]: SQL_SUCCESS_WITH_INFO\n");
		}

		// process data
		printf("  %-*s\n", BERUFSIZE, kBeruf);

		i++;
	}

	// cancel statement handle
	rc = SQLCancel(*hstmt);
	if (!checkReturnCode("SQLCancel [hstmt]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	if (i == 0) {
		printf("  Keine Berufe vorhanden.\n");
	}

	// get input
	printf("\n Berufe ? ");
	fgets(vBuf, VBUFSIZE, stdin);
	vBuf[strlen(vBuf) - 1] = 0;
	//strncpy(beruf, vBuf, BERUFSIZE); // linux
	strncpy_s(beruf, BERUFSIZE, vBuf, VBUFSIZE); // windows

	return strlen(beruf);
}

int getKunden(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *beruf) {
	// sql vars
	SQLINTEGER kKunr;
	SQLCHAR kName[NAMESIZE + 1];
	SQLLEN bindLen;
	SQLRETURN rc = 0;

	// input buffer
	char vBuf[VBUFSIZE];

	// SQL statement
	char *part1 = "SELECT Kunr, Name FROM Kunde WHERE Beruf = '";
	char *part2 = "'";
	int size = strlen(part1) + strlen(beruf) + strlen(part2) + 1;
	char *sqlStatement = malloc(sizeof(char)* size);
	//sprintf(sqlStatement, "%s%s%s", part1, ort, part2); // linux
	sprintf_s(sqlStatement, sizeof(char)* size, "%s%s%s", part1, beruf, part2); // windows
	if (DEBUGINFO) printf("sqlStatement: \"%s\"\n", sqlStatement);

	// perform the SQL statement
	rc = SQLExecDirect(*hstmt, (SQLCHAR *)sqlStatement, SQL_NTS);
	if (!checkReturnCode("SQLExecDirect [hstmt, sqlStatement]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	// bind columns
	rc = SQLBindCol(*hstmt, 1, SQL_C_LONG, &kKunr, 0, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 1, kKunr]", rc, *hstmt, SQL_HANDLE_STMT);
	rc = SQLBindCol(*hstmt, 2, SQL_C_CHAR, kName, NAMESIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 2, kName]", rc, *hstmt, SQL_HANDLE_STMT);

	puts("");

	// fetch and print each row of data
	int i = 0;
	while ((rc = SQLFetch(*hstmt)) != SQL_NO_DATA) {
		// check error and warning
		if (rc == SQL_ERROR) {
			printf("SQLFetch [hstmt]: SQL_ERROR\n");
			break;
		}
		if (rc == SQL_SUCCESS_WITH_INFO) {
			printf("SQLFetch [hstmt]: SQL_SUCCESS_WITH_INFO\n");
		}

		// process data
		printf("  %ld %-*s\n", kKunr, NAMESIZE, kName);

		i++;
	}

	// cancel statement handle
	rc = SQLCancel(*hstmt);
	if (!checkReturnCode("SQLCancel [hstmt]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	if (i == 0) {
		printf("  Beruf '%s' ist nicht vorhanden.\n", beruf);
		return 0;
	}

	// wait
	printf("\n ? ");
	fgets(vBuf, sizeof(vBuf), stdin);

	return 0;
}
