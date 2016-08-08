// lhwy.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "lhwy.h"
#include "lhwyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include <odbcinst.h>

/////////////////////////////////////////////////////////////////////////////
// CLhwyApp

BEGIN_MESSAGE_MAP(CLhwyApp, CWinApp)
	//{{AFX_MSG_MAP(CLhwyApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLhwyApp construction

CLhwyApp::CLhwyApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLhwyApp object

CLhwyApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CLhwyApp initialization

BOOL CLhwyApp::InitInstance()
{
//  AfxGetModuleState()->m_dwVersion = 0x0601;

 
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

    CString sPath;
	GetModuleFileName(NULL,sPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);
	sPath.ReleaseBuffer ();
	int nPos;
	nPos=sPath.ReverseFind ('\\');
	sPath=sPath.Left (nPos);
	nPos=sPath.ReverseFind('\\');
    sPath=sPath.Left (nPos);
	CString lpszFile = sPath + "\\lhwy.mdb";
	
   
    char* szDesc;
	int mlen;
	szDesc=new char[256];
	sprintf(szDesc,"DSN=%s? DESCRIPTION=TOC support source? DBQ=%s? FIL=MicrosoftAccess? DEFAULTDIR=%s?? ","lhwy",lpszFile,sPath);



	mlen = strlen(szDesc);
    for (int i=0; i<mlen; i++)
	{
	if (szDesc[i] == '?')
	 szDesc[i] = '\0';
	}

  if (FALSE == SQLConfigDataSource(NULL,ODBC_ADD_DSN,"Microsoft Access Driver (*.mdb)\0",(LPCSTR)szDesc))
  AfxMessageBox("SQLConfigDataSource Failed");
				

    try
	{
     CString strConnect;
	 strConnect.Format("DSN=lhwy;");
	 if(!m_DB.OpenEx(strConnect,CDatabase::useCursorLib))
     {
     AfxMessageBox("Unable to Connect to the Specified Data Source");
     return FALSE ;
     }
	CString str;
	 //str=m_DB.GetConnect();
	// AfxMessageBox(str);
// str=m_DB.GetDatabaseName();
//	AfxMessageBox(str);
//if(FALSE==	m_DB.CanUpdate())
//AfxMessageBox("FALSE");
//else 
//AfxMessageBox("TRUE");
//	if(FALSE==m_DB.CanTransact())
//		AfxMessageBox("FALSE");
//	else 
//		AfxMessageBox("TRUE");
	}
   catch(CDBException *pE)
    {
        pE->ReportError();
        pE->Delete();
        return FALSE;
    }

	AfxEnableControlContainer();
	//SetDialogBkColor(RGB(140,130,210),RGB(255,0,0));
    SetDialogBkColor(RGB (140, 180, 220), RGB ( 255 ,0 , 0 ) );
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CLhwyDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

