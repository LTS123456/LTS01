
// Ex11.1View.h : CEx111View 类的接口
//

#pragma once

class CEx111Set;

class CEx111View : public CRecordView
{
protected: // 仅从序列化创建
	CEx111View();
	DECLARE_DYNCREATE(CEx111View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX111_FORM };
#endif
	CEx111Set* m_pSet;

// 特性
public:
	CEx111Doc* GetDocument() const;

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
	virtual ~CEx111View();
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
	double ID;
	CString m_num;
	CString m_name;
	double m_age;
	double m_tele;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // Ex11.1View.cpp 中的调试版本
inline CEx111Doc* CEx111View::GetDocument() const
   { return reinterpret_cast<CEx111Doc*>(m_pDocument); }
#endif

