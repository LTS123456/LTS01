
// Ex2.3View.h : CEx23View ��Ľӿ�
//

#pragma once


class CEx23View : public CView
{
protected: // �������л�����
	CEx23View();
	DECLARE_DYNCREATE(CEx23View)

// ����
public:
	CEx23Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Ex2.3View.cpp �еĵ��԰汾
inline CEx23Doc* CEx23View::GetDocument() const
   { return reinterpret_cast<CEx23Doc*>(m_pDocument); }
#endif

