
// UsedllView.h : CUsedllView ��Ľӿ�
//

#pragma once


class CUsedllView : public CView
{
protected: // �������л�����
	CUsedllView();
	DECLARE_DYNCREATE(CUsedllView)

// ����
public:
	CUsedllDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CUsedllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UsedllView.cpp �еĵ��԰汾
inline CUsedllDoc* CUsedllView::GetDocument() const
   { return reinterpret_cast<CUsedllDoc*>(m_pDocument); }
#endif

