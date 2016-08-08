// NaDilalog.cpp : implementation file
//

#include "stdafx.h"
#include "lhwy.h"
#include  "BaDialog.h"
#include "NaDilalog.h"
#include  "lhwyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNaDilalog dialog


CNaDilalog::CNaDilalog(CWnd* pParent /*=NULL*/)
	: CDialog(CNaDilalog::IDD, pParent)
{  for(int i=0;i<5;i++)
   for(int j=0;j<5;j++)
	   score[i][j]=0;
	//{{AFX_DATA_INIT(CNaDilalog)
	//}}AFX_DATA_INIT
}


void CNaDilalog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNaDilalog)
	DDX_Control(pDX, IDC_SHOW, m_ShowButton);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrlj);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrlx);
	DDX_Control(pDX, IDC_FIND, m_FindButton);
	DDX_Control(pDX, IDC_ALL, m_AllButton);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNaDilalog, CDialog)
	//{{AFX_MSG_MAP(CNaDilalog)
	ON_BN_CLICKED(IDC_ALL, OnAll)
	ON_BN_CLICKED(IDC_FIND, OnFind)
	ON_BN_CLICKED(IDC_SHOW, OnShow)
	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNaDilalog message handlers

BOOL CNaDilalog::OnInitDialog() 
{
	CDialog::OnInitDialog();

   CDRecordset m_Set(&theApp.m_DB);
   CBRecordset m_bSet(&theApp.m_DB);
	// TODO: Add extra initialization here
    unsigned i=0;
	CODBCFieldInfo Info;
	m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"一班STUDENT");
	m_ListCtrlx.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	for( i=0;i<m_Set.m_nFields;i++)
	{
	    m_Set.GetODBCFieldInfo(i,Info);
		m_ListCtrlx.InsertColumn(i,Info.m_strName);
	    m_ListCtrlx.SetColumnWidth(i,70);
	}

   m_Set.Close();

	m_bSet.Open(AFX_DB_USE_DEFAULT_TYPE,"一班OBJECT");
	m_ListCtrlj.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	for(i=0;i<m_bSet.m_nFields;i++)
	{
	  m_bSet.GetODBCFieldInfo(i,Info);
	  m_ListCtrlj.InsertColumn(i,Info.m_strName);
	  m_ListCtrlj.SetColumnWidth(i,120);
	}
    m_bSet.Close();
    
	GetDlgItem(IDC_SHOW)->EnableWindow(FALSE);
    

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
int CNaDilalog::Show()
{
	
  int k=0;
 
  do
  {  
  CString s;
  s.Format("%d",m_Set.m_column1);
  m_ListCtrlx.InsertItem(k,s,0);
  m_ListCtrlx.SetItemText(k,1,m_Set.m_column2);
  s.Format("%.1f",m_Set.m_column3);
  m_ListCtrlx.SetItemText(k,2,s);
  s.Format("%.1f",m_Set.m_column4);
  m_ListCtrlx.SetItemText(k,3,s);
  s.Format("%.1f",m_Set.m_column5);
  m_ListCtrlx.SetItemText(k,4,s);
  s.Format("%.1f",m_Set.m_column6);
  m_ListCtrlx.SetItemText(k,5,s);
  s.Format("%.1f",m_Set.m_column7);
  m_ListCtrlx.SetItemText(k,6,s);
  s.Format("%.1f",m_Set.m_column8);
  m_ListCtrlx.SetItemText(k,7,s);
  s.Format("%.2f",m_Set.m_column9);
  m_ListCtrlx.SetItemText(k,8,s);
		
  k++;
  m_Set.MoveNext();
		
  }  while(!m_Set.IsEOF());
  m_Set.Close();
  return k;
  
}


void CNaDilalog::OnAll() 
{
	// TODO: Add your control notification handler code here
	if(m_Set.IsOpen())
	m_Set.Close();
	m_ListCtrlx.DeleteAllItems();
	m_Set.m_strFilter.Empty();
	m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"一班STUDENT");
    m_nRecordCount=this->Show();
	m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM 二班STUDENT");
	m_nRecordCount+=this->Show();
	this->Sel();
	CString s;
	s.Format("%d",m_nRecordCount);
	GetDlgItem(IDC_STATICALL)->SetWindowText(s);
	GetDlgItem(IDC_SHOW)->EnableWindow(TRUE);

}



void CNaDilalog::Select()
{
 if(dlg.m_Getstring2==">=")
 m_Set.m_strFilter.Format("[%s]>=%.2f",dlg.m_Getstring1,dlg.m_find);
 if(dlg.m_Getstring2=="=")
 m_Set.m_strFilter.Format("[%s]=%.2f",dlg.m_Getstring1,dlg.m_find);
 if(dlg.m_Getstring2=="<=")
 m_Set.m_strFilter.Format("[%s]<=%.2f",dlg.m_Getstring1,dlg.m_find);
 m_Set.Requery();
 if(m_Set.IsEOF())
 { 
 m_Set.Close();
 return ;
 }
 else
 {
 this->Show();
 JS=TRUE;
 }

}
void CNaDilalog::OnFind() 
{
if(m_Set.IsOpen())
m_Set.Close();

 JS=FALSE;
if( dlg.DoModal()==IDOK)
{
m_ListCtrlx.DeleteAllItems();	
m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"一班STUDENT");
this->Select();
m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"[二班STUDENT]");
this->Select();
this->Sql();
if(JS==FALSE)
AfxMessageBox("没有符合条件的记录");
}
}



