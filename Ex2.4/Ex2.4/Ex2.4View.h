
// Ex2.4View.h : CEx24View ��Ľӿ�
//

#pragma once


class CEx24View : public CView
{
protected: // �������л�����
	CEx24View();
	DECLARE_DYNCREATE(CEx24View)

// ����
public:
	CEx24Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx24View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Ex2.4View.cpp �еĵ��԰汾
inline CEx24Doc* CEx24View::GetDocument() const
   { return reinterpret_cast<CEx24Doc*>(m_pDocument); }
#endif

