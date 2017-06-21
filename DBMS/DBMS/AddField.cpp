// AddField.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "AddField.h"
#include "afxdialogex.h"
#include "DBView.h"
#include "MainFrm.h"

// CAddField 对话框

IMPLEMENT_DYNAMIC(CAddField, CDialogEx)

CAddField::CAddField(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddField::IDD, pParent)
{

}

CAddField::~CAddField()
{
}

void CAddField::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
}


BEGIN_MESSAGE_MAP(CAddField, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddField::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAddField 消息处理程序


void CAddField::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s1,s2,s3;//s1是名称，s2是字段类型，s3是默认值
	int primary,NotNull;
	m_edit1.GetWindowText(s1);
	m_edit2.GetWindowText(s3);
	m_combo.GetWindowText(s2);

	if(s3.IsEmpty())
	{
		s3="\\";
	}
	if(m_check1.GetCheck()==1)
		primary=1;
	else primary=0;

	if(m_check2.GetCheck()==1)
		NotNull=1;
	else NotNull=0;

	if(primary==1&&NotNull==0)
	{
		AfxMessageBox(_T("添加失败，主键必须不为空！"));
		return;
	}

	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
    CDBView *pView=(CDBView *)pMain->GetActiveView();

	pView->addField(s1,s2,primary,NotNull,s3);
}


BOOL CAddField::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_combo.AddString(_T("INTEGER"));
	m_combo.AddString(_T("VARCHAR"));
	m_combo.AddString(_T("BOOL"));
	m_combo.AddString(_T("DOUBLE"));
	m_combo.AddString(_T("SYSTEMTIME"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
