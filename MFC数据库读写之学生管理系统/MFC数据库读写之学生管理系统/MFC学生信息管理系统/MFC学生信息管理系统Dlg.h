// MFC学生信息管理系统Dlg.h : header file
//

#if !defined(AFX_MFCDLG_H__11CC3DC8_1499_4B79_BF1B_797FA9A357B9__INCLUDED_)
#define AFX_MFCDLG_H__11CC3DC8_1499_4B79_BF1B_797FA9A357B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCDlg dialog

class CMFCDlg : public CDialog
{
// Construction
public:
	void readDb();
	CMFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCDlg)
	enum { IDD = IDD_MFC_DIALOG };
	CListCtrl	m_list;
	CString	m_age;
	CString	m_name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onadd();
	afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Ondel();
	afx_msg void Onmodify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDLG_H__11CC3DC8_1499_4B79_BF1B_797FA9A357B9__INCLUDED_)
