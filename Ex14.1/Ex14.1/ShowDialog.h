#pragma once


// ShowDialog �Ի���

class ShowDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ShowDialog)

public:
	ShowDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void foo(CImage& img, int& sx, int& sy, int& w, int& h);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
