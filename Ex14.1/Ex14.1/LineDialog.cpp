// LineDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ex14.1.h"
#include "LineDialog.h"
#include "afxdialogex.h"


// LineDialog �Ի���

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


// LineDialog ��Ϣ�������
