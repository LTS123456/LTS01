// DEL_DIALOG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ex13.3.h"
#include "DEL_DIALOG.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Ex13.3Doc.h"
#include "Ex13.3View.h"


// DEL_DIALOG �Ի���

IMPLEMENT_DYNAMIC(DEL_DIALOG, CDialogEx)

DEL_DIALOG::DEL_DIALOG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_del(0)
{

}

DEL_DIALOG::~DEL_DIALOG()
{
}

void DEL_DIALOG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_del);
}


BEGIN_MESSAGE_MAP(DEL_DIALOG, CDialogEx)
END_MESSAGE_MAP()


// DEL_DIALOG ��Ϣ�������


BOOL DEL_DIALOG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	CEx133View* pView = (CEx133View*)pFrame->GetActiveView();
	m_del = pView->change;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
