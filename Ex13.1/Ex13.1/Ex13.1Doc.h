
// Ex13.1Doc.h : CEx131Doc ��Ľӿ�
//


#pragma once
#include "Ex13.1Set.h"


class CEx131Doc : public CDocument
{
protected: // �������л�����
	CEx131Doc();
	DECLARE_DYNCREATE(CEx131Doc)

// ����
public:
	CEx131Set m_Ex131Set;

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
	virtual ~CEx131Doc();
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
