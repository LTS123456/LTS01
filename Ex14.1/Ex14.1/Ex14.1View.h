
// Ex14.1View.h : CEx141View ��Ľӿ�
//

#pragma once

class CEx141Set;

class CEx141View : public CRecordView
{
protected: // �������л�����
	CEx141View();
	DECLARE_DYNCREATE(CEx141View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX141_FORM };
#endif
	CEx141Set* m_pSet;

// ����
public:
	CEx141Doc* GetDocument() const;

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
	virtual ~CEx141View();
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
	CString m_num;
	CString m_name;
	double m_age;
	double m_tele;
	CString path;
	afx_msg void OnBnClickedButton1();
	afx_msg void foo(CImage& img, int& sx, int& sy, int& w, int& h);
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	afx_msg void OnSerch();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLine();
	afx_msg void OnShow();
};

#ifndef _DEBUG  // Ex14.1View.cpp �еĵ��԰汾
inline CEx141Doc* CEx141View::GetDocument() const
   { return reinterpret_cast<CEx141Doc*>(m_pDocument); }
#endif

