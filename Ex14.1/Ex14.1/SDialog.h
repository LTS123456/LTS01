#pragma once
#include "afxwin.h"


// SDialog �Ի���

class SDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SDialog)

public:
	SDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif
	CEx141Set* m_pSet;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list;
	virtual BOOL OnInitDialog();
};
