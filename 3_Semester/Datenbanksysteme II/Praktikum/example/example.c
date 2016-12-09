#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

#define VBUFSIZE 128
#define ORTSIZE 20
#define KUNRSIZE 10
#define NAMESIZE 20
#define TELNRSIZE 15

int getOrte(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *ort);
int getKunden(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *ort, char*mitID);
int getDaten(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *mitID);         //-----------------------------------------------
int getProjekt(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *mitID);

int main(int argc, char *argv[]) {
	// sql vars
	SQLHENV henv = SQL_NULL_HENV; // environment
	SQLHDBC hdbc = SQL_NULL_HDBC; // connection
	SQLHSTMT hstmt = SQL_NULL_HSTMT; // statement

	// input vars
	char mitID[4];
	char ort[ORTSIZE + 1];

	// sql connect
	sqlConnect(&henv, &hdbc, &hstmt);

	// program logic
	while (getOrte(&henv, &hdbc, &hstmt, ort)) {
		getKunden(&henv, &hdbc, &hstmt, ort, mitID);
		getDaten(&henv, &hdbc, &hstmt, mitID);
		getProjekt(&henv, &hdbc, &hstmt, mitID);
	}

	puts("");

	// sql disconnect
	sqlDisconnect(&henv, &hdbc, &hstmt);

	return 0;
}



