
// Ex8.3View.cpp : CEx83View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex8.3.h"
#endif

#include "Ex8.3Doc.h"
#include "Ex8.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CRect cr;
int flag = 0;
// CEx83View

IMPLEMENT_DYNCREATE(CEx83View, CView)

BEGIN_MESSAGE_MAP(CEx83View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEx83View 构造/析构

CEx83View::CEx83View()
{
	// TODO: 在此处添加构造代码

}

CEx83View::~CEx83View()
{
}

BOOL CEx83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx83View 绘制

void CEx83View::OnDraw(CDC* pDC)
{
	CEx83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag)
		pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx83View 诊断

#ifdef _DEBUG
void CEx83View::AssertValid() const
{
	CView::AssertValid();
}

void CEx83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx83Doc* CEx83View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx83Doc)));
	return (CEx83Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx83View 消息处理程序


void CEx83View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	cr.right = point.x;
	cr.bottom = point.y;
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CEx83View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1;
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CEx83View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 0;
	CView::OnLButtonUp(nFlags, point);
}
