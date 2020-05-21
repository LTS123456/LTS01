
// Ex13.1View.cpp : CEx131View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex13.1.h"
#endif

#include "Ex13.1Set.h"
#include "Ex13.1Doc.h"
#include "Ex13.1View.h"
#include "Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx131View

IMPLEMENT_DYNCREATE(CEx131View, CRecordView)

BEGIN_MESSAGE_MAP(CEx131View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON2, &CEx131View::OnBnClickedButton2)
	ON_COMMAND(ID_RECORD_FIRST, &CEx131View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CEx131View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CEx131View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CEx131View::OnRecordLast)
END_MESSAGE_MAP()

// CEx131View 构造/析构

CEx131View::CEx131View()
	: CRecordView(IDD_EX131_FORM)
	, m_edit(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CEx131View::~CEx131View()
{
}

void CEx131View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_0jpg);
}

BOOL CEx131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CEx131View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex131Set;
	CRecordView::OnInitialUpdate();

}


// CEx131View 诊断

#ifdef _DEBUG
void CEx131View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx131View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx131Doc* CEx131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx131Doc)));
	return (CEx131Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx131View 数据库支持
CRecordset* CEx131View::OnGetRecordset()
{
	return m_pSet;
}

// CEx131View 消息处理程序
void CEx131View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
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

void CEx131View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s = _T("C:\\Users\\ling\\Desktop\\学生照片\\");
	path = s + m_pSet->m_0jpg;
	Dialog *dia = new Dialog;
	dia->Create(IDD_DIALOG1);
	dia->ShowWindow(1);
}


void CEx131View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	UpdateData(FALSE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\学生照片\\");
	img.Load(s + m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx131View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	UpdateData(FALSE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\学生照片\\");
	img.Load(s + m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx131View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	UpdateData(FALSE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\学生照片\\");
	img.Load(s + m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CEx131View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	UpdateData(FALSE);
	CImage img;
	CString s = _T("C:\\Users\\ling\\Desktop\\学生照片\\");
	img.Load(s + m_pSet->m_0jpg);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
