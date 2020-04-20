
// Ex8.4View.cpp : CEx84View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex8.4.h"
#endif

#include "Ex8.4Doc.h"
#include "Ex8.4View.h"
#include "Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int flag = 0;
int x = 0;
int y = 0;
int l = 0;
int s = 0;
CRect cr;
// CEx84View

IMPLEMENT_DYNCREATE(CEx84View, CView)

BEGIN_MESSAGE_MAP(CEx84View, CView)
	ON_COMMAND(ID_DRAWELLIPSE, &CEx84View::OnDrawellipse)
END_MESSAGE_MAP()

// CEx84View 构造/析构

CEx84View::CEx84View()
{
	// TODO: 在此处添加构造代码

}

CEx84View::~CEx84View()
{
}

BOOL CEx84View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx84View 绘制

void CEx84View::OnDraw(CDC* pDC)
{
	CEx84Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag)
	{
		Dialog dia;
		int r=dia.DoModal();
		if (r == IDOK)
		{
			x = dia.m_x;
			y = dia.m_y;
			l = dia.m_long;
			s = dia.m_short;
		}
		cr = CRect(x - l, y - s, x + l, y + s);
		pDC->Ellipse(cr);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx84View 诊断

#ifdef _DEBUG
void CEx84View::AssertValid() const
{
	CView::AssertValid();
}

void CEx84View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx84Doc* CEx84View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx84Doc)));
	return (CEx84Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx84View 消息处理程序


void CEx84View::OnDrawellipse()
{
	// TODO: 在此添加命令处理程序代码
	flag = 1;
	Invalidate();
}
