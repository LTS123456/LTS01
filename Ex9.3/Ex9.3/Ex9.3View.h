
// Ex9.3View.h : CEx93View ��Ľӿ�
//

#pragma once


class CEx93View : public CView
{
protected: // �������л�����
	CEx93View();
	DECLARE_DYNCREATE(CEx93View)

// ����
public:
	CEx93Doc* GetDocument() const;

// ����
public:
	CRect cr;
	CArray<CRect, CRect> a;
	int count=0;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx93View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnFileOpen();
//	afx_msg void OnClose();
};

#ifndef _DEBUG  // Ex9.3View.cpp �еĵ��԰汾
inline CEx93Doc* CEx93View::GetDocument() const
   { return reinterpret_cast<CEx93Doc*>(m_pDocument); }
#endif

