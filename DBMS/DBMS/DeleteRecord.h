#pragma once
#include "afxcmn.h"


// CDeleteRecord �Ի���

class CDeleteRecord : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteRecord)

public:
	CDeleteRecord(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleteRecord();

// �Ի�������
	enum { IDD = IDD_DIALOG15 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	afx_msg void OnBnClickedButton1();
	CString db;
	CString tb;
	int index;
	int index2;
	virtual BOOL OnInitDialog();
};
