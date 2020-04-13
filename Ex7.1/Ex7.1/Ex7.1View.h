
// Ex7.1View.h : CEx71View 类的接口
//

#pragma once


class CEx71View : public CView
{
protected: // 仅从序列化创建
	CEx71View();
	DECLARE_DYNCREATE(CEx71View)

// 特性
public:
	CEx71Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx71View();
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
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex7.1View.cpp 中的调试版本
inline CEx71Doc* CEx71View::GetDocument() const
   { return reinterpret_cast<CEx71Doc*>(m_pDocument); }
#endif

