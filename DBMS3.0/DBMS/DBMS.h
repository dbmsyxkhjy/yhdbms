
// DBMS.h : DBMS Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDBMSApp:
// �йش����ʵ�֣������ DBMS.cpp
//

class CDBMSApp : public CWinApp
{
public:
	CDBMSApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnCreatedatabase();
	afx_msg void OnOpendatabase();
	afx_msg void OnNewtable();
	afx_msg void OnModifytable();

	afx_msg void OnDatabaseDeletedatabase();
};

extern CDBMSApp theApp;
