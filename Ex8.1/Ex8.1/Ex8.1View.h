
// Ex8.1View.h : CEx81View 类的接口
//

#pragma once


class CEx81View : public CView
{
protected: // 仅从序列化创建
	CEx81View();
	DECLARE_DYNCREATE(CEx81View)

// 特性
public:
	CEx81Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx81View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString s;
	int r;
	int flag;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnEditshow();
	afx_msg void OnListshow();
};

#ifndef _DEBUG  // Ex8.1View.cpp 中的调试版本
inline CEx81Doc* CEx81View::GetDocument() const
   { return reinterpret_cast<CEx81Doc*>(m_pDocument); }
#endif
