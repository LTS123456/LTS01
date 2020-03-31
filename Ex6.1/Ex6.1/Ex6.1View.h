
// Ex6.1View.h : CEx61View 类的接口
//

#pragma once


class CEx61View : public CView
{
protected: // 仅从序列化创建
	CEx61View();
	DECLARE_DYNCREATE(CEx61View)

// 特性
public:
	CEx61Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx61View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // Ex6.1View.cpp 中的调试版本
inline CEx61Doc* CEx61View::GetDocument() const
   { return reinterpret_cast<CEx61Doc*>(m_pDocument); }
#endif

