
// Ex4.4View.h : CEx44View 类的接口
//

#pragma once


class CEx44View : public CView
{
protected: // 仅从序列化创建
	CEx44View();
	DECLARE_DYNCREATE(CEx44View)

// 特性
public:
	CEx44Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx44View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Ex4.4View.cpp 中的调试版本
inline CEx44Doc* CEx44View::GetDocument() const
   { return reinterpret_cast<CEx44Doc*>(m_pDocument); }
#endif

