#pragma once


// ADD_DIALOG �Ի���

class ADD_DIALOG : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_DIALOG)

public:
	ADD_DIALOG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ADD_DIALOG();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long m_add;
};
