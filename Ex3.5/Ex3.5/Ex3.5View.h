
// Ex3.5View.h : CEx35View ��Ľӿ�
//

#pragma once


class CEx35View : public CView
{
protected: // �������л�����
	CEx35View();
	DECLARE_DYNCREATE(CEx35View)

// ����
public:
	CEx35Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx35View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex3.5View.cpp �еĵ��԰汾
inline CEx35Doc* CEx35View::GetDocument() const
   { return reinterpret_cast<CEx35Doc*>(m_pDocument); }
#endif

