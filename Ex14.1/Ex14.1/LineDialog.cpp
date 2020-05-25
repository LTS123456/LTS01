// LineDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex14.1.h"
#include "LineDialog.h"
#include "afxdialogex.h"


// LineDialog 对话框

IMPLEMENT_DYNAMIC(LineDialog, CDialogEx)

LineDialog::LineDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_Line(_T(""))
{

}

LineDialog::~LineDialog()
{
}

void LineDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Line);
}


BEGIN_MESSAGE_MAP(LineDialog, CDialogEx)
END_MESSAGE_MAP()


// LineDialog 消息处理程序
