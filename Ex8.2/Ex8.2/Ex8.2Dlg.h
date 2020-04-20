
// Ex8.2Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CEx82Dlg 对话框
class CEx82Dlg : public CDialogEx
{
// 构造
public:
	CEx82Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX82_DIALOG };
#endif
	double num1;
	double num2;
	int strle;
	int mark;
	void Save();
	void Calculator();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	CEdit m_edit;
	CString m_str;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};
