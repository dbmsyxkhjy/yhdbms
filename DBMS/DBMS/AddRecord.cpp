// AddRecord.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DBMS.h"
#include "AddRecord.h"
#include "afxdialogex.h"


// CAddRecord �Ի���

IMPLEMENT_DYNAMIC(CAddRecord, CDialogEx)

CAddRecord::CAddRecord(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddRecord::IDD, pParent)
{

}

CAddRecord::~CAddRecord()
{
}

void CAddRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_EDIT3, m_edit);
}


BEGIN_MESSAGE_MAP(CAddRecord, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddRecord::OnBnClickedButton1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &CAddRecord::OnNMDblclkList2)
	ON_EN_KILLFOCUS(IDC_EDIT3, &CAddRecord::OnEnKillfocusEdit3)
END_MESSAGE_MAP()


// CAddRecord ��Ϣ�������


BOOL CAddRecord::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_edit.ShowWindow(SW_HIDE);

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT; 
	dwStyle |= LVS_EX_GRIDLINES;             // Displays gridlines around items and subitems. This style is available only in conjunction with the LVS_REPORT style.
	dwStyle |= LVS_EX_HEADERDRAGDROP;        // Enables drag-and-drop reordering of columns in a list-view control. This style is only available to list-view controls that use the LVS_REPORT style.
	m_list.SetExtendedStyle(dwStyle); 

	m_list.InsertColumn(0,_T("�ֶ�����"),LVCFMT_LEFT,100);
	m_list.InsertColumn(1,_T("�ֶ�����"),LVCFMT_LEFT,100);
	m_list.InsertColumn(2,_T("��Ϊ��"),LVCFMT_LEFT,100);
	m_list.InsertColumn(3,_T("ֵ"),LVCFMT_LEFT,100);
	m_list.InsertColumn(4,_T("Default"),LVCFMT_LEFT,100);


	FILE *file;
	CString filepath="Output\\data\\"+db+"\\"+tb+".tic.txt";
	file=fopen(filepath,"r");

	char m[20];
	memset(m,0,20*sizeof(char));
	num=0;
	while(fscanf(file,"%s",m)!=EOF)
	{
		m_list.InsertItem(num,_T(""));
		m_list.SetItemText(num,0,m);
		fscanf(file,"%s",m);
		m_list.SetItemText(num,1,m);
		fscanf(file,"%s",m);
		fscanf(file,"%s",m);
		if(strcmp(m,"1")==0)
		{
			m_list.SetItemText(num,2,_T("��"));
		}
		else
		{
			m_list.SetItemText(num,2,_T("��"));
		}
		m_list.SetItemText(num,3,_T(""));
		fscanf(file,"%s",m);
		m_list.SetItemText(num,4,m);
		num++;
	}
	fclose(file);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CAddRecord::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filepath="Output\\data\\"+db+"\\"+tb+".trd.txt";
	FILE *file;
	file=fopen(filepath,"a+");
	char m[20];
	memset(m,0,20*sizeof(char));
	for(int i=0;i<num;i++)
	{
		CString kong=" ";
		CString s;
		s=m_list.GetItemText(i,3);
		if(!s.IsEmpty())
		{
		fwrite(s,s.GetLength(),1,file);
		fwrite(kong,kong.GetLength(),1,file);
		}
		else
		{
			CString s2;
			s2=m_list.GetItemText(i,4);
			fwrite(s2,s2.GetLength(),1,file);
		fwrite(kong,kong.GetLength(),1,file);
		}
	}
	CString line="\r\n";
	fwrite(line,line.GetLength(),1,file);
	fclose(file);
	m_list.DeleteAllItems();
	int num=m_list.GetHeaderCtrl()->GetItemCount();
	for(int i=0;i<num;i++)
	m_list.DeleteColumn(0);
	OnInitDialog();
	AfxMessageBox(_T("��Ӽ�¼�ɹ���"));

}




void CAddRecord::OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	m_Row = pNMListView->iItem;//���ѡ�е���
	m_Col = pNMListView->iSubItem;//���ѡ����



		m_list.GetSubItemRect(m_Row,m_Col,LVIR_LABEL,rc);//��������RECT��
		m_edit.SetParent(&m_list);//ת������Ϊ�б���е�����
		m_edit.MoveWindow(rc);//�ƶ�Edit��RECT���ڵ�λ��;
		m_edit.SetWindowText(m_list.GetItemText(m_Row,m_Col));//���������е�ֵ����Edit�ؼ��У�
		m_edit.ShowWindow(SW_SHOW);//��ʾEdit�ؼ���
		m_edit.SetFocus();//����Edit����
		m_edit.ShowCaret();//��ʾ���
		m_edit.SetSel(-1);//������ƶ������


	


	*pResult = 0;
}


void CAddRecord::OnEnKillfocusEdit3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tem;
	m_edit.GetWindowText(tem);    //�õ��û�������µ�����
	m_list.SetItemText(m_Row,m_Col,tem);   //���ñ༭���������
	m_edit.ShowWindow(SW_HIDE);                //���ر༭��
}
