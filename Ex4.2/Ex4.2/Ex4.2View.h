
// Ex4.2View.h : CEx42View ��Ľӿ�
//

#pragma once


class CEx42View : public CView
{
protected: // �������л�����
	CEx42View();
	DECLARE_DYNCREATE(CEx42View)

// ����
public:
	CEx42Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx42View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex4.2View.cpp �еĵ��԰汾
inline CEx42Doc* CEx42View::GetDocument() const
   { return reinterpret_cast<CEx42Doc*>(m_pDocument); }
#endif

