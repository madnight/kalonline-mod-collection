/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
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




