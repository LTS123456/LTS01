// SerchDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ex14.1.h"
#include "SerchDialog.h"
#include "afxdialogex.h"


// SerchDialog �Ի���

IMPLEMENT_DYNAMIC(SerchDialog, CDialogEx)

SerchDialog::SerchDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_Search(_T(""))
{

}

SerchDialog::~SerchDialog()
{
}

void SerchDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Search);
}


BEGIN_MESSAGE_MAP(SerchDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &SerchDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// SerchDialog ��Ϣ�������


void SerchDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
