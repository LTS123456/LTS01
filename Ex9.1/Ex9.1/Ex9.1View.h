
// Ex9.1View.h : CEx91View 类的接口
//

#pragma once

class CEx91View : public CView
{
protected: // 仅从序列化创建
	CEx91View();
	DECLARE_DYNCREATE(CEx91View)

// 特性
public:
	CEx91Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEx91View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString filename;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
};

#ifndef _DEBUG  // Ex9.1View.cpp 中的调试版本
inline CEx91Doc* CEx91View::GetDocument() const
   { return reinterpret_cast<CEx91Doc*>(m_pDocument); }
#endif

