
// Ex7.2View.h : CEx72View 类的接口
//

#pragma once


class CEx72View : public CView
{
protected: // 仅从序列化创建
	CEx72View();
	DECLARE_DYNCREATE(CEx72View)

// 特性
public:
	CEx72Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx72View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCount();
};

#ifndef _DEBUG  // Ex7.2View.cpp 中的调试版本
inline CEx72Doc* CEx72View::GetDocument() const
   { return reinterpret_cast<CEx72Doc*>(m_pDocument); }
#endif

