
// Ex13.1Set.cpp : CEx131Set ���ʵ��
//

#include "stdafx.h"
#include "Ex13.1.h"
#include "Ex13.1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx131Set ʵ��

// ���������� 2020��5��21��, 9:33

IMPLEMENT_DYNAMIC(CEx131Set, CRecordset)

CEx131Set::CEx131Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_0jpg = L"";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CEx131Set::GetDefaultConnect()
{
	return _T("DSN=\x7167\x7247;DBQ=C:\\Users\\ling\\Desktop\\\x7167\x7247.xls;DefaultDir=C:\\Users\\ling\\Desktop;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CEx131Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CEx131Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[0#jpg]"), m_0jpg);

}
/////////////////////////////////////////////////////////////////////////////
// CEx131Set ���

#ifdef _DEBUG
void CEx131Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEx131Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

