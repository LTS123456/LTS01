
// Ex7.1View.h : CEx71View ��Ľӿ�
//

#pragma once


class CEx71View : public CView
{
protected: // �������л�����
	CEx71View();
	DECLARE_DYNCREATE(CEx71View)

// ����
public:
	CEx71Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx71View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex7.1View.cpp �еĵ��԰汾
inline CEx71Doc* CEx71View::GetDocument() const
   { return reinterpret_cast<CEx71Doc*>(m_pDocument); }
#endif

