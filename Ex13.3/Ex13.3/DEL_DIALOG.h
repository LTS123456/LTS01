#pragma once


// DEL_DIALOG �Ի���

class DEL_DIALOG : public CDialogEx
{
	DECLARE_DYNAMIC(DEL_DIALOG)

public:
	DEL_DIALOG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DEL_DIALOG();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long m_del;
	virtual BOOL OnInitDialog();
};
