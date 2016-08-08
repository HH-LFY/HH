// FinDialog.cpp : implementation file
//

#include "stdafx.h"
#include "lhwy.h"
#include "FinDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFinDialog dialog


CFinDialog::CFinDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CFinDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFinDialog)
	m_find = 0.0f;
	//}}AFX_DATA_INIT
}


void CFinDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFinDialog)
	DDX_Control(pDX, IDOK, m_OkButton);
	DDX_Control(pDX, IDCANCEL, m_CancelButton);
	DDX_Control(pDX, IDC_COMBO2, m_com);
	DDX_Control(pDX, IDC_COMBO1, m_cob);
	DDX_Text(pDX, IDC_FIND, m_find);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFinDialog, CDialog)
	//{{AFX_MSG_MAP(CFinDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFinDialog message handlers

void CFinDialog::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
    m_cob.GetLBText(m_cob.GetCurSel(),m_Getstring1);

    m_com.GetLBText(m_com.GetCurSel(),m_Getstring2);
	
	CDialog::OnOK();
}

BOOL CFinDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_com.SetCurSel(1);
	m_cob.SetCurSel(2);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
