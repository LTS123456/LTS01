
// Ex8.4View.h : CEx84View 类的接口
//

#pragma once


class CEx84View : public CView
{
protected: // 仅从序列化创建
	CEx84View();
	DECLARE_DYNCREATE(CEx84View)

// 特性
public:
	CEx84Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx84View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawellipse();
};

#ifndef _DEBUG  // Ex8.4View.cpp 中的调试版本
inline CEx84Doc* CEx84View::GetDocument() const
   { return reinterpret_cast<CEx84Doc*>(m_pDocument); }
#endif