void CNaDilalog::OnShow() 
{
	// TODO: Add your control notification handler code here
	m_ListCtrlj.DeleteAllItems();
    CString s;   
    m_bSet.Open(AFX_DB_USE_DEFAULT_TYPE,"一班OBJECT");
    int i=0;
    m_bSet.MoveFirst();
    do
	 {  
    m_ListCtrlj.InsertItem(i,m_bSet.m_column1,0);
    i++;
    m_bSet.MoveNext();
	} while(!m_bSet.IsEOF());
   m_bSet.MoveFirst();
   for(i=0;i<=4;i++)
   {		  
    score[i][1]=m_bSet.m_column2;
    score[i][3]=(float)m_bSet.m_column4;
    score[i][4]=(float)m_bSet.m_column5;
    if(i!=4)
    m_bSet.MoveNext();
   }
    m_bSet.Close();

   m_bSet.Open(AFX_DB_USE_DEFAULT_TYPE,"[二班OBJECT]");
   this->Vaul();
   this->Fin();

  for(i=0;i<5;i++)
  { 
	s.Format("%.1f",score[i][1]);
	m_ListCtrlj.SetItemText(i,1,s);
	s.Format("%.2f",score[i][2]);
    m_ListCtrlj.SetItemText(i,2,s);
    s.Format("%d",(int)score[i][3]);
    m_ListCtrlj.SetItemText(i,3,s);
    s.Format("%d",(int)score[i][4]);
    m_ListCtrlj.SetItemText(i,4,s);
	}
}

void  CNaDilalog::Sel()
{   
	CWnd *ppWnd=CWnd::FindWindow(NULL,"学生成绩管理");
  
    if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Three=="三班")
	{
	m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM 三班STUDENT");
    this->Att();
	}
   if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Four=="四班")
	{
	m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM 四班STUDENT");
	 this->Att();
	}
 if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Five=="五班")
	{
	m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM 五班STUDENT");
  this->Att();
	}
if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Six=="六班")
	{
	m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM 六班STUDENT");
	  this->Att();
	}
if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Seven=="七班")
	{
	m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM 七班STUDENT");
  this->Att();
	}
if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Eight=="八班")
	{
	m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM 八班STUDENT");
	 this->Att();

	}
}

void  CNaDilalog::Fin()
{
	CWnd *ppWnd=CWnd::FindWindow(NULL,"学生成绩管理");

    if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Three=="三班")
	{ 
    m_bSet.Open(AFX_DB_USE_DEFAULT_TYPE,"[三班OBJECT]");
    this->Vaul();
	}
 if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Four=="四班")
	{ 
   m_bSet.Open(AFX_DB_USE_DEFAULT_TYPE,"[四班OBJECT]");
    this->Vaul();
	}
 if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Five=="五班")
	{ 
	 m_bSet.Open(AFX_DB_USE_DEFAULT_TYPE,"[五班OBJECT]");
     this->Vaul();
	}
 if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Six=="六班")
	{ 
   m_bSet.Open(AFX_DB_USE_DEFAULT_TYPE,"[六班OBJECT]");
   this->Vaul();
	}
 if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Seven=="七班")
	{ 
   m_bSet.Open(AFX_DB_USE_DEFAULT_TYPE,"[七班OBJECT]");
   this->Vaul();
	}
 if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Eight=="八班")
	{ 
   m_bSet.Open(AFX_DB_USE_DEFAULT_TYPE,"[八班OBJECT]");
    this->Vaul();
	}
}

void CNaDilalog::Sql()
{
	CWnd *ppWnd=CWnd::FindWindow(NULL,"学生成绩管理");
   if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Three=="三班")
	{ 
    m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"[三班STUDENT]");
	this->Beg();
   }
 if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Four=="四班")
	{ 
    m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"[四班STUDENT]");
	this->Beg();
   }
 if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Five=="五班")
	{ 
    m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"[五班STUDENT]");
	this->Beg();
   }
 if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Six=="六班")
	{ 
    m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"[六班STUDENT]");
	this->Beg();
   }
 if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Seven=="七班")
	{ 
    m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"[七班STUDENT]");
	this->Beg();
   }
 if(((CLhwyDlg*) ppWnd)->m_bdlg.m_Eight=="八班")
	{ 
    m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"[八班STUDENT]");
	this->Beg();
   }
}


void  CNaDilalog::Vaul()
{
   for(int i=0;i<5;i++)
   {
	score[i][1]+=m_bSet.m_column2;
	score[i][2]=score[i][1]/m_nRecordCount;
	score[i][3]+=(float)m_bSet.m_column4;
	score[i][4]+=(float)m_bSet.m_column5;
	if(!m_bSet.IsEOF())
   m_bSet.MoveNext();
   }
   m_bSet.Close();
}

void CNaDilalog::Beg()
{
    if(m_Set.m_column1==0)
	m_Set.Close();
	else
    this->Select();
}

void CNaDilalog::Att()
{
	m_Set.MoveFirst();
	if(m_Set.m_column1==0)
	m_Set.Close();
	else
	m_nRecordCount+=this->Show();
}