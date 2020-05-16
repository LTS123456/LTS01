
// Ex3.1View.cpp : CEx31View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex3.1.h"
#endif

#include "Ex3.1Doc.h"
#include "Ex3.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CRect cr;

// CEx31View

IMPLEMENT_DYNCREATE(CEx31View, CView)

BEGIN_MESSAGE_MAP(CEx31View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx31View 构造/析构

CEx31View::CEx31View()
{
	// TODO: 在此处添加构造代码

}

CEx31View::~CEx31View()
{
}

BOOL CEx31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx31View 绘制

void CEx31View::OnDraw(CDC* pDC)
{
	CEx31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect clientRect;
	GetClientRect(&clientRect);
	cr = CRect(clientRect.top, clientRect.top, clientRect.bottom, clientRect.bottom);
	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx31View 诊断

#ifdef _DEBUG
void CEx31View::AssertValid() const
{
	CView::AssertValid();
}

void CEx31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx31Doc* CEx31View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx31Doc)));
	return (CEx31Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx31View 消息处理程序


void CEx31View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
