
// Ex9.3View.cpp : CEx93View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex9.3.h"
#endif

#include "Ex9.3Doc.h"
#include "Ex9.3View.h"
#include "iostream"
#include "string"
#include "fstream"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int flag;


// CEx93View

IMPLEMENT_DYNCREATE(CEx93View, CView)

BEGIN_MESSAGE_MAP(CEx93View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CEx93View::OnFileOpen)
//	ON_WM_CLOSE()
END_MESSAGE_MAP()

// CEx93View 构造/析构

CEx93View::CEx93View()
{
	// TODO: 在此处添加构造代码

}

CEx93View::~CEx93View()
{
}

BOOL CEx93View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx93View 绘制

void CEx93View::OnDraw(CDC* pDC)
{
	CEx93Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	if (count != 0)
	{
		int i;
		CString filename = _T("G:\\MyPoject\\Ex9.3\\Ellipse.txt");
		ofstream of(filename);
		for (i = 0; i < count; i++)
		{
			pDC->Ellipse(a[i]);
			of << a[i].left << ' ' << a[i].top << ' ' << a[i].right << ' ' << a[i].bottom << endl;
		}
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx93View 诊断

#ifdef _DEBUG
void CEx93View::AssertValid() const
{
	CView::AssertValid();
}

void CEx93View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx93Doc* CEx93View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx93Doc)));
	return (CEx93Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx93View 消息处理程序


void CEx93View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1;
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CEx93View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1)
	{
		cr.right = point.x;
		cr.bottom = point.y;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CEx93View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 0;
	a.Add(cr);
	count++;
	CView::OnLButtonUp(nFlags, point);
}


void CEx93View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CString filename = _T("G:\\MyPoject\\Ex9.3\\Ellipse.txt");
	ifstream ifs(filename);
	string s;
	int count = 0, i = 0;
	int num[4];
	while (ifs >> s)
	{
		num[i] = atoi(s.c_str());
		i++;
		count++;
		if (count % 4 == 0)
		{
			CRect cr(num[0], num[1], num[2], num[3]);
			dc.Ellipse(cr);
			i = 0;
		}
	}
}


