
// Ex4.2View.cpp : CEx42View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex4.2.h"
#endif

#include "Ex4.2Doc.h"
#include "Ex4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int T = 0;
int x = 0;
int  one = 0;
// CEx42View
void CEx42View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nFlags)
		T++;
	CView::OnMouseMove(nFlags, point);
}


void CEx42View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	x = point.x;
	CView::OnLButtonDown(nFlags, point);
}

void CEx42View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	x = point.x - x;
	one = x / T;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
IMPLEMENT_DYNCREATE(CEx42View, CView)

BEGIN_MESSAGE_MAP(CEx42View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEx42View 构造/析构

CEx42View::CEx42View()
{
	// TODO: 在此处添加构造代码

}

CEx42View::~CEx42View()
{
}

BOOL CEx42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx42View 绘制

void CEx42View::OnDraw(CDC* pDC)
{
	CEx42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString str;
	str.Format(_T("MouseMove移动了%d次，横向移动%d个像素发生一次。"), T, one);
	pDC->TextOutA(500, 500, str);
	T = 0;
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx42View 诊断

#ifdef _DEBUG
void CEx42View::AssertValid() const
{
	CView::AssertValid();
}

void CEx42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx42Doc* CEx42View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx42Doc)));
	return (CEx42Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx42View 消息处理程序


