
// Ex4.1View.h : CEx41View ��Ľӿ�
//

#pragma once


class CEx41View : public CView
{
protected: // �������л�����
	CEx41View();
	DECLARE_DYNCREATE(CEx41View)

// ����
public:
	CEx41Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx41View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex4.1View.cpp �еĵ��԰汾
inline CEx41Doc* CEx41View::GetDocument() const
   { return reinterpret_cast<CEx41Doc*>(m_pDocument); }
#endif

