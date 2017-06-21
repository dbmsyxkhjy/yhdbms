#pragma once
#include "AddRecord.h"
#include "afxwin.h"

// CCheckRecord 对话框

class CCheckRecord : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckRecord)

public:
	CCheckRecord(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCheckRecord();

// 对话框数据
	enum { IDD = IDD_DIALOG11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
};
