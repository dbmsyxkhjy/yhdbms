#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CModifyRecord 对话框

class CModifyRecord : public CDialogEx
{
	DECLARE_DYNAMIC(CModifyRecord)

public:
	CModifyRecord(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CModifyRecord();

// 对话框数据
	enum { IDD = IDD_DIALOG13 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CEdit m_edit;
	CString db;
	CString tb;
	int m_Row;
	int m_Col;
	int index;
	int index2;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnEnKillfocusEdit3();
	afx_msg void OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit3();
};
