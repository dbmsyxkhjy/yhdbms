#pragma once
#include "afxwin.h"


// COpenTable �Ի���

class COpenTable : public CDialogEx
{
	DECLARE_DYNAMIC(COpenTable)

public:
	COpenTable(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COpenTable();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
};
