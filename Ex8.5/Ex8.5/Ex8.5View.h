
// Ex8.5View.h : CEx85View ��Ľӿ�
//

#pragma once


class CEx85View : public CView
{
protected: // �������л�����
	CEx85View();
	DECLARE_DYNCREATE(CEx85View)

// ����
public:
	CEx85Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx85View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex8.5View.cpp �еĵ��԰汾
inline CEx85Doc* CEx85View::GetDocument() const
   { return reinterpret_cast<CEx85Doc*>(m_pDocument); }
#endif

