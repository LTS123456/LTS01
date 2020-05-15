
// Ex11.2View.cpp : CEx112View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex11.2.h"
#endif

#include "Ex11.2Set.h"
#include "Ex11.2Doc.h"
#include "Ex11.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx112View

IMPLEMENT_DYNCREATE(CEx112View, CRecordView)

BEGIN_MESSAGE_MAP(CEx112View, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CEx112View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CEx112View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CEx112View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CEx112View::OnRecordLast)
END_MESSAGE_MAP()

// CEx112View 构造/析构

CEx112View::CEx112View()
	: CRecordView(IDD_EX112_FORM)
	, ID(0)
	, m_num(_T(""))
	, m_name(_T(""))
	, m_age(0)
	, m_tele(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CEx112View::~CEx112View()
{
}

void CEx112View::DoDataExchange(CDataExchange* pDX)
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

BOOL CEx112View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CEx112View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex112Set;
	CRecordView::OnInitialUpdate();

}


// CEx112View 诊断

#ifdef _DEBUG
void CEx112View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx112View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx112Doc* CEx112View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx112Doc)));
	return (CEx112Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx112View 数据库支持
CRecordset* CEx112View::OnGetRecordset()
{
	return m_pSet;
}

void CEx112View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
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

// CEx112View 消息处理程序


void CEx112View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();//凡是用到getdc必须释放它
	pDC->SetStretchBltMode(HALFTONE);//图像不失真
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
}



void CEx112View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	CRect cr;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx112View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CRect cr;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx112View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	UpdateData(false);
	CRect cr;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CEx112View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	CRect cr;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&cr);
	InvalidateRect(cr);
}
