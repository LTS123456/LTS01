// ShowDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex14.1.h"
#include "ShowDialog.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Ex14.1Doc.h"
#include "Ex14.1View.h"


// ShowDialog 对话框

IMPLEMENT_DYNAMIC(ShowDialog, CDialogEx)

ShowDialog::ShowDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

ShowDialog::~ShowDialog()
{
}

void ShowDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ShowDialog, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// ShowDialog 消息处理程序
void ShowDialog::foo(CImage& img, int& sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;

	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;

	}
}

void ShowDialog::OnPaint()
{
	CPaintDC dc(this); 
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	CEx141View* pView = (CEx141View*)pFrame->GetActiveView();
	CImage img;
	img.Load(pView->path);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
