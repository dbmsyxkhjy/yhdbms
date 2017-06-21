// ModifyRecord.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "ModifyRecord.h"
#include "afxdialogex.h"


// CModifyRecord 对话框

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


// CModifyRecord 消息处理程序


void CModifyRecord::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
	AfxMessageBox(_T("记录修改成功！"));
}


BOOL CModifyRecord::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
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

	index=0;//列名的个数
	while(fscanf(file,"%s",m)!=EOF)
	{
	m_list.InsertColumn(index, m, LVCFMT_LEFT, 100);
	index++;
	}
	fclose(file);

	filepath="Output\\data\\"+db+"\\"+tb+".trd.txt";
	file=fopen(filepath,"r");
	index2=0;//记录的条数
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
	// 异常: OCX 属性页应返回 FALSE
}


void CModifyRecord::OnEnKillfocusEdit3()
{
	// TODO: 在此添加控件通知处理程序代码
		CString tem;
	m_edit.GetWindowText(tem);    //得到用户输入的新的内容
	m_list.SetItemText(m_Row,m_Col,tem);   //设置编辑框的新内容
	m_edit.ShowWindow(SW_HIDE);                //隐藏编辑框
}


void CModifyRecord::OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)
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


void CModifyRecord::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
