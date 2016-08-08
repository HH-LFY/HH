// EditDialog.cpp : implementation file
//

#include "stdafx.h"
#include "lhwy.h"
#include "EditDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditDialog dialog


CEditDialog::CEditDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditDialog)
	m_fchemistry = 0.0f;
	m_fenglish = 0.0f;
	m_fmaths = 0.0f;
	m_pass = _T("");
	m_fphysical = 0.0f;
	m_fpolitic = 0.0f;
	m_xue = 0;
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void CEditDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditDialog)
	DDX_Control(pDX, IDOK, m_OkButton);
	DDX_Control(pDX, IDCANCEL, m_CancelButton);
	DDX_Text(pDX, IDC_CHEMISTRY, m_fchemistry);
	DDX_Text(pDX, IDC_ENGLISH, m_fenglish);
	DDX_Text(pDX, IDC_MATHS, m_fmaths);
	DDX_Text(pDX, IDC_PASS, m_pass);
	DDX_Text(pDX, IDC_PHYSICAL, m_fphysical);
	DDX_Text(pDX, IDC_POLITIC, m_fpolitic);
	DDX_Text(pDX, IDC_XUE, m_xue);
	DDX_Text(pDX, IDC_NAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditDialog, CDialog)
	//{{AFX_MSG_MAP(CEditDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditDialog message handlers
