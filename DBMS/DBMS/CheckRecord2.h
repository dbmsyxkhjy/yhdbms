#pragma once
#include "afxwin.h"


// CCheckRecord2 对话框

class CCheckRecord2 : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckRecord2)

public:
	CCheckRecord2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCheckRecord2();

// 对话框数据
	enum { IDD = IDD_DIALOG12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
};
