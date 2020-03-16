
// Ex4.1View.h : CEx41View 类的接口
//

#pragma once


class CEx41View : public CView
{
protected: // 仅从序列化创建
	CEx41View();
	DECLARE_DYNCREATE(CEx41View)

// 特性
public:
	CEx41Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex4.1View.cpp 中的调试版本
inline CEx41Doc* CEx41View::GetDocument() const
   { return reinterpret_cast<CEx41Doc*>(m_pDocument); }
#endif

