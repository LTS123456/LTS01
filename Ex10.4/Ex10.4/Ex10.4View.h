
// Ex10.4View.h : CEx104View ��Ľӿ�
//

#pragma once

class CEx104Set;

class CEx104View : public CRecordView
{
protected: // �������л�����
	CEx104View();
	DECLARE_DYNCREATE(CEx104View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX104_FORM };
#endif
	CEx104Set* m_pSet;

// ����
public:
	CEx104Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CEx104View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	double ID;
	CString snum;
	CString sname;
	double age;
	double telenum;
};

#ifndef _DEBUG  // Ex10.4View.cpp �еĵ��԰汾
inline CEx104Doc* CEx104View::GetDocument() const
   { return reinterpret_cast<CEx104Doc*>(m_pDocument); }
#endif

