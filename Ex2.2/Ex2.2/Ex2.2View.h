
// Ex2.2View.h : CEx22View ��Ľӿ�
//

#pragma once


class CEx22View : public CView
{
protected: // �������л�����
	CEx22View();
	DECLARE_DYNCREATE(CEx22View)

// ����
public:
	CEx22Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Ex2.2View.cpp �еĵ��԰汾
inline CEx22Doc* CEx22View::GetDocument() const
   { return reinterpret_cast<CEx22Doc*>(m_pDocument); }
#endif

