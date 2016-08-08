// BRecordset.cpp : implementation file
//

#include "stdafx.h"
#include "lhwy.h"
#include "BRecordset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBRecordset

IMPLEMENT_DYNAMIC(CBRecordset, CRecordset)

CBRecordset::CBRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBRecordset)
	m_column1 = _T("");
	m_column2 = 0.0f;
	m_column3 = 0.0f;
	m_column4 = 0;
	m_column5 = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CBRecordset::GetDefaultConnect()
{
	return _T("ODBC;DSN=lhwy");
}

CString CBRecordset::GetDefaultSQL()
{
	return _T("[NO1OBJECT]");
}

void CBRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBRecordset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[科目]"), m_column1);
	RFX_Single(pFX, _T("[总成绩]"), m_column2);
	RFX_Single(pFX, _T("[平均成绩]"), m_column3);
	RFX_Long(pFX, _T("[及格人数]"), m_column4);
	RFX_Long(pFX, _T("[优秀人数]"), m_column5);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBRecordset diagnostics

#ifdef _DEBUG
void CBRecordset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBRecordset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
