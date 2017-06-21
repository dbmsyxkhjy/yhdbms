// MFC学生信息管理系统Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC学生信息管理系统.h"
#include "MFC学生信息管理系统Dlg.h"
#include<afxdao.h>//dao操作来实现数据库的读写
#include<comdef.h>//在数据格式转换的时候会用到
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CDaoDatabase db;//数据库
CDaoRecordset Dbset(&db);//记录集，有了它才能进行读写以及删除操作
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCDlg dialog

CMFCDlg::CMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCDlg)
	m_age = _T("");
	m_name = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON);
}

void CMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Text(pDX, IDC_age, m_age);
	DDV_MaxChars(pDX, m_age, 3);
	DDX_Text(pDX, IDC_name, m_name);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_add, Onadd)
	ON_NOTIFY(NM_CLICK, IDC_LIST, OnClickList)
	ON_BN_CLICKED(IDC_del, Ondel)
	ON_BN_CLICKED(IDC_modify, Onmodify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCDlg message handlers

BOOL CMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);//设置扩展样式
	m_list.InsertColumn(0,"姓名",LVCFMT_LEFT,227,0);//添加姓名项
	m_list.InsertColumn(1,"年龄",LVCFMT_LEFT,227,1);//添加年龄项
	// TODO: Add extra initialization here
	readDb();//在初始化函数中，如果没有找到数据库文件就创建，并且在列表中显示出来
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCDlg::readDb()
{
CString Filepath="Data.mdb";//将数据库文件Data.mdb在程序的同一目录下
CFileFind Ffind;//先看看存不存在数据库文件
BOOL flag=Ffind.FindFile(Filepath);
Ffind.Close();
if(!flag)//如果没有，我们就创建
{
	db.Create(Filepath);
	CString sqlcmd="CREATE TABLE DataTable(Name VARCHAR(20),Age VARCHAR(3))";//创建内部表，并设置两个属性（姓名,年龄）
	db.Execute(sqlcmd);//执行sql指令
	db.Close();//创建完成一定要关闭，否则出错
	MessageBox("数据库已建立成功!","温情提示");
}
_variant_t varname;
COleVariant varage;
CString Sname,Sage;
int i=0;
db.Open(Filepath);
Dbset.Open(AFX_DAO_USE_DEFAULT_TYPE,"SELECT * FROM DataTable",0);
while(!Dbset.IsEOF())
{
	varname=Dbset.GetFieldValue("Name");
	Dbset.GetFieldValue("Age",varage);
	Sname=(LPCSTR)_bstr_t(varname);
	Sage=(LPCSTR)varage.pbstrVal;//分别将数据库里面读出来的文件转换成CString
	m_list.InsertItem(i,"");
	m_list.SetItemText(i,0,Sname);
	m_list.SetItemText(i,1,Sage);
	Dbset.MoveNext();//这一句千万别忘了，否则就不能循环，就会卡在刚才那种状况
	i++;
}
Dbset.Close();
db.Close();
}

void CMFCDlg::Onadd() 
{
	UpdateData(true);
	if(m_name.IsEmpty()||m_age.IsEmpty())//如果输入框为空，则提示信息
	{
		MessageBox("信息不能为空!","温情提示");
	}
	else
	{
		CString Filepath="Data.mdb";
		int i=m_list.GetItemCount();//在列表的队尾添加，所以先获取行数
		db.Open(Filepath);
		Dbset.Open(AFX_DAO_USE_DEFAULT_TYPE,"SELECT * FROM DataTable",0);
		Dbset.AddNew();//在记录集的队尾添加
		Dbset.SetFieldValue("Name",_variant_t(m_name));
		Dbset.SetFieldValue("Age",atol(m_age));//将CString格式转换成数据库规定的格式
		Dbset.Update();//一定要及时更新
		Dbset.Close();
		db.Close();//并关闭
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,0,m_name);
		m_list.SetItemText(i,1,m_age);//在列表里显示
	}
}

void CMFCDlg::OnClickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int pos=m_list.GetSelectionMark();
	m_name=m_list.GetItemText(pos,0);
	m_age=m_list.GetItemText(pos,1);
	UpdateData(false);
	*pResult=0;
}

void CMFCDlg::Ondel() 
{
int pos=m_list.GetSelectionMark();//所选中行的索引号
if(!(pos+1))//如果没有选中从第一行到最后一行，则提示选中先
{
	MessageBox("请先选择需要删除的一行!","温情提示");
}	
else
{
	CString Filepath="Data.mdb";
	db.Open(Filepath);
	Dbset.Open(AFX_DAO_USE_DEFAULT_TYPE,"SELECT *FROM DataTable",0);
	Dbset.Move(pos);//将记录集的指针移动到当前数据的索引处
	Dbset.Delete();//删除数据
	Dbset.Close();
	db.Close();
	m_list.DeleteAllItems();
	readDb();//最后两句的作用是刷新列表，自己领会！！！O(∩_∩)O哈哈~
}
}

void CMFCDlg::Onmodify() 
{
UpdateData(true);
int pos=m_list.GetSelectionMark();
if(!(pos+1))	
{
	MessageBox("请先选择需要修改的行!","温情提示");
}
else
{
	CString Filepath="Data.mdb";
	db.Open(Filepath);
	Dbset.Open(AFX_DAO_USE_DEFAULT_TYPE,"SELECT * FROM DataTable",0);
	Dbset.Move(pos);
	Dbset.Edit();//将指针移动到所选项后，将数据至于编辑状态
	Dbset.SetFieldValue("Name",_variant_t(m_name));
	Dbset.SetFieldValue("Age",atol(m_age));
	Dbset.Update();//记得修改完以后要更新，否则会出错
	Dbset.Close();
	db.Close();
    m_list.DeleteAllItems();
	readDb();
}
}
