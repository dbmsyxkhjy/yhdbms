// DeleteRecord.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DBMS.h"
#include "DeleteRecord.h"
#include "afxdialogex.h"


// CDeleteRecord �Ի���

IMPLEMENT_DYNAMIC(CDeleteRecord, CDialogEx)

CDeleteRecord::CDeleteRecord(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeleteRecord::IDD, pParent)
{

}

CDeleteRecord::~CDeleteRecord()
{
}

void CDeleteRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
}


BEGIN_MESSAGE_MAP(CDeleteRecord, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteRecord::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDeleteRecord ��Ϣ�������


void CDeleteRecord::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int x=m_list.GetSelectionMark();
	if(x==-1)
	{
		AfxMessageBox(_T("��ѡ��ɾ���ļ�¼"));
		return;
	}
	CString filepath="Output\\data\\"+db+"\\"+tb+".trd.txt";
	CString filepath2="Output\\data\\"+db+"\\"+"temp.txt";

	FILE *file,*file2;
	file=fopen(filepath,"r");
	file2=fopen(filepath2,"w");

	char m[20];
	memset(m,0,20*sizeof(char));
	int u=0;
	while(fscanf(file,"%s",m)!=EOF)
	{
		if(u==x)
		{
			for(int i=1;i<index;i++)
				fscanf(file,"%s",m);
		}
		else
		{
			CString kong=" ";
			fwrite(m,strlen(m),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
			for(int i=1;i<index;i++)
			{
				fscanf(file,"%s",m);
				fwrite(m,strlen(m),1,file2);
			    fwrite(kong,kong.GetLength(),1,file2);
			}
		}
		CString line="\r\n";
		fwrite(line,line.GetLength(),1,file2);
		u++;
	}
	fclose(file);
	fclose(file2);
	remove(filepath);
	rename(filepath2,filepath);

	m_list.DeleteAllItems();
	int num=m_list.GetHeaderCtrl()->GetItemCount();
	for(int i=0;i<num;i++)
	m_list.DeleteColumn(0);
	OnInitDialog();
	AfxMessageBox(_T("��¼ɾ���ɹ���"));

}


BOOL CDeleteRecord::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT; 
	dwStyle |= LVS_EX_GRIDLINES;             // Displays gridlines around items and subitems. This style is available only in conjunction with the LVS_REPORT style.
	dwStyle |= LVS_EX_HEADERDRAGDROP;        // Enables drag-and-drop reordering of columns in a list-view control. This style is only available to list-view controls that use the LVS_REPORT style.
	m_list.SetExtendedStyle(dwStyle); 


	FILE *file;
	CString filepath="Output\\data\\"+db+"\\"+tb+".tdf.txt";
	file=fopen(filepath,"r");

	char m[20];
	memset(m,0,20*sizeof(char));

	index=0;//�����ĸ���
	while(fscanf(file,"%s",m)!=EOF)
	{
	m_list.InsertColumn(index, m, LVCFMT_LEFT, 100);
	index++;
	}
	fclose(file);

	filepath="Output\\data\\"+db+"\\"+tb+".trd.txt";
	file=fopen(filepath,"r");
	index2=0;//��¼������
	while(fscanf(file,"%s",m)!=EOF)
	{
		m_list.InsertItem(index2, _T(""));
		m_list.SetItemText(index2, 0,m);
		for(int i=1;i<index;i++)
		{
		fscanf(file,"%s",m);
		m_list.SetItemText(index2, i,m);
		}
		index2++;
	}
	fclose(file);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
