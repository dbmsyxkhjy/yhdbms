#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <Windows.h>

#define VARCHAR CString
#define INTEGER int
#define DOUBLE double
#define DATETIME SYSTEMTIME
#define BOOL bool

struct DatabaseBlock
{
	VARCHAR name;//database name
	BOOL type;//database type: false is system database,true is user database
	VARCHAR filename;//full path of database data folder
	DATETIME crtime;//creation date
	
};

#endif