#pragma once


// SerchDialog �Ի���

class SerchDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SerchDialog)

public:
	SerchDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SerchDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_Search;
};
