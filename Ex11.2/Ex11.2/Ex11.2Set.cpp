
// Ex11.2Set.cpp : CEx112Set ���ʵ��
//

#include "stdafx.h"
#include "Ex11.2.h"
#include "Ex11.2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx112Set ʵ��

// ���������� 2020��5��15��, 10:13

IMPLEMENT_DYNAMIC(CEx112Set, CRecordset)

CEx112Set::CEx112Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0.0;
	column1 = L"";
	column2 = L"";
	column3 = 0.0;
	column4 = 0.0;
	column5 = L"";
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CEx112Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f;DBQ=C:\\Users\\ling\\Desktop\\\x5b66\x751f\x4fe1\x606f.xls;DefaultDir=C:\\Users\\ling\\Desktop;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CEx112Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CEx112Set::DoFieldExchange(CFieldExchange* pFX)
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
	RFX_Text(pFX, _T("[��Ƭ·��]"), column5);

}
/////////////////////////////////////////////////////////////////////////////
// CEx112Set ���

#ifdef _DEBUG
void CEx112Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEx112Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

