#pragma once
#include "afxwin.h"


// COpenTable 对话框

class COpenTable : public CDialogEx
{
	DECLARE_DYNAMIC(COpenTable)

public:
	COpenTable(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COpenTable();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
};
