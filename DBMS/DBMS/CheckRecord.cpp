// CheckRecord.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "CheckRecord.h"
#include "afxdialogex.h"
#include <io.h>

// CCheckRecord 对话框

IMPLEMENT_DYNAMIC(CCheckRecord, CDialogEx)

CCheckRecord::CCheckRecord(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCheckRecord::IDD, pParent)
{

}

CCheckRecord::~CCheckRecord()
{
}

void CCheckRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
}


BEGIN_MESSAGE_MAP(CCheckRecord, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCheckRecord::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCheckRecord 消息处理程序


void CCheckRecord::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s1,s2;
	m_edit1.GetWindowText(s1);
	m_edit2.GetWindowText(s2);
	CString filepath="Output\\data\\"+s1+"\\"+s2+".tdf.txt";
	if(access(filepath,0)!=0)
	{
		AfxMessageBox(_T("添加失败,请输入有效的名称！"));
		return;
	}
	CAddRecord a;
	a.db=s1;
	a.tb=s2;
	a.DoModal();
}
