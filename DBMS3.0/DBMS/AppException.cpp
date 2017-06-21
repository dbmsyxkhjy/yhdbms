// AppException.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "AppException.h"


// CAppException

IMPLEMENT_DYNAMIC(CAppException, CWnd)

CAppException::CAppException()
{

}

CAppException::~CAppException()
{
}


BEGIN_MESSAGE_MAP(CAppException, CWnd)
END_MESSAGE_MAP()



// CAppException 消息处理程序
CAppException::CAppException(CString message)
{
	m_message=message;
	m_code=0;	
}

CString CAppException::getErrorMessage()
{
	return m_message;
}