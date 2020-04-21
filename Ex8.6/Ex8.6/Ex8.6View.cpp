
// Ex8.6View.cpp : CEx86View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex8.6.h"
#include "Dialog.h"
#endif

#include "Ex8.6Doc.h"
#include "Ex8.6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int s1 = 255;
int s2 = 255;
int s3 = 255;
CRect cr;
int flag=0;
// CEx86View

IMPLEMENT_DYNCREATE(CEx86View, CView)

BEGIN_MESSAGE_MAP(CEx86View, CView)
	ON_COMMAND(ID_DRAWCOLAR, &CEx86View::OnDrawcolar)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEx86View 构造/析构

CEx86View::CEx86View()
{
	// TODO: 在此处添加构造代码

}

CEx86View::~CEx86View()
{
}

BOOL CEx86View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx86View 绘制

void CEx86View::OnDraw(CDC* pDC)
{
	CEx86Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush bru(RGB(s1, s2, s3));
	CBrush *oldbrush;
	oldbrush = pDC->SelectObject(&bru);
	pDC->Ellipse(cr);
	s1 = s2 = s3 = 255;
	if (flag)
	{
		CPen pen;
		pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
		pDC->SelectObject(&pen);
		pDC->MoveTo(cr.left, cr.top);
		pDC->LineTo(cr.right, cr.top);
		pDC->MoveTo(cr.right, cr.top);
		pDC->LineTo(cr.right, cr.bottom);
		pDC->MoveTo(cr.right, cr.bottom);
		pDC->LineTo(cr.left, cr.bottom);
		pDC->MoveTo(cr.left, cr.bottom);
		pDC->LineTo(cr.left, cr.top);
		flag = 0;
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx86View 诊断

#ifdef _DEBUG
void CEx86View::AssertValid() const
{
	CView::AssertValid();
}

void CEx86View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx86Doc* CEx86View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx86Doc)));
	return (CEx86Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx86View 消息处理程序


void CEx86View::OnDrawcolar()
{
	// TODO: 在此添加命令处理程序代码
	Dialog dia;
	int r = dia.DoModal();
	if (r == IDOK)
	{
		s1 = dia.m_s1;
		s2 = dia.m_s2;
		s3 = dia.m_s3;
	}
	Invalidate();
}


void CEx86View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x > cr.left &&point.x < cr.right &&point.y > cr.top &&point.y < cr.bottom)
		flag = 1;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CEx86View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	cr.left = point.x - 100;
	cr.top = point.y - 70;
	cr.right = point.x + 100;
	cr.bottom = point.y + 70;
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
