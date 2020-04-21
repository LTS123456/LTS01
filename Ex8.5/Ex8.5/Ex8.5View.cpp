
// Ex8.5View.cpp : CEx85View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex8.5.h"
#endif

#include "Ex8.5Doc.h"
#include "Ex8.5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int flag1 = 0;
int flag2 = 0;
CRect cr;
// CEx85View

IMPLEMENT_DYNCREATE(CEx85View, CView)

BEGIN_MESSAGE_MAP(CEx85View, CView)
//	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEx85View 构造/析构

CEx85View::CEx85View()
{
	// TODO: 在此处添加构造代码

}

CEx85View::~CEx85View()
{
}

BOOL CEx85View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx85View 绘制

void CEx85View::OnDraw(CDC* pDC)
{
	CEx85Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	if (flag2)
	{
		CPen pen;
		pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
		pDC->SelectObject(&pen);
		pDC->MoveTo(cr.left, cr.top);
		pDC->LineTo(cr.right, cr.top);
		pDC->MoveTo(cr.right, cr.top);
		pDC->LineTo(cr.right, cr.bottom);
		pDC->MoveTo(cr.right, cr.bottom);
		pDC->LineTo(cr.left, cr.bottom);
		pDC->MoveTo(cr.left, cr.bottom);
		pDC->LineTo(cr.left, cr.top);
		flag2 = 0;
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx85View 诊断

#ifdef _DEBUG
void CEx85View::AssertValid() const
{
	CView::AssertValid();
}

void CEx85View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx85Doc* CEx85View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx85Doc)));
	return (CEx85Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx85View 消息处理程序


void CEx85View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x > cr.left &&point.x < cr.right &&point.y > cr.top &&point.y < cr.bottom)
		flag2 = 1;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CEx85View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	cr.left = point.x - 100;
	cr.top = point.y - 70;
	cr.right = point.x + 100;
	cr.bottom = point.y + 70;
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
