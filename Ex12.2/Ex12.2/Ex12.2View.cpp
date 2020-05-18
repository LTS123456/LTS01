
// Ex12.1View.cpp : CEx121View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex12.2.h"
#endif

#include "Ex12.2Set.h"
#include "Ex12.2Doc.h"
#include "Ex12.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString filename=_T("C:\\Users\\ling\\Desktop\\学生照片\\0.jpg");
// CEx121View

IMPLEMENT_DYNCREATE(CEx122View, CRecordView)

BEGIN_MESSAGE_MAP(CEx122View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CEx122View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CEx122View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CEx122View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CEx122View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CEx121View 构造/析构

CEx122View::CEx122View()
	: CRecordView(IDD_EX122_FORM)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CEx122View::~CEx122View()
{
}

void CEx122View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
}

BOOL CEx122View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CEx122View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex122Set;
	CRecordView::OnInitialUpdate();

}


// CEx121View 诊断

#ifdef _DEBUG
void CEx122View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx122View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx122Doc* CEx122View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx122Doc)));
	return (CEx122Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx121View 数据库支持
CRecordset* CEx122View::OnGetRecordset()
{
	return m_pSet;
}

void CEx122View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
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

// CEx121View 消息处理程序


void CEx122View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CString s = _T("C:\\Users\\ling\\Desktop\\学生照片\\");
	filename = s + m_pSet->m_0jpg;
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx122View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CString s = _T("C:\\Users\\ling\\Desktop\\学生照片\\");
	filename = s + m_pSet->m_0jpg;
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx122View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CString s = _T("C:\\Users\\ling\\Desktop\\学生照片\\");
	filename = s + m_pSet->m_0jpg;
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx122View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CString s = _T("C:\\Users\\ling\\Desktop\\学生照片\\");
	filename= s + m_pSet->m_0jpg;
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}




void CEx122View::OnPaint()
{
	CPaintDC dc(this);   
	CImage img;
	img.Load(filename);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
