// 车票管理1Dlg.cpp : implementation file
//

#include "StdAfx.h"
#include "车票管理1.h"
#include "车票管理1Dlg.h"
#include "DlgProxy.h"
#include <iostream>
#include "stdio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

int a[20];
int b[20];
int max[20];
int daoru=0;
int tuxing=0;

int time1(CString);

int time()
{
	int t=0;
	SYSTEMTIME S;
	GetLocalTime(&S);
	t=S.wHour*60+S.wMinute;
	return t;
}



bool judge(char *ks,char *qd,char *zd,char *sc,char *rs)
{
	bool result = 1;
	if((strcmp(rs,"")==0)||(strcmp(qd,"")==0)||(strcmp(zd,"")==0)||(strcmp(sc,"")==0))
		result = 0;
	return result;
}


void CALLBACK c(HWND hwnd,UINT message,UINT ID,DWORD TIME)
{
	SYSTEMTIME S;
	GetLocalTime(&S);
	TCHAR str[250];
	wsprintf(str,("%d年%d月%d日  %i:%i:%i"),S.wYear,S.wMonth,S.wDay,S.wHour,S.wMinute,S.wSecond);
	SetDlgItemText(hwnd,IDC_EDIT6,str);
}


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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

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
// CMy1Dlg dialog

IMPLEMENT_DYNAMIC(CMy1Dlg, CDialog);

CMy1Dlg::CMy1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;

}

