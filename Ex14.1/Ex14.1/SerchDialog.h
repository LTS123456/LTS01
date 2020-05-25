#pragma once


// SerchDialog 对话框

class SerchDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SerchDialog)

public:
	SerchDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SerchDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_Search;
};
