
// Ex7.3View.h : CEx73View ��Ľӿ�
//

#pragma once


class CEx73View : public CView
{
protected: // �������л�����
	CEx73View();
	DECLARE_DYNCREATE(CEx73View)

// ����
public:
	CEx73Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx73View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex7.3View.cpp �еĵ��԰汾
inline CEx73Doc* CEx73View::GetDocument() const
   { return reinterpret_cast<CEx73Doc*>(m_pDocument); }
#endif

