#pragma once


// CDeleteTable 对话框

class CDeleteTable : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteTable)

public:
	CDeleteTable(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeleteTable();

// 对话框数据
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
