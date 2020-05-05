
// Ex10.4Set.cpp : CEx104Set ���ʵ��
//

#include "stdafx.h"
#include "Ex10.4.h"
#include "Ex10.4Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx104Set ʵ��

// ���������� 2020��5��5��, 15:42

IMPLEMENT_DYNAMIC(CEx104Set, CRecordset)

CEx104Set::CEx104Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0.0;
	column1 = L"";
	column2 = L"";
	column3 = 0.0;
	column4 = 0.0;
	m_nFields = 5;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CEx104Set::GetDefaultConnect()
{
	return _T("DSN=\x4fe1\x606f;DBQ=C:\\Users\\ling\\Desktop\\\x5b66\x751f\x4fe1\x606f.xls;DefaultDir=C:\\Users\\ling\\Desktop;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CEx104Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CEx104Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Double(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[ѧ��]"), column1);
	RFX_Text(pFX, _T("[����]"), column2);
	RFX_Double(pFX, _T("[����]"), column3);
	RFX_Double(pFX, _T("[�ֻ���]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// CEx104Set ���

#ifdef _DEBUG
void CEx104Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEx104Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

