
// Ex3.3View.h : CEx33View ��Ľӿ�
//

#pragma once


class CEx33View : public CView
{
protected: // �������л�����
	CEx33View();
	DECLARE_DYNCREATE(CEx33View)

// ����
public:
	CEx33Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx33View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex3.3View.cpp �еĵ��԰汾
inline CEx33Doc* CEx33View::GetDocument() const
   { return reinterpret_cast<CEx33Doc*>(m_pDocument); }
#endif

