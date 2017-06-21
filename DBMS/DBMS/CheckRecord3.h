#pragma once
#include "afxwin.h"


// CCheckRecord3 对话框

class CCheckRecord3 : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckRecord3)

public:
	CCheckRecord3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCheckRecord3();

// 对话框数据
	enum { IDD = IDD_DIALOG14 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
};
