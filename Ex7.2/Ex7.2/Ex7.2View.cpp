
// Ex7.2View.cpp : CEx72View 类的实现
//

#include "stdafx.h"
#include "MyDialog.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex7.2.h"
#endif

#include "Ex7.2Doc.h"
#include "Ex7.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx72View

IMPLEMENT_DYNCREATE(CEx72View, CView)

BEGIN_MESSAGE_MAP(CEx72View, CView)
	ON_COMMAND(ID_COUNT, &CEx72View::OnCount)
END_MESSAGE_MAP()

// CEx72View 构造/析构

CEx72View::CEx72View()
{
	// TODO: 在此处添加构造代码

}

CEx72View::~CEx72View()
{
}

BOOL CEx72View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx72View 绘制

void CEx72View::OnDraw(CDC* /*pDC*/)
{
	CEx72Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEx72View 诊断

#ifdef _DEBUG
void CEx72View::AssertValid() const
{
	CView::AssertValid();
}

void CEx72View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx72Doc* CEx72View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx72Doc)));
	return (CEx72Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx72View 消息处理程序


void CEx72View::OnCount()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog dia;
	int sum;
	CClientDC dc(this);
	int r = dia.DoModal();
	if (r == IDOK)
	{
		int A = dia.a;
		int B = dia.b;
		sum = A + B;
		CString c;
		c.Format(_T("计算的结果是：%d"), sum);
		dc.TextOutW(600, 200, c);
	}
}
