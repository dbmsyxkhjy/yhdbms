#pragma once
#include "afxwin.h"


// COpenDB �Ի���

class COpenDB : public CDialogEx
{
	DECLARE_DYNAMIC(COpenDB)

public:
	COpenDB(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COpenDB();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	afx_msg void OnBnClickedButton1();
};
