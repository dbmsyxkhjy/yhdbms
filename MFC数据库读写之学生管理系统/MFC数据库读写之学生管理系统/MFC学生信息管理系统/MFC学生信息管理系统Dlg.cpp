// MFCѧ����Ϣ����ϵͳDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCѧ����Ϣ����ϵͳ.h"
#include "MFCѧ����Ϣ����ϵͳDlg.h"
#include<afxdao.h>//dao������ʵ�����ݿ�Ķ�д
#include<comdef.h>//�����ݸ�ʽת����ʱ����õ�
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CDaoDatabase db;//���ݿ�
CDaoRecordset Dbset(&db);//��¼�������������ܽ��ж�д�Լ�ɾ������
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
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);//������չ��ʽ
	m_list.InsertColumn(0,"����",LVCFMT_LEFT,227,0);//���������
	m_list.InsertColumn(1,"����",LVCFMT_LEFT,227,1);//���������
	// TODO: Add extra initialization here
	readDb();//�ڳ�ʼ�������У����û���ҵ����ݿ��ļ��ʹ������������б�����ʾ����
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
CString Filepath="Data.mdb";//�����ݿ��ļ�Data.mdb�ڳ����ͬһĿ¼��
CFileFind Ffind;//�ȿ����治�������ݿ��ļ�
BOOL flag=Ffind.FindFile(Filepath);
Ffind.Close();
if(!flag)//���û�У����Ǿʹ���
{
	db.Create(Filepath);
	CString sqlcmd="CREATE TABLE DataTable(Name VARCHAR(20),Age VARCHAR(3))";//�����ڲ����������������ԣ�����,���䣩
	db.Execute(sqlcmd);//ִ��sqlָ��
	db.Close();//�������һ��Ҫ�رգ��������
	MessageBox("���ݿ��ѽ����ɹ�!","������ʾ");
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
	Sage=(LPCSTR)varage.pbstrVal;//�ֱ����ݿ�������������ļ�ת����CString
	m_list.InsertItem(i,"");
	m_list.SetItemText(i,0,Sname);
	m_list.SetItemText(i,1,Sage);
	Dbset.MoveNext();//��һ��ǧ������ˣ�����Ͳ���ѭ�����ͻῨ�ڸղ�����״��
	i++;
}
Dbset.Close();
db.Close();
}

void CMFCDlg::Onadd() 
{
	UpdateData(true);
	if(m_name.IsEmpty()||m_age.IsEmpty())//��������Ϊ�գ�����ʾ��Ϣ
	{
		MessageBox("��Ϣ����Ϊ��!","������ʾ");
	}
	else
	{
		CString Filepath="Data.mdb";
		int i=m_list.GetItemCount();//���б�Ķ�β��ӣ������Ȼ�ȡ����
		db.Open(Filepath);
		Dbset.Open(AFX_DAO_USE_DEFAULT_TYPE,"SELECT * FROM DataTable",0);
		Dbset.AddNew();//�ڼ�¼���Ķ�β���
		Dbset.SetFieldValue("Name",_variant_t(m_name));
		Dbset.SetFieldValue("Age",atol(m_age));//��CString��ʽת�������ݿ�涨�ĸ�ʽ
		Dbset.Update();//һ��Ҫ��ʱ����
		Dbset.Close();
		db.Close();//���ر�
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,0,m_name);
		m_list.SetItemText(i,1,m_age);//���б�����ʾ
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
int pos=m_list.GetSelectionMark();//��ѡ���е�������
if(!(pos+1))//���û��ѡ�дӵ�һ�е����һ�У�����ʾѡ����
{
	MessageBox("����ѡ����Ҫɾ����һ��!","������ʾ");
}	
else
{
	CString Filepath="Data.mdb";
	db.Open(Filepath);
	Dbset.Open(AFX_DAO_USE_DEFAULT_TYPE,"SELECT *FROM DataTable",0);
	Dbset.Move(pos);//����¼����ָ���ƶ�����ǰ���ݵ�������
	Dbset.Delete();//ɾ������
	Dbset.Close();
	db.Close();
	m_list.DeleteAllItems();
	readDb();//��������������ˢ���б��Լ���ᣡ����O(��_��)O����~
}
}

void CMFCDlg::Onmodify() 
{
UpdateData(true);
int pos=m_list.GetSelectionMark();
if(!(pos+1))	
{
	MessageBox("����ѡ����Ҫ�޸ĵ���!","������ʾ");
}
else
{
	CString Filepath="Data.mdb";
	db.Open(Filepath);
	Dbset.Open(AFX_DAO_USE_DEFAULT_TYPE,"SELECT * FROM DataTable",0);
	Dbset.Move(pos);
	Dbset.Edit();//��ָ���ƶ�����ѡ��󣬽��������ڱ༭״̬
	Dbset.SetFieldValue("Name",_variant_t(m_name));
	Dbset.SetFieldValue("Age",atol(m_age));
	Dbset.Update();//�ǵ��޸����Ժ�Ҫ���£���������
	Dbset.Close();
	db.Close();
    m_list.DeleteAllItems();
	readDb();
}
}
