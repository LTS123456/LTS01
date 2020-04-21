
// Ex8.5View.h : CEx85View 类的接口
//

#pragma once


class CEx85View : public CView
{
protected: // 仅从序列化创建
	CEx85View();
	DECLARE_DYNCREATE(CEx85View)

// 特性
public:
	CEx85Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx85View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex8.5View.cpp 中的调试版本
inline CEx85Doc* CEx85View::GetDocument() const
   { return reinterpret_cast<CEx85Doc*>(m_pDocument); }
#endif

