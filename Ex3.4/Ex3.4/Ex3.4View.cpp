
// Ex3.4View.cpp : CEx34View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex3.4.h"
#endif

#include "Ex3.4Doc.h"
#include "Ex3.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx34View

IMPLEMENT_DYNCREATE(CEx34View, CView)

BEGIN_MESSAGE_MAP(CEx34View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx34View 构造/析构

CEx34View::CEx34View()
{
	// TODO: 在此处添加构造代码
}

CEx34View::~CEx34View()
{
}

BOOL CEx34View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx34View 绘制

void CEx34View::OnDraw(CDC* /*pDC*/)
{
	CEx34Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEx34View 诊断

#ifdef _DEBUG
void CEx34View::AssertValid() const
{
	CView::AssertValid();
}

void CEx34View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx34Doc* CEx34View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx34Doc)));
	return (CEx34Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx34View 消息处理程序


void CEx34View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEx34Doc* pDoc = GetDocument();
	int sum = pDoc->A + pDoc->B;
	CString s;
	s.Format(_T("A+B=%d"), sum);
	CClientDC dc(this);
	dc.TextOutW(600, 300, s);
	CView::OnLButtonDown(nFlags, point);
}
