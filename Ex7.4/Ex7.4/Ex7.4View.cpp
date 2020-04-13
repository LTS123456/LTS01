
// Ex7.4View.cpp : CEx74View 类的实现
//

#include "stdafx.h"
#include "MyDialog.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex7.4.h"
#endif

#include "Ex7.4Doc.h"
#include "Ex7.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx74View

IMPLEMENT_DYNCREATE(CEx74View, CView)

BEGIN_MESSAGE_MAP(CEx74View, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CEx74View 构造/析构

CEx74View::CEx74View()
{
	// TODO: 在此处添加构造代码

}

CEx74View::~CEx74View()
{
}

BOOL CEx74View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx74View 绘制

void CEx74View::OnDraw(CDC* /*pDC*/)
{
	CEx74Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx74View 诊断

#ifdef _DEBUG
void CEx74View::AssertValid() const
{
	CView::AssertValid();
}

void CEx74View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx74Doc* CEx74View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx74Doc)));
	return (CEx74Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx74View 消息处理程序


void CEx74View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MyDialog *pD = new MyDialog;
	pD->Create(IDD_DIALOG1);
	pD->ShowWindow(1);
	CView::OnLButtonDblClk(nFlags, point);
}
