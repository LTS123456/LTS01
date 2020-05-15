
// Ex1.2View.cpp : CEx12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex1.2.h"
#endif

#include "Ex1.2Doc.h"
#include "Ex1.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx12View

IMPLEMENT_DYNCREATE(CEx12View, CView)

BEGIN_MESSAGE_MAP(CEx12View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEx12View 构造/析构

CEx12View::CEx12View()
{
	// TODO: 在此处添加构造代码

}

CEx12View::~CEx12View()
{
}

BOOL CEx12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx12View 绘制

void CEx12View::OnDraw(CDC* /*pDC*/)
{
	CEx12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEx12View 诊断

#ifdef _DEBUG
void CEx12View::AssertValid() const
{
	CView::AssertValid();
}

void CEx12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx12Doc* CEx12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx12Doc)));
	return (CEx12Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx12View 消息处理程序


void CEx12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx12Doc* pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void CEx12View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx12Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(600, 300, s);
	CView::OnRButtonDown(nFlags, point);
}
