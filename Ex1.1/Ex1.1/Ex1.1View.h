
// Ex1.1View.h : CEx11View ��Ľӿ�
//

#pragma once


class CEx11View : public CView
{
protected: // �������л�����
	CEx11View();
	DECLARE_DYNCREATE(CEx11View)

// ����
public:
	CEx11Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx11View();
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
};

#ifndef _DEBUG  // Ex1.1View.cpp �еĵ��԰汾
inline CEx11Doc* CEx11View::GetDocument() const
   { return reinterpret_cast<CEx11Doc*>(m_pDocument); }
#endif

