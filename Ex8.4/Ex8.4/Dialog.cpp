// Dialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex8.4.h"
#include "Dialog.h"
#include "afxdialogex.h"


// Dialog 对话框

IMPLEMENT_DYNAMIC(Dialog, CDialogEx)

Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_x(0)
	, m_y(0)
	, m_long(0)
	, m_short(0)
{

}

Dialog::~Dialog()
{
}

void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDV_MinMaxInt(pDX, m_x, 0, 1000);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	DDV_MinMaxInt(pDX, m_y, 0, 1000);
	DDX_Text(pDX, IDC_EDIT3, m_long);
	DDV_MinMaxInt(pDX, m_long, 0, 500);
	DDX_Text(pDX, IDC_EDIT4, m_short);
	DDV_MinMaxInt(pDX, m_short, 0, 500);
}


BEGIN_MESSAGE_MAP(Dialog, CDialogEx)
END_MESSAGE_MAP()


// Dialog 消息处理程序
