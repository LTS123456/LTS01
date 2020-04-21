// Dialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex8.6.h"
#include "Dialog.h"
#include "afxdialogex.h"


// Dialog 对话框

IMPLEMENT_DYNAMIC(Dialog, CDialogEx)

Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_s1(0)
	, m_s2(0)
	, m_s3(0)
{

}

Dialog::~Dialog()
{
}

void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_s1);
	DDV_MinMaxInt(pDX, m_s1, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_s2);
	DDV_MinMaxInt(pDX, m_s2, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, m_s3);
	DDV_MinMaxInt(pDX, m_s3, 0, 255);
}


BEGIN_MESSAGE_MAP(Dialog, CDialogEx)
END_MESSAGE_MAP()


// Dialog 消息处理程序
