
// Ex2.4View.h : CEx24View 类的接口
//

#pragma once


class CEx24View : public CView
{
protected: // 仅从序列化创建
	CEx24View();
	DECLARE_DYNCREATE(CEx24View)

// 特性
public:
	CEx24Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx24View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Ex2.4View.cpp 中的调试版本
inline CEx24Doc* CEx24View::GetDocument() const
   { return reinterpret_cast<CEx24Doc*>(m_pDocument); }
#endif

