
// Ex9.1View.cpp : CEx91View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex9.1.h"
#endif

#include "Ex9.1Doc.h"
#include "Ex9.1View.h"
#include "fstream"
#include "string"
#include "iostream"
#include "MyDialog.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int flag = 0;

// CEx91View

IMPLEMENT_DYNCREATE(CEx91View, CView)

BEGIN_MESSAGE_MAP(CEx91View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CEx91View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CEx91View::OnFileSaveAs)
END_MESSAGE_MAP()

// CEx91View 构造/析构

CEx91View::CEx91View()
{
	// TODO: 在此处添加构造代码
	
}

CEx91View::~CEx91View()
{
}

BOOL CEx91View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx91View 绘制

void CEx91View::OnDraw(CDC* /*pDC*/)
{
	CEx91Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
}


// CEx91View 诊断

#ifdef _DEBUG
void CEx91View::AssertValid() const
{
	CView::AssertValid();
}

void CEx91View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx91Doc* CEx91View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx91Doc)));
	return (CEx91Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx91View 消息处理程序


void CEx91View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	string s;
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ifstream in(cfd.GetPathName());
		in >> s;
		filename= s.c_str();
		flag = 1;
	}
	if (flag == 1)
	{
		MyDialog *dia = new MyDialog;
		dia->Create(IDD_DIALOG1);
		dia->ShowWindow(1);
	}
}

void CEx91View::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream out (_T("C:\\Users\\ling\\Desktop\\abc.txt"));
		CString s = cfd.GetPathName();
		out << CT2A(s.GetString()) << endl;
	}
}
