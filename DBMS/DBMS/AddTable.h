#pragma once
#include "afxwin.h"


// CAddTable 对话框

class CAddTable : public CDialogEx
{
	DECLARE_DYNAMIC(CAddTable)

public:
	CAddTable(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddTable();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	afx_msg void OnBnClickedButton1();
};
