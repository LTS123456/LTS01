
// Ex8.1View.h : CEx81View ��Ľӿ�
//

#pragma once


class CEx81View : public CView
{
protected: // �������л�����
	CEx81View();
	DECLARE_DYNCREATE(CEx81View)

// ����
public:
	CEx81Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx81View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString s;
	int r;
	int flag;
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnEditshow();
	afx_msg void OnListshow();
};

#ifndef _DEBUG  // Ex8.1View.cpp �еĵ��԰汾
inline CEx81Doc* CEx81View::GetDocument() const
   { return reinterpret_cast<CEx81Doc*>(m_pDocument); }
#endif
