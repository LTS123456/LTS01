
// Ex3.2View.cpp : CEx32View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex3.2.h"
#endif

#include "Ex3.2Doc.h"
#include "Ex3.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx32View

IMPLEMENT_DYNCREATE(CEx32View, CView)

BEGIN_MESSAGE_MAP(CEx32View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx32View 构造/析构

CEx32View::CEx32View()
{
	// TODO: 在此处添加构造代码

}

CEx32View::~CEx32View()
{
}

BOOL CEx32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx32View 绘制

void CEx32View::OnDraw(CDC* pDC)
{
	CEx32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int i;
	for (i = 0; i < pDoc->count; i++)
	{
		pDC->Ellipse(pDoc->cr[i]);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx32View 诊断

#ifdef _DEBUG
void CEx32View::AssertValid() const
{
	CView::AssertValid();
}

void CEx32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx32Doc* CEx32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx32Doc)));
	return (CEx32Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx32View 消息处理程序


void CEx32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx32Doc* pDoc = GetDocument();
	int a = rand() % 150+20;
	int b = rand() % 100 + 20;
	pDoc->cr.Add(CRect(point.x - a, point.y - b, point.x + a, point.y + b));
	pDoc->count++;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
