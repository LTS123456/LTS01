#pragma once
#include "afxwin.h"


// SDialog 对话框

class SDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SDialog)

public:
	SDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif
	CEx141Set* m_pSet;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list;
	virtual BOOL OnInitDialog();
};
