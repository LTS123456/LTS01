
// Ex13.3View.cpp : CEx133View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex13.3.h"
#endif

#include "Ex13.3Set.h"
#include "Ex13.3Doc.h"
#include "Ex13.3View.h"
#include "ADD_DIALOG.h"
#include "DEL_DIALOG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx133View

IMPLEMENT_DYNCREATE(CEx133View, CRecordView)

BEGIN_MESSAGE_MAP(CEx133View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON3, &CEx133View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CEx133View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CEx133View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CEx133View 构造/析构

CEx133View::CEx133View()
	: CRecordView(IDD_EX133_FORM)
	, m_1(0)
	, m_2(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CEx133View::~CEx133View()
{
}

void CEx133View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
}

BOOL CEx133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CEx133View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex133Set;
	CRecordView::OnInitialUpdate();

}


// CEx133View 诊断

#ifdef _DEBUG
void CEx133View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx133View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx133Doc* CEx133View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx133Doc)));
	return (CEx133Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx133View 数据库支持
CRecordset* CEx133View::OnGetRecordset()
{
	return m_pSet;
}



// CEx133View 消息处理程序


void CEx133View::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(FALSE);
}


void CEx133View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD_DIALOG dia;
	int r = dia.DoModal();
	if (r == IDOK)
	{
		long add = dia.m_add;
		m_pSet->AddNew();
		m_pSet->m_1 = add;
		m_pSet->Update();
		UpdateData(FALSE);
	}
}


void CEx133View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	change = m_pSet->m_1;
	DEL_DIALOG dia;
	int r = dia.DoModal();
	if (r == IDOK)
	{
		long del = dia.m_del;
		m_pSet->Edit();
		m_pSet->m_1 = del;
		m_pSet->Update();
		UpdateData(FALSE);
	}
}
