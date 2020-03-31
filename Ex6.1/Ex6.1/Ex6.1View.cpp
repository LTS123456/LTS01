
// Ex6.1View.cpp : CEx61View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CEx61View ����/����

CEx61View::CEx61View()
{
	// TODO: �ڴ˴���ӹ������

}

CEx61View::~CEx61View()
{
}

BOOL CEx61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx61View ����

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
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx61View ���

#ifdef _DEBUG
void CEx61View::AssertValid() const
{
	CView::AssertValid();
}

void CEx61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx61Doc* CEx61View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx61Doc)));
	return (CEx61Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx61View ��Ϣ�������


void CEx61View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	r = cfd.DoModal();
	if (r == IDOK)
	{
		s = cfd.GetPathName();
		img.Load(s);
	}
	Invalidate();
}
