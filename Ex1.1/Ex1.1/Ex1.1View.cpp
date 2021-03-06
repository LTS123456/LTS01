
// Ex1.1View.cpp : CEx11View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex1.1.h"
#endif

#include "Ex1.1Doc.h"
#include "Ex1.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx11View

IMPLEMENT_DYNCREATE(CEx11View, CView)

BEGIN_MESSAGE_MAP(CEx11View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx11View 构造/析构

CEx11View::CEx11View()
{
	// TODO: 在此处添加构造代码

}

CEx11View::~CEx11View()
{
}

BOOL CEx11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx11View 绘制

void CEx11View::OnDraw(CDC* /*pDC*/)
{
	CEx11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEx11View 诊断

#ifdef _DEBUG
void CEx11View::AssertValid() const
{
	CView::AssertValid();
}

void CEx11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx11Doc* CEx11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx11Doc)));
	return (CEx11Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx11View 消息处理程序


void CEx11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx11Doc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.TextOutW(600, 300, pDoc->name);
	CView::OnLButtonDown(nFlags, point);
}
