#pragma once


// CDeleteField �Ի���

class CDeleteField : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteField)

public:
	CDeleteField(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleteField();

// �Ի�������
	enum { IDD = IDD_DIALOG9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
