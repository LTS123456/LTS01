#pragma once


// ShowDialog 对话框

class ShowDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ShowDialog)

public:
	ShowDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void foo(CImage& img, int& sx, int& sy, int& w, int& h);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
