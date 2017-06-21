// DBListView.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "DBListView.h"
#include <IO.h>

// CDBListView

IMPLEMENT_DYNCREATE(CDBListView, CListView)

CDBListView::CDBListView()
{

}

CDBListView::~CDBListView()
{
}

BEGIN_MESSAGE_MAP(CDBListView, CListView)
END_MESSAGE_MAP()


// CDBListView 诊断

#ifdef _DEBUG
void CDBListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CDBListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDBListView 消息处理程序


void CDBListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	// Get the ListCtrl associated with the ListView
	CListCtrl &listCtrl = GetListCtrl();

	// Add LVS_REPORT style to ListCtrl
	LONG lStyle;
	lStyle = ::GetWindowLong(listCtrl.m_hWnd, GWL_STYLE);   // Get the style of the current window
	lStyle |= LVS_REPORT;                                 
	::SetWindowLong(listCtrl.m_hWnd, GWL_STYLE, lStyle);    //Set style

	// Set the extended style of the ListCtrl
	DWORD dwStyle = listCtrl.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;         // When an item is selected, the item and all its subitems are highlighted. This style is available only in conjunction with the LVS_REPORT style.
	dwStyle |= LVS_EX_GRIDLINES;             // Displays gridlines around items and subitems. This style is available only in conjunction with the LVS_REPORT style.
	dwStyle |= LVS_EX_HEADERDRAGDROP;        // Enables drag-and-drop reordering of columns in a list-view control. This style is only available to list-view controls that use the LVS_REPORT style.
	listCtrl.SetExtendedStyle(dwStyle); 


	
}


void CDBListView::modifyTable(CString s1,CString s2)
{
	CListCtrl &listCtrl = GetListCtrl();
	listCtrl.DeleteAllItems();
	int num=listCtrl.GetHeaderCtrl()->GetItemCount();
	for(int i=0;i<num;i++)
	listCtrl.DeleteColumn(0);

    listCtrl.InsertColumn(0, _T("Field"), LVCFMT_LEFT, 100);
	listCtrl.InsertColumn(1, _T("Type"), LVCFMT_LEFT, 100);
	listCtrl.InsertColumn(2, _T("Primary_Key"), LVCFMT_LEFT, 100);
	listCtrl.InsertColumn(3, _T("NotNull"), LVCFMT_LEFT, 100);
	listCtrl.InsertColumn(4, _T("Default"), LVCFMT_LEFT, 100);

	//根据输入的数据库名和表名查找表结构
	FILE *file;
	CString filepath="Output\\data\\"+s1+"\\"+s2+".tic.txt";
	if(access(filepath,0)!=0)
	{
		AfxMessageBox(_T("对不起，输入的名称有误！"));
		return;
	}
	file=fopen(filepath,"r");
	char m[20];
	memset(m,0,20*sizeof(char));
	int index=0;
	while(fscanf(file,"%s",m)!=EOF)
	{
		listCtrl.InsertItem(index, _T(""));
		listCtrl.SetItemText(index, 0,m);
		fscanf(file,"%s",m);
		listCtrl.SetItemText(index, 1,m);
		fscanf(file,"%s",m);
		if(strcmp(m,"1")==0) 
		listCtrl.SetItemText(index, 2,"YES");
		else
        listCtrl.SetItemText(index, 2,"NO");
		fscanf(file,"%s",m);
		if(strcmp(m,"1")==0)
		listCtrl.SetItemText(index, 3,"YES");
		else
        listCtrl.SetItemText(index, 3,"NO");
		fscanf(file,"%s",m);
		if(strcmp(m,"\\")==0)
		listCtrl.SetItemText(index, 4,"NO Default!");
		else
        listCtrl.SetItemText(index, 4,m);
	}
	fclose(file);

	AfxMessageBox(_T("表属性获取成功！"));


}


void CDBListView::openTable(CString s1,CString s2)
{
	CListCtrl &listCtrl = GetListCtrl();
	listCtrl.DeleteAllItems();
	int num=listCtrl.GetHeaderCtrl()->GetItemCount();
	for(int i=0;i<num;i++)
	listCtrl.DeleteColumn(0);
	FILE *file;
	CString filepath="Output\\data\\"+s1+"\\"+s2+".tdf.txt";
	if(access(filepath,0)!=0)
	{
		AfxMessageBox(_T("对不起，输入的名称有误！"));
		return;
	}
	file=fopen(filepath,"r");
	char m[20];
	memset(m,0,20*sizeof(char));
	int index=0;
	while(fscanf(file,"%s",m)!=EOF)
	{
	listCtrl.InsertColumn(index, m, LVCFMT_LEFT, 100);
	index++;
	}
	fclose(file);

	filepath="Output\\data\\"+s1+"\\"+s2+".trd.txt";
	file=fopen(filepath,"r");
	int index2=0;
	while(fscanf(file,"%s",m)!=EOF)
	{
		listCtrl.InsertItem(index2, _T(""));
		listCtrl.SetItemText(index2, 0,m);
		for(int i=1;i<index;i++)
		{
		fscanf(file,"%s",m);
		listCtrl.SetItemText(index2, i,m);
		}
		index2++;
	}
	fclose(file);
	AfxMessageBox(_T("成功打开表格！"));
}