
// Ex9.2Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CEx92Dlg 对话框
class CEx92Dlg : public CDialogEx
{
// 构造
public:
	CEx92Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX92_DIALOG };
#endif

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
	int nCurSel;
	CListBox m_list;
	CEdit m_edit;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	virtual void OnOK();
};
