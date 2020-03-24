
// Ex5.1View.cpp : CEx51View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CEx51View ����/����

CEx51View::CEx51View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx51View::~CEx51View()
{
}

BOOL CEx51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx51View ����

void CEx51View::OnDraw(CDC* /*pDC*/)
{
	CEx51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx51View ���

#ifdef _DEBUG
void CEx51View::AssertValid() const
{
	CView::AssertValid();
}

void CEx51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx51Doc* CEx51View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx51Doc)));
	return (CEx51Doc*)m_pDocument;
}
#endif //_DEBUG
CRect CR;

// CEx51View ��Ϣ�������
void CEx51View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ���������������
	CRect clientRect;
	GetClientRect(&clientRect);
	CRect cr(clientRect.right / 2, clientRect.bottom / 2, clientRect.right / 2, clientRect.bottom / 2);
	CR = cr;
	SetTimer(0, 500, NULL);
	OnTimer(0);
}


