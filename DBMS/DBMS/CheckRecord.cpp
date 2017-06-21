// CheckRecord.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DBMS.h"
#include "CheckRecord.h"
#include "afxdialogex.h"
#include <io.h>

// CCheckRecord �Ի���

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


// CCheckRecord ��Ϣ�������


void CCheckRecord::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s1,s2;
	m_edit1.GetWindowText(s1);
	m_edit2.GetWindowText(s2);
	CString filepath="Output\\data\\"+s1+"\\"+s2+".tdf.txt";
	if(access(filepath,0)!=0)
	{
		AfxMessageBox(_T("���ʧ��,��������Ч�����ƣ�"));
		return;
	}
	CAddRecord a;
	a.db=s1;
	a.tb=s2;
	a.DoModal();
}
