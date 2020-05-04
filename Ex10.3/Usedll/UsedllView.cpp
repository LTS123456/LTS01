
// UsedllView.cpp : CUsedllView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Usedll.h"
#endif

#include "UsedllDoc.h"
#include "UsedllView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Ex10.3.h"

// CUsedllView

IMPLEMENT_DYNCREATE(CUsedllView, CView)

BEGIN_MESSAGE_MAP(CUsedllView, CView)
END_MESSAGE_MAP()

// CUsedllView 构造/析构

CUsedllView::CUsedllView()
{
	// TODO: 在此处添加构造代码

}

CUsedllView::~CUsedllView()
{
}

BOOL CUsedllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUsedllView 绘制

void CUsedllView::OnDraw(CDC* pDC)
{
	CUsedllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s1;
	s1.Format(_T("%d"), factorial(5));
	pDC->TextOutW(200, 300, s1);
	CString s2;
	s2.Format(_T("%f"), convert(30.0));
	pDC->TextOutW(200, 350, s2);
	// TODO: 在此处为本机数据添加绘制代码
}


// CUsedllView 诊断

#ifdef _DEBUG
void CUsedllView::AssertValid() const
{
	CView::AssertValid();
}

void CUsedllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsedllDoc* CUsedllView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsedllDoc)));
	return (CUsedllDoc*)m_pDocument;
}
#endif //_DEBUG


// CUsedllView 消息处理程序
