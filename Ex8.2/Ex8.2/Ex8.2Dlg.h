
// Ex8.2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CEx82Dlg �Ի���
class CEx82Dlg : public CDialogEx
{
// ����
public:
	CEx82Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX82_DIALOG };
#endif
	double num1;
	double num2;
	int strle;
	int mark;
	void Save();
	void Calculator();
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
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	CEdit m_edit;
	CString m_str;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};
