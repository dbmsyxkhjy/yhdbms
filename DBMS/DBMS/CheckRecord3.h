#pragma once
#include "afxwin.h"


// CCheckRecord3 �Ի���

class CCheckRecord3 : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckRecord3)

public:
	CCheckRecord3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCheckRecord3();

// �Ի�������
	enum { IDD = IDD_DIALOG14 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
};
