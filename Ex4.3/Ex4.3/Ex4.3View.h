
// Ex4.3View.h : CEx43View ��Ľӿ�
//

#pragma once


class CEx43View : public CView
{
protected: // �������л�����
	CEx43View();
	DECLARE_DYNCREATE(CEx43View)

// ����
public:
	CEx43Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx43View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex4.3View.cpp �еĵ��԰汾
inline CEx43Doc* CEx43View::GetDocument() const
   { return reinterpret_cast<CEx43Doc*>(m_pDocument); }
#endif

