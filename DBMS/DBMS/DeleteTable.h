#pragma once


// CDeleteTable �Ի���

class CDeleteTable : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteTable)

public:
	CDeleteTable(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleteTable();

// �Ի�������
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
