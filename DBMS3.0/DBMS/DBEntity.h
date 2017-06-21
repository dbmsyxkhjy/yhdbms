#pragma once
#ifndef _DBENTITY_H_
#define _DBENTITY_H_



// CDBEntity

class CDBEntity : public CWnd
{
	DECLARE_DYNAMIC(CDBEntity)

public:
	CDBEntity();

	CString getName();
	bool getType();
	CString getFilepath();
	SYSTEMTIME getCrtime();

	void setName(CString name);
	void setType(bool type);
	void setFilepath(CString filepath);
	void setCrtime(SYSTEMTIME crtime);
	virtual ~CDBEntity();

protected:
	DECLARE_MESSAGE_MAP()

	CString m_name;
	bool m_type;
	CString m_filePath;
	SYSTEMTIME m_crtime;


	
};

#endif
