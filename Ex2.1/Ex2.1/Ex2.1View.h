
// Ex2.1View.h : CEx21View 类的接口
//

#pragma once


class CEx21View : public CView
{
protected: // 仅从序列化创建
	CEx21View();
	DECLARE_DYNCREATE(CEx21View)

// 特性
public:
	CEx21Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx21View();
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

#ifndef _DEBUG  // Ex2.1View.cpp 中的调试版本
inline CEx21Doc* CEx21View::GetDocument() const
   { return reinterpret_cast<CEx21Doc*>(m_pDocument); }
#endif

