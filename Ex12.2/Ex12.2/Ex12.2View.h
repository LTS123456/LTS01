
// Ex12.2View.h : CEx122View ��Ľӿ�
//

#pragma once

class CEx122Set;

class CEx122View : public CRecordView
{
protected: // �������л�����
	CEx122View();
	DECLARE_DYNCREATE(CEx122View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX122_FORM };
#endif
	CEx122Set* m_pSet;

// ����
public:
	CEx122Doc* GetDocument() const;

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
	virtual ~CEx122View();
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
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // Ex12.2View.cpp �еĵ��԰汾
inline CEx122Doc* CEx122View::GetDocument() const
   { return reinterpret_cast<CEx122Doc*>(m_pDocument); }
#endif

