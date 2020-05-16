
// Ex2.5View.cpp : CEx25View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex2.5.h"
#endif

#include "Ex2.5Doc.h"
#include "Ex2.5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx25View

IMPLEMENT_DYNCREATE(CEx25View, CView)

BEGIN_MESSAGE_MAP(CEx25View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEx25View 构造/析构

CEx25View::CEx25View()
{
	// TODO: 在此处添加构造代码

}

CEx25View::~CEx25View()
{
}

BOOL CEx25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx25View 绘制

void CEx25View::OnDraw(CDC* /*pDC*/)
{
	CEx25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEx25View 诊断

#ifdef _DEBUG
void CEx25View::AssertValid() const
{
	CView::AssertValid();
}

void CEx25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx25Doc* CEx25View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx25Doc)));
	return (CEx25Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx25View 消息处理程序


void CEx25View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx25Doc* pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void CEx25View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx25Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(600, 300, s);
	CView::OnRButtonDown(nFlags, point);
}