CMy1Dlg::~CMy1Dlg()
{
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CMy1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1Dlg)
	DDX_Control(pDX, IDC_LIST1, m_ctllist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_CHANGE(IDC_EDIT6, OnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1Dlg message handlers

BOOL CMy1Dlg::OnInitDialog()
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

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetTimer(1,1000, c);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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



void CMy1Dlg::OnPaint() 
{
	if(tuxing==0)
	{
		tuxing++;
		DWORD k = m_ctllist.GetExtendedStyle();  //添加列表框的网格线！！！
		k = LVS_EX_FULLROWSELECT; 
		k = LVS_EX_GRIDLINES;            //显示网格线      
		m_ctllist.SetExtendedStyle(k);   //设置网格线
  		m_ctllist.InsertColumn(0,"班次",LVCFMT_LEFT,40);             
		m_ctllist.InsertColumn(1,"发车时间",LVCFMT_LEFT,60);
		m_ctllist.InsertColumn(2,"起点站",LVCFMT_LEFT,60);
		m_ctllist.InsertColumn(3,"终点站",LVCFMT_LEFT,60);
		m_ctllist.InsertColumn(4,"行车时间",LVCFMT_LEFT,90);
		m_ctllist.InsertColumn(5,"额定载量",LVCFMT_LEFT,90);
		m_ctllist.InsertColumn(6,"已订票人数",LVCFMT_LEFT,90);
		m_ctllist.InsertColumn(7,"状态",LVCFMT_LEFT,90);
		memset(a,0,sizeof(a));	
		memset(b,0,sizeof(b));
	}
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
	if(daoru==0)
	{
		if(6==MessageBox("是否导入数据？","系统提示",MB_YESNO))
		{
				freopen("车管信息.txt","r",stdin);

				int jc=1;
				char aaa[100];
				CString kss,qdd,zdd,scc,rss,ztt;
				for(int i=1;i <= 5; i++)
				{
				int count=m_ctllist.GetItemCount(); 
	
				CString str; 

				str.Format("%d",count+1);
	
				TCHAR ks[50],qd[50],zd[50],sc[50],rs[50];
	
				TCHAR ps[200];

 				gets(aaa);
				strcpy(ks,aaa);

				gets(aaa);
				strcpy(qd,aaa);

				gets(aaa);
				strcpy(zd,aaa);

				gets(aaa);
				strcpy(sc,aaa);

				gets(aaa);
				strcpy(rs,aaa);

				gets(aaa);
				strcpy(ps,aaa);
				int k=atoi(aaa);
				a[count+1]=k;

		//		MessageBox(kss,qdd,MB_OK);

				m_ctllist.InsertItem(count,str); 

				m_ctllist.SetItemText(count,2,qd);   

				m_ctllist.SetItemText(count,3,zd); 
	
				m_ctllist.SetItemText(count,1,ks); 

				m_ctllist.SetItemText(count,4,sc);

				m_ctllist.SetItemText(count,5,rs);

				m_ctllist.SetItemText(count,6,ps);
				}
		}
		fclose(stdin);
		if(daoru==0)
			daoru++;
	}
	int count=m_ctllist.GetItemCount(); 
	for(int mn = 0; mn <= count; mn++)
	{
		CString TIME;
		TIME=m_ctllist.GetItemText(mn,1);
		if(time()<time1(TIME))
			m_ctllist.SetItemText(mn,7,"未发车");
	    else
			m_ctllist.SetItemText(mn,7,"已发车");
	}
}

HCURSOR CMy1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1Dlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CMy1Dlg::OnOK() 
{
//	if (CanExit())
//		CDialog::OnOK();
	int count=m_ctllist.GetItemCount(); 
	CString str;  //str 行号
	str.Format("%d",count+1);
	TCHAR ks[50],qd[50],zd[50],sc[50],rs[50];
	CString kss,qdd,zdd,scc,rss,ztt;
	TCHAR ps[200];
	GetDlgItemText(IDC_EDIT1,kss);
	GetDlgItemText(IDC_EDIT2,qdd);
	GetDlgItemText(IDC_EDIT3,zdd);
	GetDlgItemText(IDC_EDIT4,scc);
	GetDlgItemText(IDC_EDIT5,rss);
	wsprintf(ps,("%d"),a[count+1]);
	wsprintf(ks,("%s"),kss);
	wsprintf(qd,("%s"),qdd);
	wsprintf(zd,("%s"),zdd);
	wsprintf(sc,("%s"),scc);
	wsprintf(rs,("%s"),rss);
	if(count==10)
	{
		MessageBox(("已达输入上限！！！"),("警告"),MB_OK|MB_ICONSTOP);
		return ;
	}
	if(FALSE==judge(ks,qd,zd,sc,rs))
	{
		MessageBox(("请进行正确的输入！！"),("警告"),MB_OK|MB_ICONSTOP);
		return ;
	}
	m_ctllist.InsertItem(count,str); 
	m_ctllist.SetItemText(count,2,qd);   
	m_ctllist.SetItemText(count,3,zd); 
	m_ctllist.SetItemText(count,1,ks); 
	m_ctllist.SetItemText(count,4,sc);
	m_ctllist.SetItemText(count,5,rs);
	m_ctllist.SetItemText(count,6,ps);
	SetDlgItemText(IDC_EDIT1,"");
	SetDlgItemText(IDC_EDIT2,"");
	SetDlgItemText(IDC_EDIT3,"");
	SetDlgItemText(IDC_EDIT4,"");
	SetDlgItemText(IDC_EDIT5,"");
	for(int i = 0; i <= count; i++)
	{
		CString TIME;
		TIME=m_ctllist.GetItemText(i,1);
		if(time()<time1(TIME))
			m_ctllist.SetItemText(i,7,"未发车");
	    else
			m_ctllist.SetItemText(i,7,"已发车");
	}
}

void CMy1Dlg::OnCancel() 
{
//	m_ctllist.DeleteAllItems();
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CMy1Dlg::CanExit()
{
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CMy1Dlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CMy1Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString A;
	GetDlgItemText(IDC_EDIT9,A);
	if(strcmp(A,"")==0)
	{
		MessageBox("请输入您想删除的班次信息！！","",MB_OK);
	}
	int count=m_ctllist.GetItemCount();
	int k=0;
	for(int j=0;j <= count ; j++)
	{
		CString banci;
		banci = m_ctllist.GetItemText(j,0);
		if(atoi(A)==atoi(banci))
		{
			k=j;
			break;
		}
	}
	m_ctllist.DeleteItem(k);
	SetDlgItemText(IDC_EDIT9,"");
}

void CMy1Dlg::OnChangeEdit6() 
{
}

void CMy1Dlg::OnButton2() 
{
	int count=m_ctllist.GetItemCount();
	for(int i = 0; i <= count; i++)
	{
		CString TIME;
		TIME=m_ctllist.GetItemText(i,1);
		if(time()<time1(TIME))
			m_ctllist.SetItemText(i,7,"未发车");
	    else
			m_ctllist.SetItemText(i,7,"已发车");
	}
	CString A;
	GetDlgItemText(IDC_EDIT7,A);
	SetDlgItemText(IDC_EDIT7,"");
	if(strcmp(A,"")==0)
	{
		MessageBox(("请输入正确的信息!!"),("警告"),MB_OK|MB_ICONSTOP);
		return ;
	}
	int k=0;
//	if(A[0]>='0'&&A[0]<='10')
	for(int j=0;j <= count ; j++)
	{
		CString banci;
		banci = m_ctllist.GetItemText(j,0);
//		MessageBox(banci,A,MB_OK);
		if(atoi(A)==atoi(banci))
		{
			k=j;
		//	MessageBox("itoa(k)","",MB_OK);
			break;
		}
	}
	CString ed=m_ctllist.GetItemText(k,5);
	int m=atoi(ed);
	int k1=atoi(A);
//	MessageBox(ed,(""),MB_OK);
	if((a[k1]+1)>m)
	{
		MessageBox(("该班次车票已经销售完毕！请选购其他班次的车票！！"),("系统提示"),MB_OK);
		return ;
	}
	CString zt=m_ctllist.GetItemText(k,7);
	if(strcmp(zt,"已发车")==0)
	{
		MessageBox("购票失败！该班次车已发车！","系统提示",MB_OK);
		return ;
	}
	a[k1]++;
	TCHAR pps[20];
	wsprintf(pps,"%d",a[k1]);
	m_ctllist.SetItemText(k,6,pps);
	MessageBox("恭喜你购票成功！","系统提示",MB_OK);
}

void CMy1Dlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	int count=m_ctllist.GetItemCount();
	for(int i = 0; i <= count; i++)
	{
		CString TIME;
		TIME=m_ctllist.GetItemText(i,1);
		if(time()<time1(TIME))
			m_ctllist.SetItemText(i,7,"未发车");
	    else
			m_ctllist.SetItemText(i,7,"已发车");
	}
	CString A;
	GetDlgItemText(IDC_EDIT8,A);
	SetDlgItemText(IDC_EDIT8,"");
	int k=0;
	for(int j=0;j <= count ; j++)
	{
		CString banci;
		banci = m_ctllist.GetItemText(j,0);
		if(atoi(A)==atoi(banci))
		{
			k=j;
			break;
		}
	}
	if(strcmp(A,"")==0)
	{
		MessageBox(("请输入正确的信息!!"),("警告"),MB_OK|MB_ICONSTOP);
		return ;
	}
	int k1=atoi(A);
	if((a[k1]-1)<0)
	{
		MessageBox(("请确认您输入的信息是否正确！！"),("警告"),MB_OK|MB_ICONSTOP);
		return ;
	}
	CString zt=m_ctllist.GetItemText(k,7);
	if(strcmp(zt,"已发车")==0)
	{
		MessageBox("退票失败！该班次车已发车！","系统提示",MB_OK);
		return ;
	}
	a[k1]--;
	TCHAR pps[20];
	wsprintf(pps,"%d",a[k1]);
	m_ctllist.SetItemText(k,6,pps);
	MessageBox("恭喜你退票成功！","系统提示",MB_OK);
}

void CMy1Dlg::OnButton4() 
{
	freopen("车票信息.txt","w",stdout);
	printf("班次号   出发时间   起点站    终点站   行车时间   额定载量   已订票人数\n");
	CString str0,str1,str2,str3,str4,str5,str6,str7;
	int count = m_ctllist.GetItemCount();
	for(int i = 0; i <= count; i++)
	{
		str0=m_ctllist.GetItemText(i,0);
		str1=m_ctllist.GetItemText(i,1);
		str2=m_ctllist.GetItemText(i,2);
		str3=m_ctllist.GetItemText(i,3);
		str4=m_ctllist.GetItemText(i,4);
		str5=m_ctllist.GetItemText(i,5);
		str6=m_ctllist.GetItemText(i,6);
		str7=m_ctllist.GetItemText(i,7);
	printf("%3s%11s%10s%11s%11s%11s%11s\n",str0,str1,str2,str3,str4,str5,str6,str7);
	}
	MessageBox(("导出信息成功！请您在桌面上的“车票信息”中查看所导出的信息。"),("系统提示"),MB_OK);
}

int time1(CString a)
{
	char str1[20],str2[20];
	int k1=0,k2=0;
	int t,t1,t2;
	int k=a.GetLength();
	int judge=0;
	for(int i=0;i < k; i++)
	{
		if(judge==0&&a[i]>='0'&&a[i]<='9')
			str1[k1++]=a[i];
		if(a[i]==':')
			judge++;
		if(judge==1&&a[i]>='0'&&a[i]<='9')
			str2[k2++]=a[i];
	}
	t1=atoi(str1);
	t2=atoi(str2);
	t=t1*60+t2;
	return t;
}
