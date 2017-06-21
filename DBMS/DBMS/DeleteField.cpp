// DeleteField.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "DeleteField.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "DBView.h"

// CDeleteField 对话框

IMPLEMENT_DYNAMIC(CDeleteField, CDialogEx)

CDeleteField::CDeleteField(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeleteField::IDD, pParent)
{

}

CDeleteField::~CDeleteField()
{
}

void CDeleteField::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeleteField, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteField::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDeleteField 消息处理程序


void CDeleteField::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	 CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
     CDBView *pView=(CDBView *)pMain->GetActiveView();

	 pView->deleteField();
}
