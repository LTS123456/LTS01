
// Ex5.1View.h : CEx51View ��Ľӿ�
//

#pragma once


class CEx51View : public CView
{
protected: // �������л�����
	CEx51View();
	DECLARE_DYNCREATE(CEx51View)

// ����
public:
	CEx51Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx51View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCircledrawing();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // Ex5.1View.cpp �еĵ��԰汾
inline CEx51Doc* CEx51View::GetDocument() const
   { return reinterpret_cast<CEx51Doc*>(m_pDocument); }
#endif

