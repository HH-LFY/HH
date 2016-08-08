// Addialog.cpp : implementation file
//

#include "stdafx.h"
#include "lhwy.h"
#include "Addialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddialog dialog


CAddialog::CAddialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAddialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddialog)
	m_fchemistry = 0.0f;
	m_fenglish = 0.0f;
	m_fmaths = 0.0f;
	m_strName = _T("");
	m_fphysical = 0.0f;
	m_nxue = 0;
	m_fpolitic = 0.0f;
	//}}AFX_DATA_INIT
}


void CAddialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddialog)
	DDX_Control(pDX, IDOK, m_OkButton);
	DDX_Control(pDX, IDCANCEL, m_CancelButton);
	DDX_Text(pDX, IDC_CHMISTRY, m_fchemistry);
	DDV_MinMaxFloat(pDX, m_fchemistry, 0.f, 100.f);
	DDX_Text(pDX, IDC_ENGLISH, m_fenglish);
	DDV_MinMaxFloat(pDX, m_fenglish, 0.f, 100.f);
	DDX_Text(pDX, IDC_MATHS, m_fmaths);
	DDV_MinMaxFloat(pDX, m_fmaths, 0.f, 100.f);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_PHYCICAL, m_fphysical);
	DDV_MinMaxFloat(pDX, m_fphysical, 0.f, 100.f);
	DDX_Text(pDX, IDC_XUEHAO, m_nxue);
	DDV_MinMaxInt(pDX, m_nxue, 1, 1000000);
	DDX_Text(pDX, IDC_POLITIC, m_fpolitic);
	DDV_MinMaxFloat(pDX, m_fpolitic, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddialog, CDialog)
	//{{AFX_MSG_MAP(CAddialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddialog message handlers
