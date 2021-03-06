
// Ex2.2View.cpp : CEx22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex2.2.h"
#endif

#include "Ex2.2Doc.h"
#include "Ex2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx22View

IMPLEMENT_DYNCREATE(CEx22View, CView)

BEGIN_MESSAGE_MAP(CEx22View, CView)
END_MESSAGE_MAP()

// CEx22View 构造/析构

CEx22View::CEx22View()
{
	// TODO: 在此处添加构造代码

}

CEx22View::~CEx22View()
{
}

BOOL CEx22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx22View 绘制

void CEx22View::OnDraw(CDC* pDC)
{
	CEx22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush b(RGB(150,61,0));
	pDC->SelectObject(&b);
	CRect clientRect;
	GetClientRect(&clientRect);
	pDC->Ellipse(clientRect);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx22View 诊断

#ifdef _DEBUG
void CEx22View::AssertValid() const
{
	CView::AssertValid();
}

void CEx22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx22Doc* CEx22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx22Doc)));
	return (CEx22Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx22View 消息处理程序
