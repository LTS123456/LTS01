
// Ex8.3View.h : CEx83View ��Ľӿ�
//

#pragma once


class CEx83View : public CView
{
protected: // �������л�����
	CEx83View();
	DECLARE_DYNCREATE(CEx83View)

// ����
public:
	CEx83Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx83View();
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

#ifndef _DEBUG  // Ex8.3View.cpp �еĵ��԰汾
inline CEx83Doc* CEx83View::GetDocument() const
   { return reinterpret_cast<CEx83Doc*>(m_pDocument); }
#endif

