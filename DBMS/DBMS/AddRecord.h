#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CAddRecord �Ի���

class CAddRecord : public CDialogEx
{
	DECLARE_DYNAMIC(CAddRecord)

public:
	CAddRecord(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddRecord();

// �Ի�������
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
	CString db;
	CString tb;
	int m_Row;
	int m_Col;
	int num;
	afx_msg void OnBnClickedButton1();


	CEdit m_edit;
	afx_msg void OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnKillfocusEdit3();
};
