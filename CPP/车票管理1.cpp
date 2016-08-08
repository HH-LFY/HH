// 车票管理1.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "车票管理1.h"
#include "车票管理1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1App

BEGIN_MESSAGE_MAP(CMy1App, CWinApp)
	//{{AFX_MSG_MAP(CMy1App)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1App construction

CMy1App::CMy1App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMy1App object

CMy1App theApp;

/////////////////////////////////////////////////////////////////////////////
// CMy1App initialization

BOOL CMy1App::InitInstance()
{
	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	if (RunEmbedded() || RunAutomated())
	{
		COleTemplateServer::RegisterAll();
	}
	else
	{
		COleObjectFactory::UpdateRegistryAll();
	}

	CMy1Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
