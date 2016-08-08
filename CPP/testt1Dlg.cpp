// testt1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "testt1.h"
#include "testt1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestt1Dlg dialog

CTestt1Dlg::CTestt1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestt1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestt1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestt1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestt1Dlg)
	DDX_Control(pDX, IDC_LIST1, m_ctllist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestt1Dlg, CDialog)
	//{{AFX_MSG_MAP(CTestt1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDD_ABOUTBOX, OnAboutbox)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_BN_CLICKED(SHANCHU, OnSHANCHU)
	ON_BN_CLICKED(IDC_BUTTON2, ONSHOUPIAO)
	ON_EN_CHANGE(IDC_TIME, OnChangeTime)
	ON_BN_CLICKED(ID_TIANJIA, OnTianjia)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestt1Dlg message handlers

BOOL CTestt1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestt1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestt1Dlg::OnPaint() 
{              
	DWORD k = m_ctllist.GetExtendedStyle();  //添加列表框的网格线！！！

	k = LVS_EX_FULLROWSELECT;//--FullRowSelect当选中一项时，它的子项是否同该项一起突出显示 --Items所有项的集合
    k = LVS_EX_GRIDLINES;            //显示网格线    
    m_ctllist.SetExtendedStyle(k);   //设置网格线
    m_ctllist.InsertColumn(0,"班次",LVCFMT_LEFT,40);              //添加列标题！！！！  这里的80,40,90用以设置列的宽度。！！！LVCFMT_LEFT用来设置对齐方式！！！
	m_ctllist.InsertColumn(1,"发车时间",LVCFMT_LEFT,80);
	m_ctllist.InsertColumn(2,"起点站",LVCFMT_LEFT,80);
	m_ctllist.InsertColumn(3,"终点站",LVCFMT_LEFT,80);
	m_ctllist.InsertColumn(4,"行车时间",LVCFMT_LEFT,80);
	m_ctllist.InsertColumn(5,"额定载量",LVCFMT_LEFT,80);
	m_ctllist.InsertColumn(6,"已订票人数",LVCFMT_LEFT,80);
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestt1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestt1Dlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}



void CTestt1Dlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CTestt1Dlg::OnAboutbox() 
{
	// TODO: Add your control notification handler code here
	
}

void CTestt1Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	MessageBox(TEXT(""),TEXT(""),MB_OK);
}


void CTestt1Dlg::OnChangeEdit2() 
{
}

void CTestt1Dlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	MessageBox(TEXT(""),TEXT(""),MB_OK);
}

void CTestt1Dlg::OnDoubleclickedAdd() 
{

}

void CTestt1Dlg::OnDell() 
{

}


void CTestt1Dlg::OnSHANCHU() 
{
	// TODO: Add your control notification handler code here
	m_ctllist.DeleteAllItems();
}

void CTestt1Dlg::ONSHOUPIAO() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg A;
	A.DoModal();
}

void CTestt1Dlg::OnChangeTime() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CTestt1Dlg::OnTianjia() 
{
	
}
