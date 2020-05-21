#pragma once


// ADD_DIALOG 对话框

class ADD_DIALOG : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_DIALOG)

public:
	ADD_DIALOG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ADD_DIALOG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long m_add;
};
