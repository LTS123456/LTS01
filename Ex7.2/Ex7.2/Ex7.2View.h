
// Ex7.2View.h : CEx72View ��Ľӿ�
//

#pragma once


class CEx72View : public CView
{
protected: // �������л�����
	CEx72View();
	DECLARE_DYNCREATE(CEx72View)

// ����
public:
	CEx72Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx72View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCount();
};

#ifndef _DEBUG  // Ex7.2View.cpp �еĵ��԰汾
inline CEx72Doc* CEx72View::GetDocument() const
   { return reinterpret_cast<CEx72Doc*>(m_pDocument); }
#endif

