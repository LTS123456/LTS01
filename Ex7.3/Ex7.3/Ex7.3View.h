
// Ex7.3View.h : CEx73View 类的接口
//

#pragma once


class CEx73View : public CView
{
protected: // 仅从序列化创建
	CEx73View();
	DECLARE_DYNCREATE(CEx73View)

// 特性
public:
	CEx73Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx73View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex7.3View.cpp 中的调试版本
inline CEx73Doc* CEx73View::GetDocument() const
   { return reinterpret_cast<CEx73Doc*>(m_pDocument); }
#endif

