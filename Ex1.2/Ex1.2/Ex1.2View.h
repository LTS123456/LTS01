
// Ex1.2View.h : CEx12View ��Ľӿ�
//

#pragma once


class CEx12View : public CView
{
protected: // �������л�����
	CEx12View();
	DECLARE_DYNCREATE(CEx12View)

// ����
public:
	CEx12Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx12View();
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

#ifndef _DEBUG  // Ex1.2View.cpp �еĵ��԰汾
inline CEx12Doc* CEx12View::GetDocument() const
   { return reinterpret_cast<CEx12Doc*>(m_pDocument); }
#endif

