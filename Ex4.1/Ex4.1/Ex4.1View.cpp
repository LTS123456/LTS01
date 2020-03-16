
// Ex4.1View.cpp : CEx41View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex4.1.h"
#endif

#include "Ex4.1Doc.h"
#include "Ex4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx41View

IMPLEMENT_DYNCREATE(CEx41View, CView)

BEGIN_MESSAGE_MAP(CEx41View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEx41View 构造/析构

CEx41View::CEx41View()
{
	// TODO: 在此处添加构造代码

}

CEx41View::~CEx41View()
{
}

BOOL CEx41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx41View 绘制

void CEx41View::OnDraw(CDC* pDC)
{
	CEx41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->mRect);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx41View 诊断

#ifdef _DEBUG
void CEx41View::AssertValid() const
{
	CView::AssertValid();
}

void CEx41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx41Doc* CEx41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx41Doc)));
	return (CEx41Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx41View 消息处理程序


void CEx41View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s.Format(_T("鼠标的位置是：X=%d,Y=%d"), point.x, point.y);
	dc.TextOutW(500, 500, s);
	CView::OnMouseMove(nFlags, point);
}


void CEx41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx41Doc* pDoc = GetDocument();
	pDoc->mRect.left = point.x;
	pDoc->mRect.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CEx41View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx41Doc* pDoc = GetDocument();
	pDoc->mRect.right = point.x;
	pDoc->mRect.bottom = point.y;
	InvalidateRect(NULL, FALSE);
	CView::OnLButtonUp(nFlags, point);
}
