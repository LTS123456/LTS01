
// Ex12.1Doc.h : CEx121Doc ��Ľӿ�
//


#pragma once
#include "Ex12.1Set.h"


class CEx121Doc : public CDocument
{
protected: // �������л�����
	CEx121Doc();
	DECLARE_DYNCREATE(CEx121Doc)

// ����
public:
	CEx121Set m_Ex121Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CEx121Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
