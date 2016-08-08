// TRecordset.cpp : implementation file
//

#include "stdafx.h"
#include "lhwy.h"
#include "TRecordset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTRecordset

IMPLEMENT_DYNAMIC(CTRecordset, CRecordset)

CTRecordset::CTRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTRecordset)
	m_column1 = _T("");
	m_column2 = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CTRecordset::GetDefaultConnect()
{
	return _T("ODBC;DSN=lhwy");
}

CString CTRecordset::GetDefaultSQL()
{
	return _T("[NO1TECHER]");
}

void CTRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTRecordset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[科目]"), m_column1);
	RFX_Text(pFX, _T("[任课老师]"), m_column2);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTRecordset diagnostics

#ifdef _DEBUG
void CTRecordset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTRecordset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
