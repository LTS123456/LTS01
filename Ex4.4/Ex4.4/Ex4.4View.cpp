
// Ex4.4View.cpp : CEx44View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex4.4.h"
#endif

#include "Ex4.4Doc.h"
#include "Ex4.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx44View

IMPLEMENT_DYNCREATE(CEx44View, CView)

BEGIN_MESSAGE_MAP(CEx44View, CView)
END_MESSAGE_MAP()

// CEx44View 构造/析构

CEx44View::CEx44View()
{
	// TODO: 在此处添加构造代码

}

CEx44View::~CEx44View()
{
}

BOOL CEx44View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx44View 绘制

void CEx44View::OnDraw(CDC* /*pDC*/)
{
	CEx44Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEx44View 诊断

#ifdef _DEBUG
void CEx44View::AssertValid() const
{
	CView::AssertValid();
}

void CEx44View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx44Doc* CEx44View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx44Doc)));
	return (CEx44Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx44View 消息处理程序
