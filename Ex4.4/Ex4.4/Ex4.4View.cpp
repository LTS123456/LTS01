
// Ex4.4View.cpp : CEx44View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex4.4.h"
#endif

#include "Ex4.4Doc.h"
#include "Ex4.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx44View

IMPLEMENT_DYNCREATE(CEx44View, CView)

BEGIN_MESSAGE_MAP(CEx44View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CEx44View ����/����

CEx44View::CEx44View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx44View::~CEx44View()
{
}

BOOL CEx44View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx44View ����

void CEx44View::OnDraw(CDC* pDC)
{
	CEx44Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (pDoc->set)
	{
		for (int i=0; i < 5; i++)
		{
			SetTimer(i, rand() % 250 + 300, NULL);
		}
		pDoc->set = false;
	}
	for (int i = 0; i < pDoc->N; i++)
	{
		pDC->Ellipse(pDoc->a[i]);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx44View ���

#ifdef _DEBUG
void CEx44View::AssertValid() const
{
	CView::AssertValid();
}

void CEx44View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx44Doc* CEx44View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx44Doc)));
	return (CEx44Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx44View ��Ϣ�������

int flag1 = 1;
int flag2 = 1;
int flag3 = 1;
int flag4 = 1;
int flag5 = 1;
void CEx44View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEx44Doc* pDoc = GetDocument();
	CRect clientRect;
	GetClientRect(&clientRect);
	int i = nIDEvent;
	switch (i)
	{
	case 0:
	{
		if (pDoc->a[0].bottom >= clientRect.bottom)
			flag1 = 0;
		if (flag1)
		{
			pDoc->a[0].top += 10;
			pDoc->a[0].bottom += 10;
		}
		else
		{
			pDoc->a[0].top -= 10;
			pDoc->a[0].bottom -= 10;
		}
		Invalidate();
	}
	break;
	case 1:
	{
		if (pDoc->a[1].bottom >= clientRect.bottom)
			flag2 = 0;
		if (flag2)
		{
			pDoc->a[1].top += 10;
			pDoc->a[1].bottom += 10;
		}
		else
		{
			pDoc->a[1].top -= 10;
			pDoc->a[1].bottom -= 10;
		}
		Invalidate();
	}
	break;
	case 2:
	{
		if (pDoc->a[2].bottom >= clientRect.bottom)
			flag3 = 0;
		if (flag3)
		{
			pDoc->a[2].top += 10;
			pDoc->a[2].bottom += 10;
		}
		else
		{
			pDoc->a[2].top -= 10;
			pDoc->a[2].bottom -= 10;
		}
		Invalidate();
	}
	break;
	case 3:
	{
		if (pDoc->a[3].bottom >= clientRect.bottom)
			flag4 = 0;
		if (flag4)
		{
			pDoc->a[3].top += 10;
			pDoc->a[3].bottom += 10;
		}
		else
		{
			pDoc->a[3].top -= 10;
			pDoc->a[3].bottom -= 10;
		}
		Invalidate();
	}
	break;
	case 4:
	{
		if (pDoc->a[4].bottom >= clientRect.bottom)
			flag5 = 0;
		if (flag5)
		{
			pDoc->a[4].top += 10;
			pDoc->a[4].bottom += 10;
		}
		else
		{
			pDoc->a[4].top -= 10;
			pDoc->a[4].bottom -= 10;
		}
		Invalidate();
	}
	break;
	}
	CView::OnTimer(nIDEvent);
}
