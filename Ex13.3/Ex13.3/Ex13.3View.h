
// Ex13.3View.h : CEx133View ��Ľӿ�
//

#pragma once

class CEx133Set;

class CEx133View : public CRecordView
{
protected: // �������л�����
	CEx133View();
	DECLARE_DYNCREATE(CEx133View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX133_FORM };
#endif
	CEx133Set* m_pSet;

// ����
public:
	CEx133Doc* GetDocument() const;

// ����
public:
	long change;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CEx133View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long m_1;
	long m_2;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // Ex13.3View.cpp �еĵ��԰汾
inline CEx133Doc* CEx133View::GetDocument() const
   { return reinterpret_cast<CEx133Doc*>(m_pDocument); }
#endif

