#include "Database.h"

SQLHANDLE hEnv ;
SQLRETURN retCode ;
SQLHANDLE hConn ;

SQLCHAR* dsnName;
SQLCHAR* userid = (SQLCHAR*)"sa";
SQLCHAR* password = (SQLCHAR*)"pw";  

inline char* CheckConnection(int i)
{
	switch(i)
	{
	case -2:
		return "[DB Connection Error: invalid handle]";
	case -1:
		return "[DB Connection Error]";
	case 0:
		return "[DB connect succeeded, started]";
	case 1:
		return "[DB connect succeeded, started]";
	case 99:
		return "[DB Connection Error: need data]";
	case 100:
		return "[DB Connection Error: no data]";
	default:
		return "[DB Connection Error: unknown error]";
	}

}

char* Database::Connect(const char *dbname)
{
	dsnName = (SQLCHAR*)dbname;
	retCode = SQLAllocHandle( SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv ) ;
	retCode = SQLSetEnvAttr( hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0 ) ; 
	SQLAllocHandle( SQL_HANDLE_DBC, hEnv, &hConn );
	retCode = SQLConnectA(hConn, dsnName, SQL_NTS, userid,SQL_NTS, password,SQL_NTS ) ;
	return CheckConnection(retCode);
}

int Database::Execute(const char *statement, bool update)
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


