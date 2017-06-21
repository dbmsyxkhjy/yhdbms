// CreateDB.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "CreateDB.h"
#include "afxdialogex.h"
#include "DBLogic.h"
#include "DBView.h"
#include "MainFrm.h"
// CCreateDB 对话框

IMPLEMENT_DYNAMIC(CCreateDB, CDialogEx)

CCreateDB::CCreateDB(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCreateDB::IDD, pParent)
{

}

CCreateDB::~CCreateDB()
{
}

void CCreateDB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CCreateDB, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCreateDB::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCreateDB 消息处理程序


void CCreateDB::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	m_edit.GetWindowText(s);

	CDBLogic logic;
	bool m;
	m=logic.CreateDatabase(s);
	if(m==true)
	{
    CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
    CDBView *pView=(CDBView *)pMain->GetActiveView();
    pView->showDB(s);
	}
}
