// CheckRecord2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DBMS.h"
#include "CheckRecord2.h"
#include "afxdialogex.h"
#include "ModifyRecord.h"
#include <io.h>

// CCheckRecord2 �Ի���

IMPLEMENT_DYNAMIC(CCheckRecord2, CDialogEx)

CCheckRecord2::CCheckRecord2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCheckRecord2::IDD, pParent)
{

}

CCheckRecord2::~CCheckRecord2()
{
}

void CCheckRecord2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
}


BEGIN_MESSAGE_MAP(CCheckRecord2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCheckRecord2::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCheckRecord2 ��Ϣ�������


void CCheckRecord2::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s1,s2;
	m_edit1.GetWindowText(s1);
	m_edit2.GetWindowText(s2);
	CString filepath="Output\\data\\"+s1+"\\"+s2+".tdf.txt";
	if(access(filepath,0)!=0)
	{
		AfxMessageBox(_T("�޸�ʧ��,��������Ч�����ƣ�"));
		return;
	}
	CModifyRecord a;
	a.db=s1;
	a.tb=s2;
	a.DoModal();
}
