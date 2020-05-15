
// Ex2.3View.h : CEx23View 类的接口
//

#pragma once


class CEx23View : public CView
{
protected: // 仅从序列化创建
	CEx23View();
	DECLARE_DYNCREATE(CEx23View)

// 特性
public:
	CEx23Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Ex2.3View.cpp 中的调试版本
inline CEx23Doc* CEx23View::GetDocument() const
   { return reinterpret_cast<CEx23Doc*>(m_pDocument); }
#endif

