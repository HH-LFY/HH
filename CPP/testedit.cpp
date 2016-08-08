// testedit.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "testedit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// testedit dialog


testedit::testedit(CWnd* pParent /*=NULL*/)
	: CDialog(testedit::IDD, pParent)
{
	//{{AFX_DATA_INIT(testedit)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void testedit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(testedit)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(testedit, CDialog)
	//{{AFX_MSG_MAP(testedit)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// testedit message handlers

int testedit::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}
