#pragma once
#include "afxwin.h"


// COpenDB 对话框

class COpenDB : public CDialogEx
{
	DECLARE_DYNAMIC(COpenDB)

public:
	COpenDB(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COpenDB();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	afx_msg void OnBnClickedButton1();
};
