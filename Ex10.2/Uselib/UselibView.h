
// UselibView.h : CUselibView ��Ľӿ�
//

#pragma once


class CUselibView : public CView
{
protected: // �������л�����
	CUselibView();
	DECLARE_DYNCREATE(CUselibView)

// ����
public:
	CUselibDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CUselibView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UselibView.cpp �еĵ��԰汾
inline CUselibDoc* CUselibView::GetDocument() const
   { return reinterpret_cast<CUselibDoc*>(m_pDocument); }
#endif

