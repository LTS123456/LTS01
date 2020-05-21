#pragma once


// DEL_DIALOG 对话框

class DEL_DIALOG : public CDialogEx
{
	DECLARE_DYNAMIC(DEL_DIALOG)

public:
	DEL_DIALOG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DEL_DIALOG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long m_del;
	virtual BOOL OnInitDialog();
};
