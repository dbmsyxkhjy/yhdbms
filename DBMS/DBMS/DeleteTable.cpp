// DeleteTable.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DBMS.h"
#include "DeleteTable.h"
#include "afxdialogex.h"
#include "DBView.h"
#include "MainFrm.h"

// CDeleteTable �Ի���

IMPLEMENT_DYNAMIC(CDeleteTable, CDialogEx)

CDeleteTable::CDeleteTable(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeleteTable::IDD, pParent)
{

}

CDeleteTable::~CDeleteTable()
{
}

void CDeleteTable::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeleteTable, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteTable::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDeleteTable ��Ϣ�������


void CDeleteTable::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
     CDBView *pView=(CDBView *)pMain->GetActiveView();

	 pView->deleteTable();
}
