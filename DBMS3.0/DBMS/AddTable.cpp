// AddTable.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "AddTable.h"
#include "afxdialogex.h"
#include "DBView.h"
#include "MainFrm.h"

// CAddTable 对话框

IMPLEMENT_DYNAMIC(CAddTable, CDialogEx)

CAddTable::CAddTable(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddTable::IDD, pParent)
{

}

CAddTable::~CAddTable()
{
}

void CAddTable::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CAddTable, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddTable::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAddTable 消息处理程序


void CAddTable::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	 CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
     CDBView *pView=(CDBView *)pMain->GetActiveView();

	 CString s;
	 m_edit.GetWindowText(s);

	 pView->addTable(s);
}
