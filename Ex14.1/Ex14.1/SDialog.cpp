// SDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ex14.1.h"
#include "Ex14.1Set.h"
#include "SDialog.h"
#include "afxdialogex.h"



// SDialog �Ի���

IMPLEMENT_DYNAMIC(SDialog, CDialogEx)

SDialog::SDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{
	m_pSet = NULL;
}

SDialog::~SDialog()
{
}

void SDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(SDialog, CDialogEx)
END_MESSAGE_MAP()


// SDialog ��Ϣ�������


BOOL SDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_pSet->MoveFirst();
	m_list.ResetContent();
	CString s;
	int n = m_pSet->GetODBCFieldCount();
	while (!m_pSet->IsEOF())
	{
		s.Empty();

		for (int i = 0; i < n; i++)
		{
			CString temp;
			m_pSet->GetFieldValue((short)i, temp);
			s += temp;
			s += _T("    ");
		}
		m_list.AddString(s);
		m_pSet->MoveNext();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
