#pragma once
#ifndef _APPEXCEPTION_H_
#define _APPEXCEPTION_H_

// CAppException

class CAppException : public CWnd
{
	DECLARE_DYNAMIC(CAppException)

public:
	CAppException();
	virtual ~CAppException();
	CString getErrorMessage();
	CAppException(CString message);

protected:
	DECLARE_MESSAGE_MAP()

private:
	CString m_message;//Exception information
	int m_code;//Exception code
};

#endif
