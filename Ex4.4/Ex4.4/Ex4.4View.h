
// Ex4.4View.h : CEx44View ��Ľӿ�
//

#pragma once


class CEx44View : public CView
{
protected: // �������л�����
	CEx44View();
	DECLARE_DYNCREATE(CEx44View)

// ����
public:
	CEx44Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx44View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Ex4.4View.cpp �еĵ��԰汾
inline CEx44Doc* CEx44View::GetDocument() const
   { return reinterpret_cast<CEx44Doc*>(m_pDocument); }
#endif

