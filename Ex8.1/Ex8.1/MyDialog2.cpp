// MyDialog2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ex8.1.h"
#include "MyDialog2.h"
#include "afxdialogex.h"
#include "Ex8.1Doc.h"
#include "MainFrm.h"
#include "Ex8.1View.h"

// MyDialog2 �Ի���

IMPLEMENT_DYNAMIC(MyDialog2, CDialogEx)

MyDialog2::MyDialog2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

MyDialog2::~MyDialog2()
{
}

void MyDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, d2);
}


BEGIN_MESSAGE_MAP(MyDialog2, CDialogEx)
END_MESSAGE_MAP()


// MyDialog2 ��Ϣ�������




BOOL MyDialog2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	CEx81View* pView = (CEx81View*)pFrame->GetActiveView();
	d2.AddString(pView->s);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
