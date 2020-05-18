
// Ex12.2View.h : CEx122View 类的接口
//

#pragma once

class CEx122Set;

class CEx122View : public CRecordView
{
protected: // 仅从序列化创建
	CEx122View();
	DECLARE_DYNCREATE(CEx122View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX122_FORM };
#endif
	CEx122Set* m_pSet;

// 特性
public:
	CEx122Doc* GetDocument() const;

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
	virtual ~CEx122View();
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
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // Ex12.2View.cpp 中的调试版本
inline CEx122Doc* CEx122View::GetDocument() const
   { return reinterpret_cast<CEx122Doc*>(m_pDocument); }
#endif

