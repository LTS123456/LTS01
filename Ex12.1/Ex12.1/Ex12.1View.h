
// Ex12.1View.h : CEx121View ��Ľӿ�
//

#pragma once

class CEx121Set;

class CEx121View : public CRecordView
{
protected: // �������л�����
	CEx121View();
	DECLARE_DYNCREATE(CEx121View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX121_FORM };
#endif
	CEx121Set* m_pSet;

// ����
public:
	CEx121Doc* GetDocument() const;

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
	virtual ~CEx121View();
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
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
//	afx_msg void OnPaint();
};

#ifndef _DEBUG  // Ex12.1View.cpp �еĵ��԰汾
inline CEx121Doc* CEx121View::GetDocument() const
   { return reinterpret_cast<CEx121Doc*>(m_pDocument); }
#endif

