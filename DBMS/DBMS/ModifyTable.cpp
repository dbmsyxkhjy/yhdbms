// ModifyTable.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "ModifyTable.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "DBListView.h"

// CModifyTable 对话框

IMPLEMENT_DYNAMIC(CModifyTable, CDialogEx)

CModifyTable::CModifyTable(CWnd* pParent /*=NULL*/)
	: CDialogEx(CModifyTable::IDD, pParent)
{

}

CModifyTable::~CModifyTable()
{
}

void CModifyTable::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_edit1);
	DDX_Control(pDX, IDC_EDIT1, m_edit2);
}


BEGIN_MESSAGE_MAP(CModifyTable, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CModifyTable::OnBnClickedButton1)
END_MESSAGE_MAP()


// CModifyTable 消息处理程序


void CModifyTable::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	 CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
     CDBListView *pView=(CDBListView *)pMain->listview;

	 CString s1,s2;
	 m_edit1.GetWindowText(s1);
	 m_edit2.GetWindowText(s2);

	 pView->modifyTable(s1,s2);
	 
}
