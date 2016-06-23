#include <Windows.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <Odbcinst.h>
#include <process.h>
#include <stdio.h>
#include <string>

#pragma once

#pragma comment( lib, "odbc32.lib" )


class Database
{
public:
	char* Connect(const char *dbname);
	int Execute(const char *statement, bool update);
};




