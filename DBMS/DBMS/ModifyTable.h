#pragma once
#include "afxwin.h"


// CModifyTable �Ի���

class CModifyTable : public CDialogEx
{
	DECLARE_DYNAMIC(CModifyTable)

public:
	CModifyTable(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CModifyTable();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
};
