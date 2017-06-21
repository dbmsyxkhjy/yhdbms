#pragma once


// CDeleteDatabase 对话框

class CDeleteDatabase : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteDatabase)

public:
	CDeleteDatabase(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeleteDatabase();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG16 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

public:
	int  removeDir(const char*  dirPath);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
};
