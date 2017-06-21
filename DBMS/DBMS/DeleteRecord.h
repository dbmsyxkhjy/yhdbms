#pragma once
#include "afxcmn.h"


// CDeleteRecord 对话框

class CDeleteRecord : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteRecord)

public:
	CDeleteRecord(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeleteRecord();

// 对话框数据
	enum { IDD = IDD_DIALOG15 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
