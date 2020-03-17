
// Ex4.3View.h : CEx43View 类的接口
//

#pragma once


class CEx43View : public CView
{
protected: // 仅从序列化创建
	CEx43View();
	DECLARE_DYNCREATE(CEx43View)

// 特性
public:
	CEx43Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx43View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex4.3View.cpp 中的调试版本
inline CEx43Doc* CEx43View::GetDocument() const
   { return reinterpret_cast<CEx43Doc*>(m_pDocument); }
#endif

