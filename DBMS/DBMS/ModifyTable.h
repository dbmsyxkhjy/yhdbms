#pragma once
#include "afxwin.h"


// CModifyTable 对话框

class CModifyTable : public CDialogEx
{
	DECLARE_DYNAMIC(CModifyTable)

public:
	CModifyTable(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CModifyTable();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
};
