
// Ex9.2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CEx92Dlg �Ի���
class CEx92Dlg : public CDialogEx
{
// ����
public:
	CEx92Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX92_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int nCurSel;
	CListBox m_list;
	CEdit m_edit;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	virtual void OnOK();
};
