
// Ex3.1View.h : CEx31View ��Ľӿ�
//

#pragma once


class CEx31View : public CView
{
protected: // �������л�����
	CEx31View();
	DECLARE_DYNCREATE(CEx31View)

// ����
public:
	CEx31Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx31View();
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

#ifndef _DEBUG  // Ex3.1View.cpp �еĵ��԰汾
inline CEx31Doc* CEx31View::GetDocument() const
   { return reinterpret_cast<CEx31Doc*>(m_pDocument); }
#endif
