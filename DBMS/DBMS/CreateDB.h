#pragma once
#include "afxwin.h"


// CCreateDB �Ի���

class CCreateDB : public CDialogEx
{
	DECLARE_DYNAMIC(CCreateDB)

public:
	CCreateDB(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCreateDB();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	afx_msg void OnBnClickedButton1();
};
