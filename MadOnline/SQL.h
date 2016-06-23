#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <Odbcinst.h>
#include <process.h>
#include <stdio.h>
#include <windows.h> 
#include <string>

#pragma comment( lib, "odbc32.lib" )

SQLHANDLE hEnv ;
SQLRETURN retCode ;
SQLHANDLE hConn ;

SQLCHAR* dsnName = (SQLCHAR*)"kal_db" ;  
SQLCHAR* userid = (SQLCHAR*)"sa";
SQLCHAR* password = (SQLCHAR*)"pw";  

int connecToSqlDB()
{
	retCode = SQLAllocHandle( SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv ) ;
	retCode = SQLSetEnvAttr( hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0 ) ; 
	SQLAllocHandle( SQL_HANDLE_DBC, hEnv, &hConn );
	retCode = SQLConnectA(hConn, dsnName, SQL_NTS, userid,SQL_NTS, password,SQL_NTS ) ;
	return retCode;
}

int executeMSSQLSTM(char *statement, bool update)
{
		SQLHANDLE hStmt ;
		SQLAllocHandle( SQL_HANDLE_STMT, hConn, &hStmt ) ;
		SQLCHAR* query = (SQLCHAR*)statement ;
		if( SQLExecDirectA( hStmt, query, SQL_NTS )){}

		if (!update)
		{
			retCode = SQLFetch( hStmt ) ;
			int id;
			SQLGetData(hStmt, 1, SQL_C_ULONG, &id, 0, NULL);
			SQLFreeHandle( SQL_HANDLE_STMT, hStmt ) ;
			SQLFreeHandle( SQL_HANDLE_DBC, hConn ) ;
			SQLFreeHandle( SQL_HANDLE_ENV, hEnv ) ;
			return id;
		} 
		else 
		{
			SQLFreeHandle( SQL_HANDLE_STMT, hStmt ) ;
			SQLFreeHandle( SQL_HANDLE_DBC, hConn ) ;
			SQLFreeHandle( SQL_HANDLE_ENV, hEnv ) ;
			return 0;
		}
}