// DBLogic.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "DBLogic.h"
#include "global.h"
#include "DBEntity.h"

// CDBLogic

IMPLEMENT_DYNAMIC(CDBLogic, CWnd)

CDBLogic::CDBLogic()
{

}

CDBLogic::~CDBLogic()
{
}


BEGIN_MESSAGE_MAP(CDBLogic, CWnd)
END_MESSAGE_MAP()



// CDBLogic 消息处理程序


bool CDBLogic::CreateDatabase(CString databasename)
{
	CFile file;
	CString filepath="Output\\"+databasename+".db.txt";
	CString dicPath="Output\\data\\"+databasename;
	if(file.Open(filepath,CFile::modeReadWrite | CFile::shareExclusive)==FALSE)
	{
		AfxMessageBox(_T("该数据库不存在，系统将新建数据库"));
		file.Open(filepath,CFile::modeReadWrite | CFile::modeCreate | CFile::shareExclusive);
		CreateDirectory(dicPath, NULL);
	
	DatabaseBlock block;
	block.name=databasename;
	if(databasename.Compare(_T("Ruanko"))==0)
	    block.type=false;
	else
		block.type=true;
	block.filename=dicPath;
	SYSTEMTIME time;
	GetLocalTime(&time);
	block.crtime=time;
	

	CString line="\r\n";
	CString s;
	file.Write(block.name,block.name.GetLength());
	file.Write(line,line.GetLength());

	if(block.type==true) s="true";
	else                 s="false";
	file.Write(s,s.GetLength());
	file.Write(line,line.GetLength());

	file.Write(block.filename,block.filename.GetLength());
	file.Write(line,line.GetLength());

	char msg[9];
	sprintf(msg,"%0.4d%0.2d%0.2d",block.crtime.wYear,block.crtime.wMonth,block.crtime.wDay);
	s.Format(_T("%s"),msg);
	file.Write(s,s.GetLength());
	file.Write(line,line.GetLength());
	file.Close();
	s="Output\\data\\"+databasename+"\\"+databasename+".tb.txt";
	file.Open(s,CFile::modeReadWrite | CFile::modeCreate | CFile::shareExclusive);
	
	}
	else
	{
		AfxMessageBox(_T("原数据库已存在！"));
		return false;
	}
	file.Close();
	return true;
}