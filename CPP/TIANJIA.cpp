// TIANJIA.cpp : implementation file
//

#include "stdafx.h"
#include "testt1.h"
#include "TIANJIA.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TIANJIA dialog


TIANJIA::TIANJIA(CWnd* pParent /*=NULL*/)
	: CDialog(TIANJIA::IDD, pParent)
{
	//{{AFX_DATA_INIT(TIANJIA)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void TIANJIA::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TIANJIA)
	DDX_Control(pDX, IDC_EDIT6, m_5);
	DDX_Control(pDX, IDC_EDIT5, m_4);
	DDX_Control(pDX, IDC_EDIT4, m_3);
	DDX_Control(pDX, IDC_EDIT3, m_2);
	DDX_Control(pDX, IDC_EDIT1, m_1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TIANJIA, CDialog)
	//{{AFX_MSG_MAP(TIANJIA)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TIANJIA message handlers
