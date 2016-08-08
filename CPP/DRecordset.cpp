// DRecordset.cpp : implementation file
//

#include "stdafx.h"
#include "lhwy.h"
#include "DRecordset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDRecordset

IMPLEMENT_DYNAMIC(CDRecordset, CRecordset)

CDRecordset::CDRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDRecordset)
	m_column1 = 0;
	m_column2 = _T("");
	m_column3 = 0.0f;
	m_column4 = 0.0f;
	m_column5 = 0.0f;
	m_column6 = 0.0f;
	m_column7 = 0.0f;
	m_column8 = 0.0f;
	m_column9 = 0.0f;
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDRecordset::GetDefaultConnect()
{
	return _T("ODBC;DSN=lhwy");
}

CString CDRecordset::GetDefaultSQL()
{
	return _T("[NO1STUDENT]");
}

void CDRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDRecordset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ѧ��]"), m_column1);
	RFX_Text(pFX, _T("[����]"), m_column2);
	RFX_Single(pFX, _T("[��ѧ]"), m_column3);
	RFX_Single(pFX, _T("[����]"), m_column4);
	RFX_Single(pFX, _T("[��ѧ]"), m_column5);
	RFX_Single(pFX, _T("[Ӣ��]"), m_column6);
	RFX_Single(pFX, _T("[����]"), m_column7);
	RFX_Single(pFX, _T("[�ܳɼ�]"), m_column8);
	RFX_Single(pFX, _T("[ƽ���ɼ�]"), m_column9);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDRecordset diagnostics

#ifdef _DEBUG
void CDRecordset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDRecordset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
