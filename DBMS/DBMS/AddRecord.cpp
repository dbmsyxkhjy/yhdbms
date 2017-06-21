// AddRecord.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "AddRecord.h"
#include "afxdialogex.h"


// CAddRecord 对话框

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


// CAddRecord 消息处理程序


BOOL CAddRecord::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_edit.ShowWindow(SW_HIDE);

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT; 
	dwStyle |= LVS_EX_GRIDLINES;             // Displays gridlines around items and subitems. This style is available only in conjunction with the LVS_REPORT style.
	dwStyle |= LVS_EX_HEADERDRAGDROP;        // Enables drag-and-drop reordering of columns in a list-view control. This style is only available to list-view controls that use the LVS_REPORT style.
	m_list.SetExtendedStyle(dwStyle); 

	m_list.InsertColumn(0,_T("字段名称"),LVCFMT_LEFT,100);
	m_list.InsertColumn(1,_T("字段类型"),LVCFMT_LEFT,100);
	m_list.InsertColumn(2,_T("不为空"),LVCFMT_LEFT,100);
	m_list.InsertColumn(3,_T("值"),LVCFMT_LEFT,100);
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
			m_list.SetItemText(num,2,_T("是"));
		}
		else
		{
			m_list.SetItemText(num,2,_T("否"));
		}
		m_list.SetItemText(num,3,_T(""));
		fscanf(file,"%s",m);
		m_list.SetItemText(num,4,m);
		num++;
	}
	fclose(file);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CAddRecord::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
	AfxMessageBox(_T("添加记录成功！"));

}




void CAddRecord::OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	m_Row = pNMListView->iItem;//获得选中的行
	m_Col = pNMListView->iSubItem;//获得选中列



		m_list.GetSubItemRect(m_Row,m_Col,LVIR_LABEL,rc);//获得子项的RECT；
		m_edit.SetParent(&m_list);//转换坐标为列表框中的坐标
		m_edit.MoveWindow(rc);//移动Edit到RECT坐在的位置;
		m_edit.SetWindowText(m_list.GetItemText(m_Row,m_Col));//将该子项中的值放在Edit控件中；
		m_edit.ShowWindow(SW_SHOW);//显示Edit控件；
		m_edit.SetFocus();//设置Edit焦点
		m_edit.ShowCaret();//显示光标
		m_edit.SetSel(-1);//将光标移动到最后


	


	*pResult = 0;
}


void CAddRecord::OnEnKillfocusEdit3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tem;
	m_edit.GetWindowText(tem);    //得到用户输入的新的内容
	m_list.SetItemText(m_Row,m_Col,tem);   //设置编辑框的新内容
	m_edit.ShowWindow(SW_HIDE);                //隐藏编辑框
}
