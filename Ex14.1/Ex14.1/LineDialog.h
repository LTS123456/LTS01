#pragma once


// LineDialog �Ի���

class LineDialog : public CDialogEx
{
	DECLARE_DYNAMIC(LineDialog)

public:
	LineDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LineDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_Line;
};
