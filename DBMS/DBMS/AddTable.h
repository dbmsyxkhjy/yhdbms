#pragma once
#include "afxwin.h"


// CAddTable �Ի���

class CAddTable : public CDialogEx
{
	DECLARE_DYNAMIC(CAddTable)

public:
	CAddTable(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddTable();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	afx_msg void OnBnClickedButton1();
};
