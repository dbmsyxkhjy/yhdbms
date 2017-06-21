// OpenDB.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "OpenDB.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "DBView.h"
// COpenDB 对话框

IMPLEMENT_DYNAMIC(COpenDB, CDialogEx)

COpenDB::COpenDB(CWnd* pParent /*=NULL*/)
	: CDialogEx(COpenDB::IDD, pParent)
{

}

COpenDB::~COpenDB()
{
}

void COpenDB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(COpenDB, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &COpenDB::OnBnClickedButton1)
END_MESSAGE_MAP()


// COpenDB 消息处理程序


void COpenDB::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	m_edit.GetWindowText(s);

	 CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
     CDBView *pView=(CDBView *)pMain->GetActiveView();

	 FILE *file;
	 CString s2;
	 s2="Output\\"+s+".db.txt";
	 if((file=fopen(s2,"r"))!=NULL)
	 {
		 pView->openDB(s);
		  fclose(file);
		  SetWindowText(s);
	 }
	 else
	 {
		 AfxMessageBox(_T("该数据库不存在！"));
	 }
}
