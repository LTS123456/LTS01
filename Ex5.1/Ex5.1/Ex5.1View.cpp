
// Ex5.1View.cpp : CEx51View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex5.1.h"
#endif

#include "Ex5.1Doc.h"
#include "Ex5.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx51View

IMPLEMENT_DYNCREATE(CEx51View, CView)

BEGIN_MESSAGE_MAP(CEx51View, CView)
	ON_COMMAND(ID_CIRCLEDRAWING, &CEx51View::OnCircledrawing)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CEx51View 构造/析构

CEx51View::CEx51View()
{
	// TODO: 在此处添加构造代码

}

CEx51View::~CEx51View()
{
}

BOOL CEx51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx51View 绘制

void CEx51View::OnDraw(CDC* /*pDC*/)
{
	CEx51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEx51View 诊断

#ifdef _DEBUG
void CEx51View::AssertValid() const
{
	CView::AssertValid();
}

void CEx51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx51Doc* CEx51View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx51Doc)));
	return (CEx51Doc*)m_pDocument;
}
#endif //_DEBUG
CRect CR;

// CEx51View 消息处理程序
void CEx51View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect clientRect;
	GetClientRect(&clientRect);
	int i = nIDEvent;
	if (CR.top <= clientRect.top)
	{
		CR.left = clientRect.right / 2;
		CR.top = clientRect.bottom / 2;
		CR.right = clientRect.right / 2;
		CR.bottom=clientRect.bottom / 2;
	}
	if (i == 0)
	{
		CR.left -= 10;
		CR.top -= 10;
		CR.right += 10;
		CR.bottom += 10;
		CPen pen(PS_SOLID, 5, RGB(rand() % 255, rand() % 255, rand() % 255));
		CPen *p;
		p = dc.SelectObject(&pen);
		dc.Ellipse(CR);
	}
	CView::OnTimer(nIDEvent);
}


void CEx51View::OnCircledrawing()
{
	// TODO: 在此添加命令处理程序代码
	CRect clientRect;
	GetClientRect(&clientRect);
	CRect cr(clientRect.right / 2, clientRect.bottom / 2, clientRect.right / 2, clientRect.bottom / 2);
	CR = cr;
	SetTimer(0, 500, NULL);
	OnTimer(0);
}


