
// Ex11.1View.h : CEx111View ��Ľӿ�
//

#pragma once

class CEx111Set;

class CEx111View : public CRecordView
{
protected: // �������л�����
	CEx111View();
	DECLARE_DYNCREATE(CEx111View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX111_FORM };
#endif
	CEx111Set* m_pSet;

// ����
public:
	CEx111Doc* GetDocument() const;

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
	virtual ~CEx111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void foo(CImage& img, int& sx, int& sy, int& w, int& h);
	DECLARE_MESSAGE_MAP()
public:
	double ID;
	CString m_num;
	CString m_name;
	double m_age;
	double m_tele;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // Ex11.1View.cpp �еĵ��԰汾
inline CEx111Doc* CEx111View::GetDocument() const
   { return reinterpret_cast<CEx111Doc*>(m_pDocument); }
#endif

