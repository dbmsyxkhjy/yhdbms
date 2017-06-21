#pragma once


// CDBListView 视图

class CDBListView : public CListView
{
	DECLARE_DYNCREATE(CDBListView)

protected:
	CDBListView();           // 动态创建所使用的受保护的构造函数
	virtual ~CDBListView();

public:
	void modifyTable(CString s1,CString s2);
	void openTable(CString s1,CString s2);
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};


