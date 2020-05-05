
// Ex10.4View.h : CEx104View 类的接口
//

#pragma once

class CEx104Set;

class CEx104View : public CRecordView
{
protected: // 仅从序列化创建
	CEx104View();
	DECLARE_DYNCREATE(CEx104View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EX104_FORM };
#endif
	CEx104Set* m_pSet;

// 特性
public:
	CEx104Doc* GetDocument() const;

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
	virtual ~CEx104View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	double ID;
	CString snum;
	CString sname;
	double age;
	double telenum;
};

#ifndef _DEBUG  // Ex10.4View.cpp 中的调试版本
inline CEx104Doc* CEx104View::GetDocument() const
   { return reinterpret_cast<CEx104Doc*>(m_pDocument); }
#endif

