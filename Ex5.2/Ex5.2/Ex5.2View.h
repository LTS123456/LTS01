
// Ex5.2View.h : CEx52View 类的接口
//

#pragma once


class CEx52View : public CView
{
protected: // 仅从序列化创建
	CEx52View();
	DECLARE_DYNCREATE(CEx52View)

// 特性
public:
	CEx52Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx52View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
	afx_msg void OnShowbmp();
	afx_msg void OnDrawline();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawrectangle();
	afx_msg void OnDrawellipse();
};

#ifndef _DEBUG  // Ex5.2View.cpp 中的调试版本
inline CEx52Doc* CEx52View::GetDocument() const
   { return reinterpret_cast<CEx52Doc*>(m_pDocument); }
#endif

