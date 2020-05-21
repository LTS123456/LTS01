
// Ex13.1View.h : CEx131View 类的接口
//

#pragma once

class CEx131Set;

class CEx131View : public CRecordView
{
protected: // 仅从序列化创建
	CEx131View();
	DECLARE_DYNCREATE(CEx131View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX131_FORM };
#endif
	CEx131Set* m_pSet;

// 特性
public:
	CEx131Doc* GetDocument() const;

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
	virtual ~CEx131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString path;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_edit;
	afx_msg void foo(CImage& img, int& sx, int& sy, int& w, int& h);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // Ex13.1View.cpp 中的调试版本
inline CEx131Doc* CEx131View::GetDocument() const
   { return reinterpret_cast<CEx131Doc*>(m_pDocument); }
#endif

