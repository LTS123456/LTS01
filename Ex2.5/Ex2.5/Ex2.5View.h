
// Ex2.5View.h : CEx25View ��Ľӿ�
//

#pragma once


class CEx25View : public CView
{
protected: // �������л�����
	CEx25View();
	DECLARE_DYNCREATE(CEx25View)

// ����
public:
	CEx25Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx25View();
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

#ifndef _DEBUG  // Ex2.5View.cpp �еĵ��԰汾
inline CEx25Doc* CEx25View::GetDocument() const
   { return reinterpret_cast<CEx25Doc*>(m_pDocument); }
#endif

