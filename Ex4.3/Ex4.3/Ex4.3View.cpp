
// Ex4.3View.cpp : CEx43View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex4.3.h"
#endif

#include "Ex4.3Doc.h"
#include "Ex4.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx43View

IMPLEMENT_DYNCREATE(CEx43View, CView)

BEGIN_MESSAGE_MAP(CEx43View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx43View 构造/析构

CEx43View::CEx43View()
{
	// TODO: 在此处添加构造代码

}

CEx43View::~CEx43View()
{
}

BOOL CEx43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx43View 绘制

void CEx43View::OnDraw(CDC* pDC)
{
	CEx43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx43View 诊断

#ifdef _DEBUG
void CEx43View::AssertValid() const
{
	CView::AssertValid();
}

void CEx43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx43Doc* CEx43View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx43Doc)));
	return (CEx43Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx43View 消息处理程序


void CEx43View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx43Doc* pDoc = GetDocument();
	CRect clientRect;
	GetClientRect(&clientRect);
	int x1 = clientRect.bottom - clientRect.top;
	int x2 = clientRect.right - clientRect.left;
	switch (nChar)
	{
	case VK_UP:
		if (pDoc->cr.top > 0);
		{
			pDoc->cr.top -= 50;
			pDoc->cr.bottom -= 50;
		}
		break;
	case VK_DOWN:
		if (pDoc->cr.bottom < x1);
		{
			pDoc->cr.top += 50;
			pDoc->cr.bottom += 50;
		}
		break;
	case VK_LEFT:
		if (pDoc->cr.left > 0);
		{
			pDoc->cr.left -= 50;
			pDoc->cr.right -= 50;
		}
		break;
	case VK_RIGHT:
		if (pDoc->cr.right < x2);
		{
			pDoc->cr.left += 50;
			pDoc->cr.right += 50;
		}
		break;
	case 'A':/*笔记本键盘没有home键*/
		if (pDoc->cr.left > 0&&pDoc->cr.top>0);
		{
			pDoc->cr.left -= 50;
			pDoc->cr.top -= 50;
		}
		break;
	case 'D':/*笔记本键盘没有END键*/
		if (pDoc->cr.left < pDoc->cr.right && pDoc->cr.top<pDoc->cr.bottom);
		{
			pDoc->cr.left += 50;
			pDoc->cr.top += 50;
		}
		break;
	}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CEx43View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx43Doc* pDoc = GetDocument();
	pDoc->cr.left = 30;
	pDoc->cr.top = 30;
	pDoc->cr.right = 130;
	pDoc->cr.bottom = 130;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
