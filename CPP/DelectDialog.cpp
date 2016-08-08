// DelectDialog.cpp : implementation file
//

#include "stdafx.h"
#include "lhwy.h"
#include "DelectDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDelectDialog dialog


CDelectDialog::CDelectDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CDelectDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDelectDialog)
	m_nPass = 0;
	m_nxue = 0;
	//}}AFX_DATA_INIT
}


void CDelectDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDelectDialog)
	DDX_Control(pDX, IDOK, m_OkButton);
	DDX_Control(pDX, IDCANCEL, m_CancelButton);
	DDX_Text(pDX, IDC_PASS, m_nPass);
	DDX_Text(pDX, IDC_XUEHAO, m_nxue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDelectDialog, CDialog)
	//{{AFX_MSG_MAP(CDelectDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDelectDialog message handlers
