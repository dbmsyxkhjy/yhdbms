// DBView.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "DBView.h"
#include <io.h>
#include "AddRecord.h"
#include "DeleteDatabase.h"

// CDBView

IMPLEMENT_DYNCREATE(CDBView, CTreeView)

CDBView::CDBView()
{

}

CDBView::~CDBView()
{
}

/*BEGIN_MESSAGE_MAP(CDBView, CTreeView)
	ON_COMMAND(ID_CreateDatabase, &CDBView::OnCreatedatabase)
END_MESSAGE_MAP()*/


// CDBView 诊断

#ifdef _DEBUG
void CDBView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CDBView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDBView 消息处理程序


void CDBView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	//Get the treeCtrl associated with CTreeView
	CTreeCtrl &treeCtrl = GetTreeCtrl();
	//Modify the style of the treeCtrl
	treeCtrl.ModifyStyle(0, TVS_HASLINES | TVS_LINESATROOT | TVS_EDITLABELS | TVS_HASBUTTONS);
	// Load ICON
	m_treeImageList.Create(16, 16, ILC_MASK, 4, 1);
	m_treeImageList.Add(AfxGetApp()->LoadIcon(IDI_ROOT));
	m_treeImageList.Add(AfxGetApp()->LoadIcon(IDI_TABLE));
	m_treeImageList.Add(AfxGetApp()->LoadIcon(IDI_LIE));
	//Associate ICON with the control
	treeCtrl.SetImageList(&m_treeImageList, TVSIL_NORMAL);

	HTREEITEM hFirstNode1 = treeCtrl.InsertItem(_T("Ruanko"), 0, 0);
	FILE *file,*file2;
	char m[20];
	memset(m,0,20*sizeof(char));
	file=fopen("Output\\data\\Ruanko\\Ruanko.tb.txt","r");

	while(fscanf(file,"%s",m)!=EOF)
	{
		
		HTREEITEM ss = treeCtrl.InsertItem(m, 1, 1, hFirstNode1);
		CString s1,s2;
		s2.Format(_T("%s"),m);
		s1="Output\\data\\Ruanko\\"+s2+".tdf.txt";
		
		if((file2=fopen(s1,"r"))!=NULL)
		{
			while(fscanf(file2,"%s",m)!=EOF)
			{
				
				HTREEITEM ss2 = treeCtrl.InsertItem(m, 2, 2,ss);
			}
					fclose(file2);
		}

	}

	treeCtrl.Expand(hFirstNode1, TVE_EXPAND);
    fclose(file);
}



void  CDBView::addTreeNode(CString s,int i)
{
	CTreeCtrl &treeCtrl = GetTreeCtrl();

	HTREEITEM hItem = treeCtrl.GetSelectedItem();
	treeCtrl.InsertItem(s,i, i, hItem); //Add an item named Adding
	treeCtrl.Expand(hItem, TVE_EXPAND);    //Expand the selected item and its child items
}

void  CDBView::deleteTreeNode()
{
	CTreeCtrl &treeCtrl = GetTreeCtrl();
	//Get the current selected node
	HTREEITEM hItem = treeCtrl.GetSelectedItem();
	//Delete the node and its child node
	treeCtrl.DeleteItem(hItem);
}

void CDBView::showDB(CString s)
{
	CTreeCtrl &treeCtrl = GetTreeCtrl();
	//Modify the style of the treeCtrl
	treeCtrl.ModifyStyle(0, TVS_HASLINES | TVS_LINESATROOT | TVS_EDITLABELS | TVS_HASBUTTONS);

	HTREEITEM hFirstNode1 = treeCtrl.InsertItem(s, 0, 0);
	FILE *file;
	char m[20];
	memset(m,0,20*sizeof(char));
	CString s2;
	s2="Output\\data\\"+s+"\\"+s+".tb.txt";
	file=fopen(s2,"r");

	while(fscanf(file,"%s",m)!=EOF)
	{
		
		HTREEITEM ss = treeCtrl.InsertItem(m, 1, 1, hFirstNode1);

	}

	treeCtrl.Expand(hFirstNode1, TVE_EXPAND);
    fclose(file);
}

