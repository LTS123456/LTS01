#pragma once


// Dialog 对话框

class Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(Dialog)

public:
	Dialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_s1;
	int m_s2;
	int m_s3;
};
