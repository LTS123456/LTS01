
// Ex6.1View.h : CEx61View ��Ľӿ�
//

#pragma once


class CEx61View : public CView
{
protected: // �������л�����
	CEx61View();
	DECLARE_DYNCREATE(CEx61View)

// ����
public:
	CEx61Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx61View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // Ex6.1View.cpp �еĵ��԰汾
inline CEx61Doc* CEx61View::GetDocument() const
   { return reinterpret_cast<CEx61Doc*>(m_pDocument); }
#endif

