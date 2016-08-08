// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "车票管理1.h"
#include "DlgProxy.h"
#include "车票管理1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1DlgAutoProxy

IMPLEMENT_DYNCREATE(CMy1DlgAutoProxy, CCmdTarget)

CMy1DlgAutoProxy::CMy1DlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CMy1Dlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CMy1Dlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CMy1DlgAutoProxy::~CMy1DlgAutoProxy()
{
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CMy1DlgAutoProxy::OnFinalRelease()
{
	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMy1DlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CMy1DlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMy1DlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CMy1DlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IMy1 to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {E03A4606-3FC7-43B0-980B-4807C398444B}
static const IID IID_IMy1 =
{ 0xe03a4606, 0x3fc7, 0x43b0, { 0x98, 0xb, 0x48, 0x7, 0xc3, 0x98, 0x44, 0x4b } };

BEGIN_INTERFACE_MAP(CMy1DlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CMy1DlgAutoProxy, IID_IMy1, Dispatch)
END_INTERFACE_MAP()

// {48CD9F96-0BB3-43EB-A49B-60E527142735}
IMPLEMENT_OLECREATE2(CMy1DlgAutoProxy, "My1.Application", 0x48cd9f96, 0xbb3, 0x43eb, 0xa4, 0x9b, 0x60, 0xe5, 0x27, 0x14, 0x27, 0x35)

/////////////////////////////////////////////////////////////////////////////
// CMy1DlgAutoProxy message handlers
