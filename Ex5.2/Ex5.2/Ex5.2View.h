
// Ex5.2View.h : CEx52View ��Ľӿ�
//

#pragma once


class CEx52View : public CView
{
protected: // �������л�����
	CEx52View();
	DECLARE_DYNCREATE(CEx52View)

// ����
public:
	CEx52Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx52View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
	afx_msg void OnShowbmp();
	afx_msg void OnDrawline();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawrectangle();
	afx_msg void OnDrawellipse();
};

#ifndef _DEBUG  // Ex5.2View.cpp �еĵ��԰汾
inline CEx52Doc* CEx52View::GetDocument() const
   { return reinterpret_cast<CEx52Doc*>(m_pDocument); }
#endif

