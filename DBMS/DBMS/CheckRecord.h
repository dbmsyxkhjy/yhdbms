#pragma once
#include "AddRecord.h"
#include "afxwin.h"

// CCheckRecord �Ի���

class CCheckRecord : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckRecord)

public:
	CCheckRecord(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCheckRecord();

// �Ի�������
	enum { IDD = IDD_DIALOG11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
};
