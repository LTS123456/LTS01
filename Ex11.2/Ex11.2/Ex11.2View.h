
// Ex11.2View.h : CEx112View ��Ľӿ�
//

#pragma once

class CEx112Set;

class CEx112View : public CRecordView
{
protected: // �������л�����
	CEx112View();
	DECLARE_DYNCREATE(CEx112View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX112_FORM };
#endif
	CEx112Set* m_pSet;

// ����
public:
	CEx112Doc* GetDocument() const;

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
	virtual ~CEx112View();
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
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // Ex11.2View.cpp �еĵ��԰汾
inline CEx112Doc* CEx112View::GetDocument() const
   { return reinterpret_cast<CEx112Doc*>(m_pDocument); }
#endif

