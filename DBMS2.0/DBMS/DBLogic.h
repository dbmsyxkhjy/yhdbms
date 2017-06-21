#pragma once
#ifndef _DBLOGIC_H_
#define _DBLOGIC_H_


// CDBLogic

class CDBLogic : public CWnd
{
	DECLARE_DYNAMIC(CDBLogic)

public:
	CDBLogic();
	virtual ~CDBLogic();
	bool CreateDatabase(CString databasename);

protected:
	DECLARE_MESSAGE_MAP()
};


#endif