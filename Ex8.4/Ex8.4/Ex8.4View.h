
// Ex8.4View.h : CEx84View ��Ľӿ�
//

#pragma once


class CEx84View : public CView
{
protected: // �������л�����
	CEx84View();
	DECLARE_DYNCREATE(CEx84View)

// ����
public:
	CEx84Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx84View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawellipse();
};

#ifndef _DEBUG  // Ex8.4View.cpp �еĵ��԰汾
inline CEx84Doc* CEx84View::GetDocument() const
   { return reinterpret_cast<CEx84Doc*>(m_pDocument); }
#endif

