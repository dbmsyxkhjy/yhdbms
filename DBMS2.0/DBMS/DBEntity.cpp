// DBEntity.cpp : 实现文件
//

#include "stdafx.h"
#include "DBMS.h"
#include "DBEntity.h"


// CDBEntity

IMPLEMENT_DYNAMIC(CDBEntity, CWnd)

CDBEntity::CDBEntity()
{

}

CDBEntity::~CDBEntity()
{
}


BEGIN_MESSAGE_MAP(CDBEntity, CWnd)
END_MESSAGE_MAP()



// CDBEntity 消息处理程序


CString CDBEntity::getName()
{
	return m_name;
}
CString CDBEntity::getFilepath()
{
	return m_filePath;
}
bool CDBEntity::getType()
{
	return m_type;
}
SYSTEMTIME CDBEntity::getCrtime()
{
	return m_crtime;
}

void CDBEntity::setName(CString name)
{
	m_name=name;
}
void CDBEntity::setType(bool type)
{
	m_type=type;
}
void CDBEntity::setFilepath(CString filepath)
{
	m_filePath=filepath;
}
void CDBEntity::setCrtime(SYSTEMTIME crtime)
{
	m_crtime=crtime;
}