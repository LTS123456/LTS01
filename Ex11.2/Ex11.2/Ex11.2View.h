
// Ex11.2View.h : CEx112View 类的接口
//

#pragma once

class CEx112Set;

class CEx112View : public CRecordView
{
protected: // 仅从序列化创建
	CEx112View();
	DECLARE_DYNCREATE(CEx112View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX112_FORM };
#endif
	CEx112Set* m_pSet;

// 特性
public:
	CEx112Doc* GetDocument() const;

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
	virtual ~CEx112View();
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
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // Ex11.2View.cpp 中的调试版本
inline CEx112Doc* CEx112View::GetDocument() const
   { return reinterpret_cast<CEx112Doc*>(m_pDocument); }
#endif

