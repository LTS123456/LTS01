
// Ex2.1View.h : CEx21View ��Ľӿ�
//

#pragma once


class CEx21View : public CView
{
protected: // �������л�����
	CEx21View();
	DECLARE_DYNCREATE(CEx21View)

// ����
public:
	CEx21Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx21View();
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

#ifndef _DEBUG  // Ex2.1View.cpp �еĵ��԰汾
inline CEx21Doc* CEx21View::GetDocument() const
   { return reinterpret_cast<CEx21Doc*>(m_pDocument); }
#endif

