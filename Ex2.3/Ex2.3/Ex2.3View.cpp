
// Ex2.3View.cpp : CEx23View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex2.3.h"
#endif

#include "Ex2.3Doc.h"
#include "Ex2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx23View

IMPLEMENT_DYNCREATE(CEx23View, CView)

BEGIN_MESSAGE_MAP(CEx23View, CView)
END_MESSAGE_MAP()

// CEx23View 构造/析构

CEx23View::CEx23View()
{
	// TODO: 在此处添加构造代码

}

CEx23View::~CEx23View()
{
}

BOOL CEx23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx23View 绘制

void CEx23View::OnDraw(CDC* pDC)
{
	CEx23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s = _T("我是凌同升");
	int A = 66;
	CString a;
	a.Format(_T("%d"), A);
	pDC->TextOutW(600, 300, s + a);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx23View 诊断

#ifdef _DEBUG
void CEx23View::AssertValid() const
{
	CView::AssertValid();
}

void CEx23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx23Doc* CEx23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx23Doc)));
	return (CEx23Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx23View 消息处理程序
