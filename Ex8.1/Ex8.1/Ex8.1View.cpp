
// Ex8.1View.cpp : CEx81View ���ʵ��
//

#include "stdafx.h"
#include "MyDialog.h"
#include "MyDialog2.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex8.1.h"
#endif

#include "Ex8.1Doc.h"
#include "Ex8.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEx81View

IMPLEMENT_DYNCREATE(CEx81View, CView)

BEGIN_MESSAGE_MAP(CEx81View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_EDITSHOW, &CEx81View::OnEditshow)
	ON_COMMAND(ID_LISTSHOW, &CEx81View::OnListshow)
END_MESSAGE_MAP()

// CEx81View ����/����

CEx81View::CEx81View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx81View::~CEx81View()
{
}

BOOL CEx81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx81View ����

void CEx81View::OnDraw(CDC* /*pDC*/)
{
	CEx81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 1)
	{
		MyDialog *pD = new MyDialog;
		pD->d1 = s;
		pD->Create(IDD_DIALOG1);
		pD->ShowWindow(1);
		flag = 0;
	}
	if (flag == 2)
	{
		MyDialog2 *pD = new MyDialog2;
		pD->Create(IDD_DIALOG2);
		pD->ShowWindow(1);
		flag = 0;
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx81View ���

#ifdef _DEBUG
void CEx81View::AssertValid() const
{
	CView::AssertValid();
}

void CEx81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx81Doc* CEx81View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx81Doc)));
	return (CEx81Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx81View ��Ϣ�������


void CEx81View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFileDialog cfd(true);
	r = cfd.DoModal();
	if (r == IDOK)
	{
		s = cfd.GetFileName();
	}
	GetDC()->TextOutW(400, 300, s);
	CView::OnLButtonDblClk(nFlags, point);
}


void CEx81View::OnEditshow()
{
	// TODO: �ڴ���������������
	flag = 1;
	Invalidate();
}


void CEx81View::OnListshow()
{
	// TODO: �ڴ���������������
	flag = 2;
	Invalidate();
}
