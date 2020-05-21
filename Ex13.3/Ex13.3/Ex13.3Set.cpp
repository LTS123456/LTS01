
// Ex13.3Set.cpp : CEx133Set ���ʵ��
//

#include "stdafx.h"
#include "Ex13.3.h"
#include "Ex13.3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx133Set ʵ��

// ���������� 2020��5��21��, 22:45

IMPLEMENT_DYNAMIC(CEx133Set, CRecordset)

CEx133Set::CEx133Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CEx133Set::GetDefaultConnect()
{
	return _T("DSN=d4;DBQ=C:\\Users\\ling\\Desktop\\d4.mdb;DefaultDir=C:\\Users\\ling\\Desktop;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CEx133Set::GetDefaultSQL()
{
	return _T("[��1]");
}

void CEx133Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CEx133Set ���

#ifdef _DEBUG
void CEx133Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEx133Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