void CDBView::openDB(CString s)
{
	CTreeCtrl &treeCtrl = GetTreeCtrl();
	treeCtrl.ModifyStyle(0, TVS_HASLINES | TVS_LINESATROOT | TVS_EDITLABELS | TVS_HASBUTTONS);

	HTREEITEM hFirstNode1 = treeCtrl.InsertItem(s, 0, 0);

	FILE *file,*file2;
	char m[20];
	memset(m,0,20*sizeof(char));
	CString s2;
	s2="Output\\data\\"+s+"\\"+s+".tb.txt";
	file=fopen(s2,"r");

	while(fscanf(file,"%s",m)!=EOF)
	{
		HTREEITEM ss = treeCtrl.InsertItem(m, 1, 1, hFirstNode1);
		CString s3;
		s3="Output\\data\\"+s+"\\"+m+".tdf.txt";
		if((file2=fopen(s3,"r"))!=NULL)
		{
			while(fscanf(file2,"%s",m)!=EOF)
			{
				
				HTREEITEM ss2 = treeCtrl.InsertItem(m, 2, 2,ss);
			}
					fclose(file2);
		}


	}

	treeCtrl.Expand(hFirstNode1, TVE_EXPAND);
    fclose(file);
	AfxMessageBox(_T("打开成功！"));
}

void CDBView::deleteDB()
{
	CTreeCtrl &treeCtrl = GetTreeCtrl();
	HTREEITEM hItem = treeCtrl.GetSelectedItem();

	CString s1;
	s1 = treeCtrl.GetItemText(hItem);
	CString filepath1 = "Output\\" + s1 + ".db.txt";
	CString filepath2 = "Output\\data\\" + s1;
	if (access(filepath1, 0) != 0)
	{
		AfxMessageBox(_T("删除失败!请在左边树状图选取有效的数据库！"));
		return;
	}

	remove(filepath1);
	CDeleteDatabase de;
	int abc = de.removeDir(filepath2);

	deleteTreeNode();

	AfxMessageBox(_T("数据库删除成功！"));
}

void CDBView::addTable(CString s)
{
	CTreeCtrl &treeCtrl = GetTreeCtrl();

	HTREEITEM hItem = treeCtrl.GetSelectedItem();
	CString s2;
	s2=treeCtrl.GetItemText(hItem);
	
	FILE *file;
	CString filepath="Output\\data\\"+s2+"\\"+s2+".tb.txt";
	if(access(filepath,0)==-1)
	{
		AfxMessageBox(_T("添加失败，请在左边的树状结构中选取有效的数据库名称！"));
		return;
	}
	file=fopen(filepath,"r+");
    char m[20];
	memset(m,0,20*sizeof(char));
	if(fscanf(file,"%s",m)==EOF)
	{
	fwrite(s,s.GetLength(),1,file);
	CString line="\r\n";
	fwrite(line,line.GetLength(),1,file);
	}
	else
	{
		do{
		CString s3;
		s3.Format(_T("%s"),m);
		if(s3.Compare(s)==0)
		{
			AfxMessageBox(_T("创建失败,同名表格已存在！"));
			return;
		}
		   }while(fscanf(file,"%s",m)!=EOF);
	CString line="\r\n";
	fwrite(s,s.GetLength(),1,file);
	fwrite(line,line.GetLength(),1,file);
	}
  
	fclose(file);

	filepath="Output\\data\\"+s2+"\\"+s+".tdf.txt";
	file=fopen(filepath,"w");
	fclose(file);

	filepath="Output\\data\\"+s2+"\\"+s+".tic.txt";
	file=fopen(filepath,"w");
	fclose(file);

	filepath="Output\\data\\"+s2+"\\"+s+".trd.txt";
	file=fopen(filepath,"w");
	fclose(file);

	addTreeNode(s,1);
	AfxMessageBox(_T("添加表格成功！"));

	
}

