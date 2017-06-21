// DeleteDatabase.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DBMS.h"
#include "DeleteDatabase.h"
#include "afxdialogex.h"
#include "DBView.h"
#include "MainFrm.h"

#include <stdio.h>  
#include <io.h>  
#include <string.h>  
#include <direct.h>  


// CDeleteDatabase �Ի���

IMPLEMENT_DYNAMIC(CDeleteDatabase, CDialogEx)

CDeleteDatabase::CDeleteDatabase(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG16, pParent)
{

}

CDeleteDatabase::~CDeleteDatabase()
{
}

void CDeleteDatabase::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeleteDatabase, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDeleteDatabase::OnBnClickedOk)
END_MESSAGE_MAP()


// CDeleteDatabase ��Ϣ�������


int CDeleteDatabase::removeDir(const char * dirPath)
{
	struct _finddata_t fb;   //������ͬ�����ļ��Ĵ洢�ṹ��  
	char  path[250];
	long    handle;
	int  resultone;
	int   noFile;            //��ϵͳ�����ļ��Ĵ�����  

	noFile = 0;
	handle = 0;


	//����·��  
	strcpy(path, dirPath);
	strcat(path, "/*");

	handle = _findfirst(path, &fb);
	//�ҵ���һ��ƥ����ļ�  
	if (handle != 0)
	{
		//�����Լ����ҵ�ƥ����ļ�������ִ��  
		while (0 == _findnext(handle, &fb))
		{
			//windows�£����и�ϵͳ�ļ�����Ϊ��..��,������������  
			noFile = strcmp(fb.name, "..");

			if (0 != noFile)
			{
				//��������·��  
				memset(path, 0, sizeof(path));
				strcpy(path, dirPath);
				strcat(path, "/");
				strcat(path, fb.name);
				//����ֵΪ16����˵�����ļ��У�����  
				if (fb.attrib == 16)
				{
					removeDir(path);
				}
				//���ļ��е��ļ���ֱ��ɾ�������ļ�����ֵ�����û����ϸ���飬���ܻ������������  
				else
				{
					remove(path);
				}
			}
		}
		//�ر��ļ��У�ֻ�йر��˲���ɾ����������������˺ܾã���׼c���õ���closedir  
		//������ܣ�һ�����Handle�ĺ���ִ�к󣬶�Ҫ���йرյĶ�����  
		_findclose(handle);
	}
	//�Ƴ��ļ���  
	resultone = rmdir(dirPath);
	return  resultone;
}

void CDeleteDatabase::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	CMainFrame *pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CDBView *pView = (CDBView *)pMain->GetActiveView();

	pView->deleteDB();
}
