// ModifyRecord.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DBMS.h"
#include "ModifyRecord.h"
#include "afxdialogex.h"


// CModifyRecord �Ի���

IMPLEMENT_DYNAMIC(CModifyRecord, CDialogEx)

CModifyRecord::CModifyRecord(CWnd* pParent /*=NULL*/)
	: CDialogEx(CModifyRecord::IDD, pParent)
{

}

CModifyRecord::~CModifyRecord()
{
}

void CModifyRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_EDIT3, m_edit);
}


BEGIN_MESSAGE_MAP(CModifyRecord, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CModifyRecord::OnBnClickedButton1)
	ON_EN_KILLFOCUS(IDC_EDIT3, &CModifyRecord::OnEnKillfocusEdit3)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &CModifyRecord::OnNMDblclkList2)
	ON_EN_CHANGE(IDC_EDIT3, &CModifyRecord::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CModifyRecord ��Ϣ�������


void CModifyRecord::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filepath="Output\\data\\"+db+"\\"+tb+".trd.txt";
	CString filepath2="Output\\data\\"+db+"\\"+"temp.txt";
	FILE *file;

	file=fopen(filepath2,"w");
	char m[20];
	memset(m,0,20*sizeof(char));
	for(int i=0;i<index2;i++)
	{
		for(int j=0;j<index;j++)
		{
			CString s=m_list.GetItemText(i,j);
			CString kong=" ";
			fwrite(s,s.GetLength(),1,file);
			fwrite(kong,kong.GetLength(),1,file);
		}
		CString line="\r\n";
		fwrite(line,line.GetLength(),1,file);
	}
	fclose(file);
	remove(filepath);
	rename(filepath2,filepath);
	m_list.DeleteAllItems();
	int num=m_list.GetHeaderCtrl()->GetItemCount();
	for(int i=0;i<num;i++)
	m_list.DeleteColumn(0);
	OnInitDialog();
	AfxMessageBox(_T("��¼�޸ĳɹ���"));
}


BOOL CModifyRecord::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_edit.ShowWindow(SW_HIDE);

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


void CModifyRecord::OnEnKillfocusEdit3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		CString tem;
	m_edit.GetWindowText(tem);    //�õ��û�������µ�����
	m_list.SetItemText(m_Row,m_Col,tem);   //���ñ༭���������
	m_edit.ShowWindow(SW_HIDE);                //���ر༭��
}


void CModifyRecord::OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)
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


void CModifyRecord::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