/*void CDBView::modifyTable(CString s)
{
	
	CTreeCtrl &treeCtrl = GetTreeCtrl();
	HTREEITEM hItem = treeCtrl.GetSelectedItem();

	HTREEITEM hItem2=treeCtrl.GetParentItem(hItem);

	CString s2,s4;
	s2=treeCtrl.GetItemText(hItem2);
	s4=treeCtrl.GetItemText(hItem);
	CString filepath;
	filepath="Output\\"+s2+".db.txt";

	if(access(filepath,0)==-1)
	{
		AfxMessageBox(_T("修改失败，选择的项并非是数据库名称！"));
		return;
	}

	FILE *file,*file2;
	filepath="Output\\data\\"+s2+"\\"+"table.ds.txt";
	CString filepath2="Output\\data\\"+s2+"\\"+"table2.ds.txt";
	file=fopen(filepath,"r");
	file2=fopen(filepath2,"w");

	 char m[20];
	memset(m,0,20*sizeof(char));

	while(fscanf(file,"%s",m)!=EOF)
	{
		CString s3;
		s3.Format(_T("%s"),m);
		if(s3.Compare(s4)!=0)
		{
			CString line="\r\n";
			fwrite(m,sizeof(m),1,file2);
			fwrite(line,line.GetLength(),1,file2);
		}
		else
		{
			CString line="\r\n";
			fwrite(s,s.GetLength(),1,file2);
			fwrite(line,line.GetLength(),1,file2);
		}
	}
	fclose(file);
	fclose(file2);
	remove(filepath);
    rename(filepath2,filepath);

	filepath="Output\\data\\"+s2+"\\"+s4+".ds.txt";
	if(access(filepath,0)!=-1)
	{
	filepath2="Output\\data\\"+s2+"\\"+s+".ds.txt";
	rename(filepath,filepath2);
	}
	treeCtrl.SetItemText(hItem,s);
	
	AfxMessageBox(_T("表格修改成功！"));
	
	
}*/


void CDBView::deleteTable()
{
	CTreeCtrl &treeCtrl = GetTreeCtrl();
	HTREEITEM hItem = treeCtrl.GetSelectedItem();

	HTREEITEM hItem2=treeCtrl.GetParentItem(hItem);

	CString s1,s2;
	s1=treeCtrl.GetItemText(hItem2);
	s2=treeCtrl.GetItemText(hItem);
	CString filepath="Output\\data\\"+s1+"\\"+s2+".tdf.txt";
	if(access(filepath,0)!=0)
	{
		AfxMessageBox(_T("删除失败!请在左边树状图选取有效的表名！"));
		return;
	}
	FILE *file,*file2;
	CString filepath1="Output\\data\\"+s1+"\\"+s1+".tb.txt";
	CString filepath2="Output\\data\\"+s1+"\\"+"temp.txt";

	file=fopen(filepath1,"r");
	file2=fopen(filepath2,"w");
	
	char m[20];
	memset(m,0,20*sizeof(char));

	while(fscanf(file,"%s",m)!=EOF)
	{
		CString s3;
		s3.Format(_T("%s"),m);
		if(s3.Compare(s2)!=0)
		{
			CString line="\r\n";
			fwrite(m,strlen(m),1,file2);
			fwrite(line,line.GetLength(),1,file2);
		}
		else
		{
		}
	}
	fclose(file);
	fclose(file2);
	remove(filepath1);
    rename(filepath2,filepath1);
	filepath="Output\\data\\"+s1+"\\"+s2+".tdf.txt";
	remove(filepath);
	filepath="Output\\data\\"+s1+"\\"+s2+".tic.txt";
	remove(filepath);
	filepath="Output\\data\\"+s1+"\\"+s2+".trd.txt";
	remove(filepath);

	//删除左边树的节点
	deleteTreeNode();

	AfxMessageBox(_T("表格删除成功！"));
}

