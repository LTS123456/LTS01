
// Ex2.4View.cpp : CEx24View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex2.4.h"
#endif

#include "Ex2.4Doc.h"
#include "Ex2.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx24View

IMPLEMENT_DYNCREATE(CEx24View, CView)

BEGIN_MESSAGE_MAP(CEx24View, CView)
END_MESSAGE_MAP()

// CEx24View 构造/析构

CEx24View::CEx24View()
{
	// TODO: 在此处添加构造代码

}

CEx24View::~CEx24View()
{
}

BOOL CEx24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx24View 绘制

void CEx24View::OnDraw(CDC* pDC)
{
	CEx24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString a;
	a.Format(_T("%d"), pDoc->A);
	pDC->TextOutW(600, 300, pDoc->s + a);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx24View 诊断

#ifdef _DEBUG
void CEx24View::AssertValid() const
{
	CView::AssertValid();
}

void CEx24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx24Doc* CEx24View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx24Doc)));
	return (CEx24Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx24View 消息处理程序
