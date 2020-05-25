// SerchDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex14.1.h"
#include "SerchDialog.h"
#include "afxdialogex.h"


// SerchDialog 对话框

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


// SerchDialog 消息处理程序


void SerchDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
