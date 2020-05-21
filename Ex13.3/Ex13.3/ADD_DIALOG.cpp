// ADD_DIALOG.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex13.3.h"
#include "ADD_DIALOG.h"
#include "afxdialogex.h"


// ADD_DIALOG 对话框

IMPLEMENT_DYNAMIC(ADD_DIALOG, CDialogEx)

ADD_DIALOG::ADD_DIALOG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIA, pParent)
	, m_add(0)
{

}

ADD_DIALOG::~ADD_DIALOG()
{
}

void ADD_DIALOG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_add);
}


BEGIN_MESSAGE_MAP(ADD_DIALOG, CDialogEx)
END_MESSAGE_MAP()


// ADD_DIALOG 消息处理程序
