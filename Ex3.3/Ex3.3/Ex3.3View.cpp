
// Ex3.3View.cpp : CEx33View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex3.3.h"
#endif

#include "Ex3.3Doc.h"
#include "Ex3.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx33View

IMPLEMENT_DYNCREATE(CEx33View, CView)

BEGIN_MESSAGE_MAP(CEx33View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEx33View 构造/析构

CEx33View::CEx33View()
{
	// TODO: 在此处添加构造代码

}

CEx33View::~CEx33View()
{
}

BOOL CEx33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx33View 绘制

void CEx33View::OnDraw(CDC* /*pDC*/)
{
	CEx33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEx33View 诊断

#ifdef _DEBUG
void CEx33View::AssertValid() const
{
	CView::AssertValid();
}

void CEx33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx33Doc* CEx33View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx33Doc)));
	return (CEx33Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx33View 消息处理程序


void CEx33View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s = _T("左键正被按下");
	CClientDC dc(this);
	dc.TextOutW(600, 300, s);
	CView::OnLButtonDown(nFlags, point);
}


void CEx33View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s = _T("左键正在抬起");
	CClientDC dc(this);
	dc.TextOutW(600, 300, s);
	CView::OnLButtonUp(nFlags, point);
}
