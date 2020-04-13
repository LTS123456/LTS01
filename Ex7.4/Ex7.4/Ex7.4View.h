
// Ex7.4View.h : CEx74View 类的接口
//

#pragma once


class CEx74View : public CView
{
protected: // 仅从序列化创建
	CEx74View();
	DECLARE_DYNCREATE(CEx74View)

// 特性
public:
	CEx74Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx74View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex7.4View.cpp 中的调试版本
inline CEx74Doc* CEx74View::GetDocument() const
   { return reinterpret_cast<CEx74Doc*>(m_pDocument); }
#endif

