
// Ex13.3Doc.h : CEx133Doc ��Ľӿ�
//


#pragma once
#include "Ex13.3Set.h"


class CEx133Doc : public CDocument
{
protected: // �������л�����
	CEx133Doc();
	DECLARE_DYNCREATE(CEx133Doc)

// ����
public:
	CEx133Set m_Ex133Set;

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
	virtual ~CEx133Doc();
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
