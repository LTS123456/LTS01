
// Ex12.1View.h : CEx121View 类的接口
//

#pragma once

class CEx121Set;

class CEx121View : public CRecordView
{
protected: // 仅从序列化创建
	CEx121View();
	DECLARE_DYNCREATE(CEx121View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX121_FORM };
#endif
	CEx121Set* m_pSet;

// 特性
public:
	CEx121Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CEx121View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void foo(CImage& img, int& sx, int& sy, int& w, int& h);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
//	afx_msg void OnPaint();
};

#ifndef _DEBUG  // Ex12.1View.cpp 中的调试版本
inline CEx121Doc* CEx121View::GetDocument() const
   { return reinterpret_cast<CEx121Doc*>(m_pDocument); }
#endif

