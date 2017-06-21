#pragma once
#include "afxwin.h"


// CModifyField 对话框

class CModifyField : public CDialogEx
{
	DECLARE_DYNAMIC(CModifyField)

public:
	CModifyField(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CModifyField();

// 对话框数据
	enum { IDD = IDD_DIALOG8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CComboBox m_combo;
	CEdit m_edit2;
	CButton m_check1;
	CButton m_check2;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
