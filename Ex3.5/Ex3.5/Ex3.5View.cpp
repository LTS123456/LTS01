
// Ex3.5View.cpp : CEx35View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex3.5.h"
#endif

#include "Ex3.5Doc.h"
#include "Ex3.5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEx35View

IMPLEMENT_DYNCREATE(CEx35View, CView)

BEGIN_MESSAGE_MAP(CEx35View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEx35View 构造/析构

CEx35View::CEx35View()
{
	// TODO: 在此处添加构造代码

}

CEx35View::~CEx35View()
{
}

BOOL CEx35View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx35View 绘制

void CEx35View::OnDraw(CDC* pDC)
{
	CEx35Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->cr1);
	pDC->Rectangle(pDoc->cr2);
	pDC->Rectangle(pDoc->cr3);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx35View 诊断

#ifdef _DEBUG
void CEx35View::AssertValid() const
{
	CView::AssertValid();
}

void CEx35View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx35Doc* CEx35View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx35Doc)));
	return (CEx35Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx35View 消息处理程序


void CEx35View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx35Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if (point.x<300||point.x>900 || point.y<250 || point.y>350)
	{
		CString s = _T("点击无效");
		dc.TextOutW(point.x, point.y, s);
	}
	if (300 < point.x && point.x < 500 && 250 < point.y && point.y < 350)
	{
		pDoc->a = rand() % 100;
		CString s;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (500 < point.x && point.x < 700 && 250 < point.y && point.y < 350)
	{
		pDoc->b = rand() % 100;
		CString s;
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CEx35View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx35Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if (point.x > 700 && point.x < 900 && point.y > 250 && point.y < 350)
	{
		CString s;
		s.Format(_T("%d"), pDoc->a + pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnRButtonDown(nFlags, point);
}
