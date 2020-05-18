
// Ex12.2Set.cpp : CEx122Set ���ʵ��
//

#include "stdafx.h"
#include "Ex12.2.h"
#include "Ex12.2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx122Set ʵ��

// ���������� 2020��5��18��, 15:46

IMPLEMENT_DYNAMIC(CEx122Set, CRecordset)

CEx122Set::CEx122Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_0jpg = L"";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CEx122Set::GetDefaultConnect()
{
	return _T("DSN=\x7167\x7247;DBQ=C:\\Users\\ling\\Desktop\\\x7167\x7247.xls;DefaultDir=C:\\Users\\ling\\Desktop;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CEx122Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CEx122Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[0#jpg]"), m_0jpg);

}
/////////////////////////////////////////////////////////////////////////////
// CEx122Set ���

#ifdef _DEBUG
void CEx122Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEx122Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

