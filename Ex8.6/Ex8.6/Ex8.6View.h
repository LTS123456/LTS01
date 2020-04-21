
// Ex8.6View.h : CEx86View 类的接口
//

#pragma once


class CEx86View : public CView
{
protected: // 仅从序列化创建
	CEx86View();
	DECLARE_DYNCREATE(CEx86View)

// 特性
public:
	CEx86Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx86View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDraw();
	afx_msg void OnDrawcolar();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex8.6View.cpp 中的调试版本
inline CEx86Doc* CEx86View::GetDocument() const
   { return reinterpret_cast<CEx86Doc*>(m_pDocument); }
#endif

