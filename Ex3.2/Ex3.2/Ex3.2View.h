
// Ex3.2View.h : CEx32View ��Ľӿ�
//

#pragma once


class CEx32View : public CView
{
protected: // �������л�����
	CEx32View();
	DECLARE_DYNCREATE(CEx32View)

// ����
public:
	CEx32Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx32View();
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

#ifndef _DEBUG  // Ex3.2View.cpp �еĵ��԰汾
inline CEx32Doc* CEx32View::GetDocument() const
   { return reinterpret_cast<CEx32Doc*>(m_pDocument); }
#endif

