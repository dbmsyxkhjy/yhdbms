#pragma once


// CDeleteDatabase �Ի���

class CDeleteDatabase : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteDatabase)

public:
	CDeleteDatabase(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleteDatabase();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG16 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

public:
	int  removeDir(const char*  dirPath);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
};
