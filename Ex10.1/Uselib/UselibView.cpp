
// UselibView.cpp : CUselibView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Uselib.h"
#endif

#include "UselibDoc.h"
#include "UselibView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "win32.h"

// CUselibView

IMPLEMENT_DYNCREATE(CUselibView, CView)

BEGIN_MESSAGE_MAP(CUselibView, CView)
END_MESSAGE_MAP()

// CUselibView 构造/析构

CUselibView::CUselibView()
{
	// TODO: 在此处添加构造代码

}

CUselibView::~CUselibView()
{
}

BOOL CUselibView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUselibView 绘制

void CUselibView::OnDraw(CDC* pDC)
{
	CUselibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	f1 f;
	s.Format(_T("%d"), f.factorial(5));
	pDC->TextOutW(200, 300, s);
	// TODO: 在此处为本机数据添加绘制代码
}


// CUselibView 诊断

#ifdef _DEBUG
void CUselibView::AssertValid() const
{
	CView::AssertValid();
}

void CUselibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUselibDoc* CUselibView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUselibDoc)));
	return (CUselibDoc*)m_pDocument;
}
#endif //_DEBUG


// CUselibView 消息处理程序
