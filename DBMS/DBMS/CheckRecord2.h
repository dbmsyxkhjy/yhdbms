#pragma once
#include "afxwin.h"


// CCheckRecord2 �Ի���

class CCheckRecord2 : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckRecord2)

public:
	CCheckRecord2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCheckRecord2();

// �Ի�������
	enum { IDD = IDD_DIALOG12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
};
