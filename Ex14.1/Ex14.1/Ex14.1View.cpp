
// Ex14.1View.cpp : CEx141View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex14.1.h"
#endif

#include "Ex14.1Set.h"
#include "Ex14.1Doc.h"
#include "Ex14.1View.h"
#include "ShowDialog.h"
#include "SerchDialog.h"
#include "LineDialog.h"
#include "SDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int flag = 1;
int flag1 = 0;

// CEx141View

IMPLEMENT_DYNCREATE(CEx141View, CRecordView)

BEGIN_MESSAGE_MAP(CEx141View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CEx141View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &CEx141View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CEx141View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CEx141View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CEx141View::OnRecordLast)
	ON_WM_PAINT()
	ON_COMMAND(ID_Serch, &CEx141View::OnSerch)
	ON_BN_CLICKED(IDC_BUTTON2, &CEx141View::OnBnClickedButton2)
	ON_COMMAND(ID_Line, &CEx141View::OnLine)
	ON_COMMAND(ID_Show, &CEx141View::OnShow)
END_MESSAGE_MAP()

// CEx141View 构造/析构

CEx141View::CEx141View()
	: CRecordView(IDD_EX141_FORM)
	, ID(0)
	, m_num(_T(""))
	, m_name(_T(""))
	, m_age(0)
	, m_tele(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CEx141View::~CEx141View()
{
}

void CEx141View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
}

BOOL CEx141View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CEx141View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex141Set;
	CRecordView::OnInitialUpdate();

}


// CEx141View 诊断

#ifdef _DEBUG
void CEx141View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx141View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx141Doc* CEx141View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx141Doc)));
	return (CEx141Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx141View 数据库支持
CRecordset* CEx141View::OnGetRecordset()
{
	return m_pSet;
}



// CEx141View 消息处理程序

void CEx141View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect);
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

void CEx141View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	path = m_pSet->column5;
	ShowDialog *dia = new ShowDialog;
	dia->Create(IDD_DIALOG1);
	dia->ShowWindow(1);
}


void CEx141View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx141View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx141View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx141View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx141View::OnPaint()
{
	CPaintDC dc(this); 
	if (flag)
	{
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
		flag = 0;
	}
}


void CEx141View::OnSerch()
{
	// TODO: 在此添加命令处理程序代码
	SerchDialog dia;
	int r = dia.DoModal();
	CString s;
	if (r == IDOK)
		s = dia.m_Search;
	m_pSet->m_strFilter = s;
	m_pSet->Requery();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
	flag1 = 1;
}


void CEx141View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag1 == 1)
	{
		m_pSet->m_strFilter = _T("");
		m_pSet->Requery();
		UpdateData(false);
		GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
		flag1 = 0;
	}
	if (flag1 == 2)
	{
		m_pSet->m_strSort = _T("");
		m_pSet->Requery();
		UpdateData(false);
		GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
		flag1 = 0;
	}
}


void CEx141View::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	LineDialog dia;
	int r = dia.DoModal();
	CString s;
	if (r == IDOK)
		s = dia.m_Line;
	m_pSet->m_strSort = s;
	m_pSet->Requery();
	UpdateData(false);
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
	flag1 = 2;
}


void CEx141View::OnShow()
{
	// TODO: 在此添加命令处理程序代码
	SDialog *dia = new SDialog;
	dia->m_pSet = m_pSet;
	dia->Create(IDD_DIALOG4);
	dia->ShowWindow(1);
}
