
// Ex9.1View.h : CEx91View ��Ľӿ�
//

#pragma once

class CEx91View : public CView
{
protected: // �������л�����
	CEx91View();
	DECLARE_DYNCREATE(CEx91View)

// ����
public:
	CEx91Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEx91View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString filename;
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
};

#ifndef _DEBUG  // Ex9.1View.cpp �еĵ��԰汾
inline CEx91Doc* CEx91View::GetDocument() const
   { return reinterpret_cast<CEx91Doc*>(m_pDocument); }
#endif

