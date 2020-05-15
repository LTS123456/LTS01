
// Ex1.1View.h : CEx11View 类的接口
//

#pragma once


class CEx11View : public CView
{
protected: // 仅从序列化创建
	CEx11View();
	DECLARE_DYNCREATE(CEx11View)

// 特性
public:
	CEx11Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx11View();
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
};

#ifndef _DEBUG  // Ex1.1View.cpp 中的调试版本
inline CEx11Doc* CEx11View::GetDocument() const
   { return reinterpret_cast<CEx11Doc*>(m_pDocument); }
#endif

