#pragma once
#include "afxwin.h"


// CAddField �Ի���

class CAddField : public CDialogEx
{
	DECLARE_DYNAMIC(CAddField)

public:
	CAddField(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddField();

// �Ի�������
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	CComboBox m_combo;
	CButton m_check1;
	CButton m_check2;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
