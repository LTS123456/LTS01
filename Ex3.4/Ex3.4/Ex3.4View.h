
// Ex3.4View.h : CEx34View ��Ľӿ�
//

#pragma once


class CEx34View : public CView
{
protected: // �������л�����
	CEx34View();
	DECLARE_DYNCREATE(CEx34View)

// ����
public:
	CEx34Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx34View();
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

#ifndef _DEBUG  // Ex3.4View.cpp �еĵ��԰汾
inline CEx34Doc* CEx34View::GetDocument() const
   { return reinterpret_cast<CEx34Doc*>(m_pDocument); }
#endif

