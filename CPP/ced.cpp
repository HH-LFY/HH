// ced.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "ced.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ced dialog


ced::ced(CWnd* pParent /*=NULL*/)
	: CDialog(ced::IDD, pParent)
{
	//{{AFX_DATA_INIT(ced)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ced::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ced)
	DDX_Control(pDX, IDC_LIST1, m_ctllist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ced, CDialog)
	//{{AFX_MSG_MAP(ced)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ced message handlers
