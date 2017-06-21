
// DBMS.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "DBMS.h"
#include "MainFrm.h"

#include "DBMSDoc.h"
#include "DBMSView.h"
#include "CreateDB.h"
#include "OpenDB.h"
#include "AddTable.h"
#include "ModifyTable.h"
#include "OpenTable.h"
#include "DeleteTable.h"
#include "AddField.h"
#include "ModifyField.h"
#include "DeleteField.h"
#include "CheckRecord.h"
#include "CheckRecord2.h"
#include "CheckRecord3.h"
#include "DeleteDatabase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDBMSApp

BEGIN_MESSAGE_MAP(CDBMSApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CDBMSApp::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_CreateDatabase, &CDBMSApp::OnCreatedatabase)
	ON_COMMAND(ID_OpenDatabase, &CDBMSApp::OnOpendatabase)
	ON_COMMAND(ID_NewTable, &CDBMSApp::OnNewtable)
	ON_COMMAND(ID_ModifyTable, &CDBMSApp::OnModifytable)
	ON_COMMAND(ID_OpenTable, &CDBMSApp::OnOpentable)
	ON_COMMAND(ID_DeleteTable, &CDBMSApp::OnDeletetable)
	ON_COMMAND(ID_AddField, &CDBMSApp::OnAddfield)
	ON_COMMAND(ID_ModifyField, &CDBMSApp::OnModifyfield)
	ON_COMMAND(ID_DeleteField, &CDBMSApp::OnDeletefield)
	ON_COMMAND(ID_AddRecord, &CDBMSApp::OnAddrecord)
	ON_COMMAND(ID_ModifyRecord, &CDBMSApp::OnModifyrecord)
	ON_COMMAND(ID_DeleteRecord, &CDBMSApp::OnDeleterecord)
	ON_COMMAND(ID_DATABASE_DELETEDATABASE, &CDBMSApp::OnDatabaseDeletedatabase)
END_MESSAGE_MAP()


// CDBMSApp ����

CDBMSApp::CDBMSApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���:
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("DBMS.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CDBMSApp ����

CDBMSApp theApp;


// CDBMSApp ��ʼ��

BOOL CDBMSApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)


	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CDBMSDoc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
		RUNTIME_CLASS(CDBMSView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// ������׼ shell ���DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand ֮����
	return TRUE;
}

int CDBMSApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CDBMSApp ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CDBMSApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CDBMSApp ��Ϣ�������





void CDBMSApp::OnCreatedatabase()
{
	// TODO: �ڴ���������������
	CCreateDB a;
	a.DoModal();
}


void CDBMSApp::OnOpendatabase()
{
	// TODO: �ڴ���������������
	COpenDB a;
	a.DoModal();
	
}


void CDBMSApp::OnNewtable()
{
	// TODO: �ڴ���������������
	CAddTable a;
	a.DoModal();

}


void CDBMSApp::OnModifytable()
{
	// TODO: �ڴ���������������
	
	CModifyTable a;
	a.DoModal();
}


void CDBMSApp::OnOpentable()
{
	// TODO: �ڴ���������������
	COpenTable a;
	a.DoModal();
}


void CDBMSApp::OnDeletetable()
{
	// TODO: �ڴ���������������
	CDeleteTable a;
	a.DoModal();
}


void CDBMSApp::OnAddfield()
{
	// TODO: �ڴ���������������
	CAddField a;
	a.DoModal();
}


void CDBMSApp::OnModifyfield()
{
	// TODO: �ڴ���������������
	CModifyField a;
	a.DoModal();
}


void CDBMSApp::OnDeletefield()
{
	// TODO: �ڴ���������������
	CDeleteField a;
	a.DoModal();
}


void CDBMSApp::OnAddrecord()
{
	// TODO: �ڴ���������������
	CCheckRecord a;
	a.DoModal();


}


void CDBMSApp::OnModifyrecord()
{
	// TODO: �ڴ���������������
	CCheckRecord2 a;
	a.DoModal();
}


void CDBMSApp::OnDeleterecord()
{
	// TODO: �ڴ���������������
	CCheckRecord3 a;
	a.DoModal();
}


void CDBMSApp::OnDatabaseDeletedatabase()
{
	// TODO: �ڴ���������������
	CDeleteDatabase a;
	a.DoModal();
}
