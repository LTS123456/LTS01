
// Ex6.2View.h : CEx62View ��Ľӿ�
//

#pragma once


class CEx62View : public CView
{
protected: // �������л�����
	CEx62View();
	DECLARE_DYNCREATE(CEx62View)

// ����
public:
	CEx62Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx62View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex6.2View.cpp �еĵ��԰汾
inline CEx62Doc* CEx62View::GetDocument() const
   { return reinterpret_cast<CEx62Doc*>(m_pDocument); }
#endif

