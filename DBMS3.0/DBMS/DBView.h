
#pragma once


// CDBView 视图

class CDBView : public CTreeView
{
	DECLARE_DYNCREATE(CDBView)

protected:
	          // 动态创建所使用的受保护的构造函数
		CDBView(); 
	virtual ~CDBView();

public:

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif


public:
	CImageList  m_treeImageList;
	virtual void OnInitialUpdate();

	void addTreeNode(CString s,int i);
	void deleteTreeNode();
	void showDB(CString s);
	void openDB(CString s);
	void addTable(CString s);
	void deleteTable();
	void addField(CString s1,CString s2,int primary,int notnull,CString s3);
	void modifyField(CString s1,CString s2,int primary,int notnull,CString s3);
	void deleteField();
	void CDBView::deleteDB();
	
};


