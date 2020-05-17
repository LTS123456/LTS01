
// Ex3.2View.h : CEx32View 类的接口
//

#pragma once


class CEx32View : public CView
{
protected: // 仅从序列化创建
	CEx32View();
	DECLARE_DYNCREATE(CEx32View)

// 特性
public:
	CEx32Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx32View();
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

#ifndef _DEBUG  // Ex3.2View.cpp 中的调试版本
inline CEx32Doc* CEx32View::GetDocument() const
   { return reinterpret_cast<CEx32Doc*>(m_pDocument); }
#endif