void CDBView::addField(CString s1,CString s2,int primary,int notnull,CString s3)
{
	CTreeCtrl &treeCtrl = GetTreeCtrl();
	HTREEITEM hItem = treeCtrl.GetSelectedItem();

	HTREEITEM hItem2=treeCtrl.GetParentItem(hItem);

	CString s4,s5;
	int number=0;//记录属性个数
	s4=treeCtrl.GetItemText(hItem2);//数据库名
	s5=treeCtrl.GetItemText(hItem);//表格名
	CString filepath="Output\\data\\"+s4+"\\"+s5+".tdf.txt";
	if(access(filepath,0)!=0)
	{
		AfxMessageBox(_T("添加失败!请在左边树状图选取有效的表名！"));
		return;
	}
	int n;
	FILE *file;
	
	
	CFile fl;
		if(fl.Open(filepath,CFile::modeReadWrite | CFile::shareExclusive)==FALSE)
		{
			return;
			
		}
		int a;
		a=fl.GetLength();
		fl.Close();
		file=fopen(filepath,"r");
		if(a==0)
		{
			n=0;//文件内容为空
		}
	else 
	{
		n=1;//文件内容不空
		char t[20];
		memset(t,0,20*sizeof(char));
		while(fscanf(file,"%s",t)!=EOF)
		{
			number++;
		}
	}
	fclose(file);
	file=fopen(filepath,"a");
	if(n==1)
	{
	CString line="\r\n";
	
	fwrite(s1,s1.GetLength(),1,file);
	fwrite(line,line.GetLength(),1,file);
	fclose(file);
	filepath="Output\\data\\"+s4+"\\"+s5+".tic.txt";
	file=fopen(filepath,"a");
	CString kong=" ";
	CString p;
	
	fwrite(s1,s1.GetLength(),1,file);
	fwrite(kong,kong.GetLength(),1,file);
	fwrite(s2,s2.GetLength(),1,file);
	fwrite(kong,kong.GetLength(),1,file);
	p.Format(_T("%d"),primary);
	fwrite(p,p.GetLength(),1,file);
	fwrite(kong,kong.GetLength(),1,file);
	p.Format(_T("%d"),notnull);
	fwrite(p,p.GetLength(),1,file);
	fwrite(kong,kong.GetLength(),1,file);
	fwrite(s3,s3.GetLength(),1,file);
	fwrite(line,line.GetLength(),1,file);
	fclose(file);

    //修改记录
	FILE *file2;
	filepath="Output\\data\\"+s4+"\\"+s5+".trd.txt";
	CString filepath2="Output\\data\\"+s4+"\\temp.txt";
	file=fopen(filepath,"r");
	file2=fopen(filepath2,"w");

	char m[20];
	memset(m,0,20*sizeof(char));
	while(fscanf(file,"%s",m)!=EOF)
	{
		fwrite(m,strlen(m),1,file2);
		fwrite(kong,kong.GetLength(),1,file2);
		for(int i=1;i<number;i++)
		{
			fscanf(file,"%s",m);
			fwrite(m,strlen(m),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
		}
		fwrite(s3,s3.GetLength(),1,file2);
		fwrite(line,line.GetLength(),1,file2);
	}

	fclose(file);
	fclose(file2);
	remove(filepath);
    rename(filepath2,filepath);
	
	}
	else//为空
	{
		CString line="\r\n";
	
	fwrite(s1,s1.GetLength(),1,file);
	fwrite(line,line.GetLength(),1,file);
		fclose(file);
	filepath="Output\\data\\"+s4+"\\"+s5+".tic.txt";
	file=fopen(filepath,"w+");
	CString kong=" ";
	CString p;
 
	fwrite(s1,s1.GetLength(),1,file);
	fwrite(kong,kong.GetLength(),1,file);
	fwrite(s2,s2.GetLength(),1,file);
	fwrite(kong,kong.GetLength(),1,file);
	p.Format(_T("%d"),primary);
	fwrite(p,p.GetLength(),1,file);
	fwrite(kong,kong.GetLength(),1,file);
	p.Format(_T("%d"),notnull);
	fwrite(p,p.GetLength(),1,file);
	fwrite(kong,kong.GetLength(),1,file);
	fwrite(s3,s3.GetLength(),1,file);
	fwrite(line,line.GetLength(),1,file);
	fclose(file);
	}

	//修改树节点
	addTreeNode(s1,2);
	AfxMessageBox(_T("添加成功！"));
}

void CDBView::modifyField(CString s1,CString s2,int primary,int notnull,CString s3)
{
	CTreeCtrl &treeCtrl = GetTreeCtrl();
	HTREEITEM hItem = treeCtrl.GetSelectedItem();
	HTREEITEM hItem2=treeCtrl.GetParentItem(hItem);
	HTREEITEM hItem3=treeCtrl.GetParentItem(hItem2);

	CString s4,s5,s6;
	int number=0;//记录属性个数
	int index=0;//记录所修改的属性是第几个
	s4=treeCtrl.GetItemText(hItem3);//数据库名
	s5=treeCtrl.GetItemText(hItem2);//表格名
	s6=treeCtrl.GetItemText(hItem);//列名
	CString filepath="Output\\data\\"+s4+"\\"+s5+".tdf.txt";
	if(access(filepath,0)!=0)
	{
		AfxMessageBox(_T("添加失败!请在左边树状图选取有效的字段名！"));
		return;
	}
	FILE *f;
	f=fopen(filepath,"r");
		CString t;
		while(fscanf(f,"%s",t)!=EOF)
		{
			number++;
		}
		fseek(f,0,SEEK_SET);
		while(fscanf(f,"%s",t)!=EOF)
		{
			if(t.Compare(s6)==0)
			{
				index++;
				break;
			}
			else
				index++;
		}
	
	fclose(f);
	CString m1,m2,m3,m4,m5;
	FILE *file,*file2;
	filepath="Output\\data\\"+s4+"\\"+s5+".tic.txt";
	CString filepath2="Output\\data\\"+s4+"\\"+s5+".trd.txt";


	if(m2.Compare(s2)!=0)
	{
		CFile fl;
		if(fl.Open(filepath2,CFile::modeReadWrite | CFile::shareExclusive)==FALSE)
		{
			return;
			
		}
		int a;
		a=fl.GetLength();

		if(a!=0)
		{
			AfxMessageBox(_T("修改失败,表中已经存在数据,无法修改字段类型！！！"));

			return;
		}
		fl.Close();
	}
	file=fopen(filepath,"r");
	file2=fopen(filepath2,"r");
	while(fscanf(file,"%s",m1)!=EOF)
	{
		if(m1.Compare(s6)==0)
		{
			fscanf(file,"%s",m2);
			fscanf(file,"%s",m3);
			fscanf(file,"%s",m4);
			fscanf(file,"%s",m5);
			break;
		}
	}
	
	if(m4.Compare("0")==0 && notnull==1)
	{
		char x[200];
		memset(x,0,200*sizeof(char));
		while(fgets(x,200,file2)!=NULL)
		{
			char *xx=NULL;
			int j=1;
			xx=strtok(x," ");
			while(j<index)
			{
				xx=strtok(NULL," ");
				j++;
			}
			if(strcmp(x,"\\")==0)
			{
				AfxMessageBox(_T("修改失败，表中已经存在该属性为空的记录，无法设置属性不为空！！！"));
				return;
			}
		}
	
	}
	fclose(file);
	fclose(file2);
	
	//开始修改字段
		filepath="Output\\data\\"+s4+"\\"+s5+".tdf.txt";
		filepath2="Output\\data\\"+s4+"\\temp2.txt";
		file=fopen(filepath,"r");
		file2=fopen(filepath2,"w");

		char sh[20];
		memset(sh,0,20*sizeof(char));
		while(fscanf(file,"%s",sh)!=EOF)
	{
	
		if(strcmp(sh,s6)!=0)
		{
			CString line="\r\n";

			
			fwrite(sh,strlen(sh),1,file2);
			fwrite(line,line.GetLength(),1,file2);

		}
		else
		{
			CString line="\r\n";
			fwrite(s1,s1.GetLength(),1,file2);
			fwrite(line,line.GetLength(),1,file2);
		}
	}
	fclose(file);
	fclose(file2);
	remove(filepath);
    rename(filepath2,filepath);

	filepath="Output\\data\\"+s4+"\\"+s5+".tic.txt";
	filepath2="Output\\data\\"+s4+"\\temp.txt";
	file=fopen(filepath,"r");
	file2=fopen(filepath2,"w");
	char m[200];
	int nn=0;
	memset(m,0,200*sizeof(char));
	while(fgets(m,200,file)!=NULL)
	{
		nn++;
		if(nn==index)
		{
			CString kong=" ";
			CString line="\r\n";
			CString tt;
			fwrite(s1,s1.GetLength(),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
			fwrite(s2,s2.GetLength(),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
			tt.Format(_T("%d"),primary);
			fwrite(tt,tt.GetLength(),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
			tt.Format(_T("%d"),notnull);
			fwrite(tt,tt.GetLength(),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
			fwrite(s3,s3.GetLength(),1,file2);
			fwrite(line,line.GetLength(),1,file2);
		}
		else
		{
			fwrite(m,strlen(m),1,file2);
		}
	}
	fclose(file);
	fclose(file2);
	remove(filepath);
    rename(filepath2,filepath);

	treeCtrl.SetItemText(hItem,s1);
	
	AfxMessageBox(_T("字段修改成功！"));
}


void CDBView::deleteField()
{
	CTreeCtrl &treeCtrl = GetTreeCtrl();
	HTREEITEM hItem = treeCtrl.GetSelectedItem();
	HTREEITEM hItem2=treeCtrl.GetParentItem(hItem);
	HTREEITEM hItem3=treeCtrl.GetParentItem(hItem2);

	CString s1,s2,s3;

	s1=treeCtrl.GetItemText(hItem3);//数据库名
	s2=treeCtrl.GetItemText(hItem2);//表格名
	s3=treeCtrl.GetItemText(hItem);//字段名

	CString filepath="Output\\data\\"+s1+"\\"+s2+".tdf.txt";
	if(access(filepath,0)!=0)
	{
		AfxMessageBox(_T("删除失败!请在左边树状图选取有效的字段名！"));
		return;
	}
	FILE *f;
	CString t;
	int number=0;
	int index=0;
	f=fopen(filepath,"r");
	while(fscanf(f,"%s",t)!=EOF)
		{
			number++;
		}
		fseek(f,0,SEEK_SET);
			while(fscanf(f,"%s",t)!=EOF)
		{
			if(t.Compare(s3)==0)
			{
				index++;
				break;
			}
			else
				index++;
		}
			fclose(f);

	FILE *file,*file2;
	CString filepath2="Output\\data\\"+s1+"\\temp.txt";
	file=fopen(filepath,"r");
	file2=fopen(filepath2,"w");
	char m[20];
	memset(m,0,20*sizeof(char));

	while(fscanf(file,"%s",m)!=EOF)
	{
		if(strcmp(m,s3)==0)
		{
		}
		else
		{
			CString line="\r\n";
			fwrite(m,strlen(m),1,file2);
			fwrite(line,line.GetLength(),1,file2);
		}
	}
	fclose(file);
	fclose(file2);
	remove(filepath);
	rename(filepath2,filepath);


	filepath="Output\\data\\"+s1+"\\"+s2+".tic.txt";
	file=fopen(filepath,"r");
	file2=fopen(filepath2,"w");
	char m1[20],m2[20],m3[20],m4[20],m5[20];
	memset(m1,0,20*sizeof(char));
	memset(m2,0,20*sizeof(char));
	memset(m3,0,20*sizeof(char));
	memset(m4,0,20*sizeof(char));
	memset(m5,0,20*sizeof(char));

	while(fscanf(file,"%s",m1)!=EOF)
	{
		fscanf(file,"%s",m2);
		fscanf(file,"%s",m3);
		fscanf(file,"%s",m4);
		fscanf(file,"%s",m5);
		if(strcmp(m1,s3)==0)
		{
		}
		else
		{
			CString kong=" ";
			CString line="\r\n";
			fwrite(m1,strlen(m1),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
			fwrite(m2,strlen(m2),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
			fwrite(m3,strlen(m3),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
			fwrite(m4,strlen(m4),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
			fwrite(m5,strlen(m5),1,file2);
			fwrite(line,line.GetLength(),1,file2);
		}
	}
	fclose(file);
	fclose(file2);
	remove(filepath);
	rename(filepath2,filepath);
	//删除该字段的记录
	filepath="Output\\data\\"+s1+"\\"+s2+".trd.txt";
	file=fopen(filepath,"r");
	file2=fopen(filepath2,"w");
	int x=0;
	while(fscanf(file,"%s",m1)!=EOF)
	{
		CString line="\r\n";
		CString kong=" ";
		x++;
		if(index!=number)
		{
		if(x==index)
		{
		}
		else if(x==number)
		{
			fwrite(m1,strlen(m1),1,file2);
			fwrite(line,line.GetLength(),1,file2);
			x=0;
		}
		else
		{
			fwrite(m1,strlen(m1),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
		}
		}
		else{
			if(x==index)
			{
				fwrite(line,line.GetLength(),1,file2);
				x=0;
			}
			else{
				fwrite(m1,strlen(m1),1,file2);
			fwrite(kong,kong.GetLength(),1,file2);
			}
		}
	}

	fclose(file);
	fclose(file2);
	remove(filepath);
	rename(filepath2,filepath);

	deleteTreeNode();
	AfxMessageBox(_T("字段删除成功！"));
}

/*void CDBView::checkAddRecord()
{
	CTreeCtrl &treeCtrl = GetTreeCtrl();
	HTREEITEM hItem = treeCtrl.GetSelectedItem();

	HTREEITEM hItem2=treeCtrl.GetParentItem(hItem);

	CString s1,s2;
	int number=0;//记录属性个数
	s1=treeCtrl.GetItemText(hItem2);//数据库名
	s2=treeCtrl.GetItemText(hItem);//表格名
	CString filepath="Output\\data\\"+s1+"\\"+s2+".tdf.txt";
	if(access(filepath,0)!=0)
	{
		AfxMessageBox(_T("添加失败,请在左边树状图选取有效的表名！"));
		return;
	}



	CAddRecord a;
	a.DoModal();
}*/