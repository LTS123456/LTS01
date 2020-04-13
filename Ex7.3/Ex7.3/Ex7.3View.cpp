
// Ex7.3View.cpp : CEx73View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex7.3.h"
#endif

#include "Ex7.3Doc.h"
#include "Ex7.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx73View
CRect cr;
int flag1,flag2,flag3;
IMPLEMENT_DYNCREATE(CEx73View, CView)

BEGIN_MESSAGE_MAP(CEx73View, CView)
	ON_WM_TIMER()
//	ON_WM_MBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CEx73View 构造/析构

CEx73View::CEx73View()
{
	// TODO: 在此处添加构造代码
	flag1 = 0;
	flag2 = 0;
	flag3 = 1;
}

CEx73View::~CEx73View()
{
}

BOOL CEx73View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx73View 绘制

void CEx73View::OnDraw(CDC* pDC)
{
	CEx73Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect clientRect;
	GetClientRect(&clientRect);
	if (cr.top != clientRect.Height() / 2 - 20)
	{
		cr.top = clientRect.Height() / 2 - 20;
		cr.bottom = clientRect.Height() / 2 + 20;
	}
	if (flag3)
	{
		cr.left = 0;
		cr.top = clientRect.Height()/2-20;
		cr.right = 40;
		cr.bottom = clientRect.Height() / 2+20;
		flag3 = 0;
	}
	SetTimer(0, 100, NULL);
	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx73View 诊断

#ifdef _DEBUG
void CEx73View::AssertValid() const
{
	CView::AssertValid();
}

void CEx73View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx73Doc* CEx73View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx73Doc)));
	return (CEx73Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx73View 消息处理程序


void CEx73View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect clientRect;
	GetClientRect(&clientRect);
	if (flag2)
	{
		if (flag1 == 0)
		{
			cr.left += 30;
			cr.right += 30;
			Invalidate();
			if (cr.right >= clientRect.right)
				flag1 = 1;
		}
		if (flag1 == 1)
		{
			cr.left -= 30;
			cr.right -= 30;
			Invalidate();
			if (cr.left <= clientRect.left)
				flag1 = 0;
		}
	}
	CView::OnTimer(nIDEvent);
}


void CEx73View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag2 = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CEx73View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag2 = 0;
	CView::OnLButtonDblClk(nFlags, point);
}
