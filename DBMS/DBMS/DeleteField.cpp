// DeleteField.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DBMS.h"
#include "DeleteField.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "DBView.h"

// CDeleteField �Ի���

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


// CDeleteField ��Ϣ�������


void CDeleteField::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
     CDBView *pView=(CDBView *)pMain->GetActiveView();

	 pView->deleteField();
}
