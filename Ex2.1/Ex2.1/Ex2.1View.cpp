
// Ex2.1View.cpp : CEx21View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex2.1.h"
#endif

#include "Ex2.1Doc.h"
#include "Ex2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CRect cr;
// CEx21View

IMPLEMENT_DYNCREATE(CEx21View, CView)

BEGIN_MESSAGE_MAP(CEx21View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx21View 构造/析构

CEx21View::CEx21View()
{
	// TODO: 在此处添加构造代码

}

CEx21View::~CEx21View()
{
}

BOOL CEx21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx21View 绘制

void CEx21View::OnDraw(CDC* pDC)
{
	CEx21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx21View 诊断

#ifdef _DEBUG
void CEx21View::AssertValid() const
{
	CView::AssertValid();
}

void CEx21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx21Doc* CEx21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx21Doc)));
	return (CEx21Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx21View 消息处理程序


void CEx21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % 300;
	cr = CRect(point.x - r, point.y - r, point.x + r, point.y + r);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
