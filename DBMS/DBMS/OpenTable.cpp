// OpenTable.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "OpenTable.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "DBListView.h"


// COpenTable 对话框

IMPLEMENT_DYNAMIC(COpenTable, CDialogEx)

COpenTable::COpenTable(CWnd* pParent /*=NULL*/)
	: CDialogEx(COpenTable::IDD, pParent)
{

}

COpenTable::~COpenTable()
{
}

void COpenTable::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
}


BEGIN_MESSAGE_MAP(COpenTable, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &COpenTable::OnBnClickedButton1)
END_MESSAGE_MAP()


// COpenTable 消息处理程序


void COpenTable::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s1,s2;
	m_edit1.GetWindowText(s1);
	m_edit2.GetWindowText(s2);

	 CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
     CDBListView *pView=(CDBListView *)pMain->listview;
	 pView->openTable(s1,s2);
}
