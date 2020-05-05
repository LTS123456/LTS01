
// Ex10.4View.cpp : CEx104View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex10.4.h"
#endif

#include "Ex10.4Set.h"
#include "Ex10.4Doc.h"
#include "Ex10.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx104View

IMPLEMENT_DYNCREATE(CEx104View, CRecordView)

BEGIN_MESSAGE_MAP(CEx104View, CRecordView)
END_MESSAGE_MAP()

// CEx104View 构造/析构

CEx104View::CEx104View()
	: CRecordView(IDD_EX104_FORM)
	, ID(0)
	, snum(_T(""))
	, sname(_T(""))
	, age(0)
	, telenum(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CEx104View::~CEx104View()
{
}

void CEx104View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
}

BOOL CEx104View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CEx104View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex104Set;
	CRecordView::OnInitialUpdate();

}


// CEx104View 诊断

#ifdef _DEBUG
void CEx104View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx104View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx104Doc* CEx104View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx104Doc)));
	return (CEx104Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx104View 数据库支持
CRecordset* CEx104View::OnGetRecordset()
{
	return m_pSet;
}



// CEx104View 消息处理程序
