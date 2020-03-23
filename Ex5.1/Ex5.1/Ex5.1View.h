
// Ex5.1View.h : CEx51View 类的接口
//

#pragma once


class CEx51View : public CView
{
protected: // 仅从序列化创建
	CEx51View();
	DECLARE_DYNCREATE(CEx51View)

// 特性
public:
	CEx51Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx51View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCircledrawing();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // Ex5.1View.cpp 中的调试版本
inline CEx51Doc* CEx51View::GetDocument() const
   { return reinterpret_cast<CEx51Doc*>(m_pDocument); }
#endif

