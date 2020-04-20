
// Ex8.3View.h : CEx83View 类的接口
//

#pragma once


class CEx83View : public CView
{
protected: // 仅从序列化创建
	CEx83View();
	DECLARE_DYNCREATE(CEx83View)

// 特性
public:
	CEx83Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx83View();
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

#ifndef _DEBUG  // Ex8.3View.cpp 中的调试版本
inline CEx83Doc* CEx83View::GetDocument() const
   { return reinterpret_cast<CEx83Doc*>(m_pDocument); }
#endif

