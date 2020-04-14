
// Ex8.1View.cpp : CEx81View 类的实现
//

#include "stdafx.h"
#include "MyDialog.h"
#include "MyDialog2.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex8.1.h"
#endif

#include "Ex8.1Doc.h"
#include "Ex8.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEx81View

IMPLEMENT_DYNCREATE(CEx81View, CView)

BEGIN_MESSAGE_MAP(CEx81View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_EDITSHOW, &CEx81View::OnEditshow)
	ON_COMMAND(ID_LISTSHOW, &CEx81View::OnListshow)
END_MESSAGE_MAP()

// CEx81View 构造/析构

CEx81View::CEx81View()
{
	// TODO: 在此处添加构造代码

}

CEx81View::~CEx81View()
{
}

BOOL CEx81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx81View 绘制

void CEx81View::OnDraw(CDC* /*pDC*/)
{
	CEx81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 1)
	{
		MyDialog *pD = new MyDialog;
		pD->d1 = s;
		pD->Create(IDD_DIALOG1);
		pD->ShowWindow(1);
		flag = 0;
	}
	if (flag == 2)
	{
		MyDialog2 *pD = new MyDialog2;
		pD->Create(IDD_DIALOG2);
		pD->ShowWindow(1);
		flag = 0;
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx81View 诊断

#ifdef _DEBUG
void CEx81View::AssertValid() const
{
	CView::AssertValid();
}

void CEx81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx81Doc* CEx81View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx81Doc)));
	return (CEx81Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx81View 消息处理程序


void CEx81View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	r = cfd.DoModal();
	if (r == IDOK)
	{
		s = cfd.GetFileName();
	}
	GetDC()->TextOutW(400, 300, s);
	CView::OnLButtonDblClk(nFlags, point);
}


void CEx81View::OnEditshow()
{
	// TODO: 在此添加命令处理程序代码
	flag = 1;
	Invalidate();
}


void CEx81View::OnListshow()
{
	// TODO: 在此添加命令处理程序代码
	flag = 2;
	Invalidate();
}
