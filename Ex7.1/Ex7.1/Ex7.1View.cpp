
// Ex7.1View.cpp : CEx71View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex7.1.h"
#endif

#include "Ex7.1Doc.h"
#include "Ex7.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CRect cr(10, 10, 90, 90);
int x = 40;
int flag=2;
// CEx71View

IMPLEMENT_DYNCREATE(CEx71View, CView)

BEGIN_MESSAGE_MAP(CEx71View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
ON_WM_TIMER()
ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEx71View 构造/析构

CEx71View::CEx71View()
{
	// TODO: 在此处添加构造代码

}

CEx71View::~CEx71View()
{
}

BOOL CEx71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx71View 绘制

void CEx71View::OnDraw(CDC* pDC)
{
	CEx71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(cr);
	SetTimer(1, rand() % 250 + 300, NULL);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx71View 诊断

#ifdef _DEBUG
void CEx71View::AssertValid() const
{
	CView::AssertValid();
}

void CEx71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx71Doc* CEx71View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx71Doc)));
	return (CEx71Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx71View 消息处理程序


void CEx71View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag==1)
	{
		cr.left = point.x - x;
		cr.top = point.y - x;
		cr.right = point.x + x;
		cr.bottom = point.y + x;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CEx71View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1; 
	CView::OnLButtonDown(nFlags, point);
}



void CEx71View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect clientRect;
	GetClientRect(&clientRect);
	if (flag == 0)
	{
			cr.top += 30;
			cr.bottom += 30;
			Invalidate();
	}
	CView::OnTimer(nIDEvent);
}


void CEx71View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 0;
	CView::OnLButtonUp(nFlags, point);
}
