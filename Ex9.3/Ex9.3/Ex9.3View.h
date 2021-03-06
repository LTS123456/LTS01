
// Ex9.3View.h : CEx93View 类的接口
//

#pragma once


class CEx93View : public CView
{
protected: // 仅从序列化创建
	CEx93View();
	DECLARE_DYNCREATE(CEx93View)

// 特性
public:
	CEx93Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	CArray<CRect, CRect> a;
	int count=0;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx93View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnFileOpen();
//	afx_msg void OnClose();
};

#ifndef _DEBUG  // Ex9.3View.cpp 中的调试版本
inline CEx93Doc* CEx93View::GetDocument() const
   { return reinterpret_cast<CEx93Doc*>(m_pDocument); }
#endif

