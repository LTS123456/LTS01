
// Ex13.3View.h : CEx133View 类的接口
//

#pragma once

class CEx133Set;

class CEx133View : public CRecordView
{
protected: // 仅从序列化创建
	CEx133View();
	DECLARE_DYNCREATE(CEx133View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX133_FORM };
#endif
	CEx133Set* m_pSet;

// 特性
public:
	CEx133Doc* GetDocument() const;

// 操作
public:
	long change;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CEx133View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long m_1;
	long m_2;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // Ex13.3View.cpp 中的调试版本
inline CEx133Doc* CEx133View::GetDocument() const
   { return reinterpret_cast<CEx133Doc*>(m_pDocument); }
#endif

