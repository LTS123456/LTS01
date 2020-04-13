// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex7.4.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, e1(_T(""))
	, e2(0)
	, e3(_T(""))
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, e1);
	DDX_Text(pDX, IDC_EDIT2, e2);
	DDX_Text(pDX, IDC_EDIT3, e3);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDialog 消息处理程序


void MyDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s1;
	UpdateData(TRUE);
	s1.Format(_T("%d"), e2);
	e3 = e1 + s1;
	UpdateData(FALSE);
}
