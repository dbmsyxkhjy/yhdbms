#pragma once


// CDBListView ��ͼ

class CDBListView : public CListView
{
	DECLARE_DYNCREATE(CDBListView)

protected:
	CDBListView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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


