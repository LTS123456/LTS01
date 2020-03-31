
// Ex6.1View.cpp : CEx61View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex6.1.h"
#endif

#include "Ex6.1Doc.h"
#include "Ex6.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString s;
int sx, sy;
CImage img;
int r;
CRect cr;
// CEx61View

IMPLEMENT_DYNCREATE(CEx61View, CView)

BEGIN_MESSAGE_MAP(CEx61View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CEx61View::OnFileOpen)
END_MESSAGE_MAP()

// CEx61View 构造/析构

CEx61View::CEx61View()
{
	// TODO: 在此处添加构造代码

}

CEx61View::~CEx61View()
{
}

BOOL CEx61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx61View 绘制

void CEx61View::OnDraw(CDC* pDC)
{
	CEx61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&cr);
	sx = cr.Width() / 2 - img.GetWidth() / 2;
	sy = cr.Height() / 2 - img.GetHeight() / 2;
	img.Draw(pDC->m_hDC, sx, sy, img.GetWidth(), img.GetHeight());
	pDC->TextOutW(sx, sy + img.GetHeight() + 20, s);
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx61View 诊断

#ifdef _DEBUG
void CEx61View::AssertValid() const
{
	CView::AssertValid();
}

void CEx61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx61Doc* CEx61View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx61Doc)));
	return (CEx61Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx61View 消息处理程序


void CEx61View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	r = cfd.DoModal();
	if (r == IDOK)
	{
		s = cfd.GetPathName();
		img.Load(s);
	}
	Invalidate();
}