int getOrte(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *ort) {
	// sql vars
	SQLCHAR kOrt[ORTSIZE + 1];
	SQLLEN bindLen;
	SQLRETURN rc;

	// input buffer
	char vBuf[VBUFSIZE];

	// SQL statement
	char *sqlStatement = "SELECT DISTINCT(Beruf) FROM Mitarbeiter";
	if (DEBUGINFO) printf("sqlStatement: \"%s\"\n", sqlStatement);

	// perform the SQL statement
	rc = SQLExecDirect(*hstmt, (SQLCHAR *)sqlStatement, SQL_NTS);
	if (!checkReturnCode("SQLExecDirect [hstmt, sqlStatement]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	// bind columns
	rc = SQLBindCol(*hstmt, 1, SQL_C_CHAR, kOrt, ORTSIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 1, kOrt]", rc, *hstmt, SQL_HANDLE_STMT);

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
		printf("  %-*s\n", ORTSIZE, kOrt);

		i++;
	}

	// cancel statement handle
	rc = SQLCancel(*hstmt);
	if (!checkReturnCode("SQLCancel [hstmt]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	if (i == 0) {
		printf("  Keine Orte vorhanden.\n");
	}

	// get input
	printf("\n Beruf ? ");
	fgets(vBuf, VBUFSIZE, stdin);
	vBuf[strlen(vBuf) - 1] = 0;
	//strncpy(ort, vBuf, ORTSIZE); // linux
	strncpy_s(ort, ORTSIZE, vBuf, VBUFSIZE); // windows

	return strlen(ort);
}

int getKunden(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *ort, char *mitID) {
	// sql vars
	SQLINTEGER kKunr;
	SQLCHAR kName[NAMESIZE + 1];
	SQLCHAR kVorname[NAMESIZE + 1];
	SQLCHAR kORT[NAMESIZE + 1];
	SQLLEN bindLen;
	SQLRETURN rc = 0;
	SQLCHAR kBeruf[NAMESIZE + 1];
	//struct SQL_TIMESTAMP_STRUCT(year,month,day) kGebDat;
	SQLINTEGER kTelnr;


	// input buffer
	char vBuf[VBUFSIZE];

	// SQL statement
	char *part1 = "SELECT MitID, Nachname, Vorname FROM Mitarbeiter WHERE Beruf = '";
	char *part2 = "'";
	int size = strlen(part1) + strlen(ort) + strlen(part2) + 1;
	char *sqlStatement = malloc(sizeof(char)* size);
	//sprintf(sqlStatement, "%s%s%s", part1, ort, part2); // linux
	sprintf_s(sqlStatement, sizeof(char) * size, "%s%s%s", part1, ort, part2); // windows
	if (DEBUGINFO) printf("sqlStatement: \"%s\"\n", sqlStatement);

	// perform the SQL statement
	rc = SQLExecDirect(*hstmt, (SQLCHAR *)sqlStatement, SQL_NTS);
	if (!checkReturnCode("SQLExecDirect [hstmt, sqlStatement]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	// bind columns
	//MitID
	rc = SQLBindCol(*hstmt, 1, SQL_C_LONG, &kKunr, 0, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 1, kKunr]", rc, *hstmt, SQL_HANDLE_STMT);
	//Nachname
	rc = SQLBindCol(*hstmt, 2, SQL_C_CHAR, kName, NAMESIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 2, kName]", rc, *hstmt, SQL_HANDLE_STMT);
	//Vorname
	rc = SQLBindCol(*hstmt, 3, SQL_C_CHAR, kVorname, NAMESIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 3, kVorname]", rc, *hstmt, SQL_HANDLE_STMT);
	//Ort
	rc = SQLBindCol(*hstmt, 4, SQL_C_CHAR, kORT, NAMESIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 4, kORT]", rc, *hstmt, SQL_HANDLE_STMT);
	//GebDat
	//Beruf
	rc = SQLBindCol(*hstmt, 6, SQL_C_CHAR, kBeruf, NAMESIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 6, kBeruf]", rc, *hstmt, SQL_HANDLE_STMT);
	//Telnr
	rc = SQLBindCol(*hstmt, 7, SQL_C_LONG, &kTelnr, TELNRSIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 7, kTelnr]", rc, *hstmt, SQL_HANDLE_STMT);

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
		printf("  %ld %-*s %-*s\n", kKunr, NAMESIZE, kName, NAMESIZE, kVorname);

		i++;
	}

	// cancel statement handle
	rc = SQLCancel(*hstmt);
	if (!checkReturnCode("SQLCancel [hstmt]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	if (i == 0) {
		printf("  Beruf '%s' ist nicht vorhanden.\n", ort);
		return 0;
	}

	// wait

	printf("\n Geben Sie die Mitarbeiternummer aus der Liste ein, fuer wen Sie die Daten angezeigt werden haben wollen... ");
	fgets(vBuf, VBUFSIZE, stdin);
	vBuf[strlen(vBuf) - 1] = 0;
	strncpy_s(mitID, KUNRSIZE, vBuf, VBUFSIZE);
	//printf("%s\n",mitID);

	return strlen(mitID);
}

int getDaten(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *mitID){

	// sql vars
	SQLCHAR mNachname[NAMESIZE + 1];
	SQLCHAR mVorname[NAMESIZE + 1];
	SQLCHAR mOrt[ORTSIZE + 1];
	SQLCHAR mBeruf[NAMESIZE + 1];
	SQL_TIMESTAMP_STRUCT Gebdat;
	SQLCHAR mTelnr[TELNRSIZE + 1];

	SQLLEN bindLen;
	SQLRETURN rc;   

	// input buffer
	char vBuf[VBUFSIZE];

	// SQL statement
	char *part1 = "SELECT Nachname, Vorname, Ort, Gebdat, Beruf, Telnr FROM Mitarbeiter WHERE MitID ='";
	char *part2 = "'";
	int size = strlen(part1) + strlen(mitID) + strlen(part2) + 1;
	char *sqlStatement = malloc(sizeof(char)* size);
	sprintf_s(sqlStatement, sizeof(char)* size, "%s%s%s", part1, mitID, part2); // windows
	if (DEBUGINFO) printf("sqlStatement: \"%s\"\n", sqlStatement);

	// perform the SQL statement
	rc = SQLExecDirect(*hstmt, (SQLCHAR *)sqlStatement, SQL_NTS);
	if (!checkReturnCode("SQLExecDirect [hstmt, sqlStatement]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	// bind columns
	//Nachname
	rc = SQLBindCol(*hstmt, 1, SQL_C_CHAR, mNachname, NAMESIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 1, kName]", rc, *hstmt, SQL_HANDLE_STMT);
	//Vorname
	rc = SQLBindCol(*hstmt, 2, SQL_C_CHAR, mVorname, NAMESIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 2, kVorname]", rc, *hstmt, SQL_HANDLE_STMT);
	//Ort
	rc = SQLBindCol(*hstmt, 3, SQL_C_CHAR, mOrt, NAMESIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 3, kORT]", rc, *hstmt, SQL_HANDLE_STMT);
	//GebDat
	rc = SQLBindCol(*hstmt, 4, SQL_C_TIMESTAMP, &Gebdat, 1024, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 4, Gebdat]", rc, *hstmt, SQL_HANDLE_STMT);
	//Beruf
	rc = SQLBindCol(*hstmt, 5, SQL_C_CHAR, mBeruf, NAMESIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 4, kBeruf]", rc, *hstmt, SQL_HANDLE_STMT);
	//Telnr
	rc = SQLBindCol(*hstmt, 6, SQL_C_CHAR, mTelnr, TELNRSIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 5, mTelnr]", rc, *hstmt, SQL_HANDLE_STMT);

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

		printf("  %-*s %-*s %-*s %d.%d.%d %-*s %-*s \n", NAMESIZE, mNachname, NAMESIZE, mVorname, ORTSIZE, mOrt, Gebdat.day, Gebdat.month, Gebdat.year, NAMESIZE, mBeruf, NAMESIZE, mTelnr);

		i++;
	}

	// cancel statement handle
	rc = SQLCancel(*hstmt);
	if (!checkReturnCode("SQLCancel [hstmt]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	if (i == 0) {
		printf("  Kein Mitarbeiter vorhanden.\n");
	}

	/*// get input
	printf("\n Beruf ? ");
	fgets(vBuf, VBUFSIZE, stdin);
	vBuf[strlen(vBuf) - 1] = 0;
	//strncpy(ort, vBuf, ORTSIZE); // linux
	strncpy_s(ort, ORTSIZE, vBuf, VBUFSIZE); // windows
	*/

	return 0;

}
int getProjekt(SQLHENV *henv, SQLHDBC *hdbc, SQLHSTMT *hstmt, char *mitID){

	// sql vars
	SQLCHAR pName[NAMESIZE + 1];
	SQLINTEGER pNr;
	SQLFLOAT pIst;
	SQLFLOAT pPlan;

	SQLLEN bindLen;
	SQLRETURN rc;

	// input buffer
	char vBuf[VBUFSIZE];

	// SQL statement
	char *part1 = "SELECT p.ProNr, p.ProName, z.Istanteil, z.Plananteil FROM Projekt p, Zuordnung z WHERE p.ProNr=z.ProNr AND MitID ='";
	char *part2 = "'";
	int size = strlen(part1) + strlen(mitID) + strlen(part2) + 1;    //---------------------------------------
	char *sqlStatement = malloc(sizeof(char)* size);
	sprintf_s(sqlStatement, sizeof(char)* size, "%s%s%s", part1, mitID, part2); // windows  ---------------------------------------
	if (DEBUGINFO) printf("sqlStatement: \"%s\"\n", sqlStatement);

	// perform the SQL statement
	rc = SQLExecDirect(*hstmt, (SQLCHAR *)sqlStatement, SQL_NTS);
	if (!checkReturnCode("SQLExecDirect [hstmt, sqlStatement]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	// bind columns
	//Nummer
	rc = SQLBindCol(*hstmt, 1, SQL_C_LONG, &pNr, KUNRSIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 1, pNr]", rc, *hstmt, SQL_HANDLE_STMT);
	//Name
	rc = SQLBindCol(*hstmt, 2, SQL_C_CHAR, pName, NAMESIZE + 1, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 2, pName]", rc, *hstmt, SQL_HANDLE_STMT);
	//Istanteil
	rc = SQLBindCol(*hstmt, 3, SQL_C_DOUBLE, &pIst, 5, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 3, pIst]", rc, *hstmt, SQL_HANDLE_STMT);
	//Plananteil
	rc = SQLBindCol(*hstmt, 4, SQL_C_DOUBLE, &pPlan, 5, &bindLen);
	checkReturnCode("SQLBindCol [hstmt, 4, pPlan]", rc, *hstmt, SQL_HANDLE_STMT);
	
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

		printf("  %ld %-*s %.1f %.1f \n", pNr, NAMESIZE, pName, pIst, pPlan);

		i++;
	}

	// cancel statement handle
	rc = SQLCancel(*hstmt);
	if (!checkReturnCode("SQLCancel [hstmt]", rc, *hstmt, SQL_HANDLE_STMT)) {
		freeSQLHandles(henv, hdbc, hstmt); exit(0);
	}

	if (i == 0) {
		printf("  Keine Projekte.\n");
	}

	return 0;

}