// CaDialog.cpp : implementation file
//

#include "stdafx.h"
#include "lhwy.h"
#include "CaDialog.h"
#include  "lhwyDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCaDialog dialog



CCaDialog::CCaDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCaDialog::IDD, pParent)
{    
	//{{AFX_DATA_INIT(CCaDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

}


void CCaDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCaDialog)
	DDX_Control(pDX, IDC_DELECTOBJECT, m_DelectObject);
	DDX_Control(pDX, IDC_DELE, m_Dele);
	DDX_Control(pDX, IDC_BUTTON1, m_DelObject);
	DDX_Control(pDX, IDC_ADDOBJECT, m_AddObject);
	DDX_Control(pDX, IDC_COMBAN, m_comban);
	DDX_Control(pDX, IDC_COMOBJECT, m_comobject);
	DDX_Control(pDX, IDC_COM, m_Com);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCaDialog, CDialog)
	//{{AFX_MSG_MAP(CCaDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_DELE, OnDele)
	ON_BN_CLICKED(IDC_ADDOBJECT, OnAddobject)
	ON_BN_CLICKED(IDC_DELECTOBJECT, OnDelectobject)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCaDialog message handlers

BOOL CCaDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
   CDRecordset m_Set(&theApp.m_DB);
   CBRecordset m_bSet(&theApp.m_DB);
   CTRecordset m_tSet(&theApp.m_DB);

  //GetDlgItem(IDC_DELECTOBJECT)->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCaDialog::OnButton1() 
{
	// TODO: Add your control notification handler code here
//	pmyListCtrl.Create(
 //  WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT,
 //  CRect(0,0,800,300), this, 1);

   CString m_string;
   int k=m_Com.GetCurSel();
   if(k==CB_ERR )
   {
	AfxMessageBox("һ��Ҫѡ��༶");
	return;
   }
   else{
    m_Com.GetLBText(k,m_string);
    CString SqlCmd;
   SqlCmd.Format("CREATE TABLE %sSTUDENT(ѧ�� INTEGER ,���� VARCHAR(10) ,��ѧ REAL  ,���� REAL,��ѧ REAL, Ӣ�� REAL, ���� REAL,�ܳɼ� REAL,ƽ���ɼ� REAL );",m_string); 
   theApp.m_DB.ExecuteSQL(SqlCmd);
   SqlCmd.Format("CREATE TABLE %sOBJECT(��Ŀ VARCHAR(20),�ܳɼ� REAL,ƽ���ɼ� REAL,�������� REAL,�������� REAL);",m_string);
   theApp.m_DB.ExecuteSQL(SqlCmd);
   SqlCmd.Format("CREATE TABLE %sTECHER(��Ŀ VARCHAR(20),�ο���ʦ VARCHAR(20));",m_string);
   theApp.m_DB.ExecuteSQL(SqlCmd);
   SqlCmd.Format("%s�����ɹ�",m_string);
   AfxMessageBox(SqlCmd);
   SqlCmd.Format("INSERT INTO %sSTUDENT (ѧ��,����,��ѧ,����,��ѧ,Ӣ��, ����,�ܳɼ�,ƽ���ɼ�) VALUES (0,'',0,0,0,0,0,0,0)",m_string);
   theApp.m_DB.ExecuteSQL(SqlCmd);
   SqlCmd.Format("INSERT INTO %sOBJECT(��Ŀ,�ܳɼ�,ƽ���ɼ�,��������,��������) VALUES('��ѧ',0,0,0,0)",m_string);
   theApp.m_DB.ExecuteSQL(SqlCmd);
   SqlCmd.Format("INSERT INTO %sOBJECT(��Ŀ,�ܳɼ�,ƽ���ɼ�,��������,��������) VALUES('����',0,0,0,0)",m_string);
  theApp.m_DB.ExecuteSQL(SqlCmd);
 SqlCmd.Format("INSERT INTO %sOBJECT(��Ŀ,�ܳɼ�,ƽ���ɼ�,��������,��������) VALUES('��ѧ',0,0,0,0)",m_string);
   theApp.m_DB.ExecuteSQL(SqlCmd);
 SqlCmd.Format("INSERT INTO %sOBJECT(��Ŀ,�ܳɼ�,ƽ���ɼ�,��������,��������) VALUES('Ӣ��',0,0,0,0)",m_string);
  theApp.m_DB.ExecuteSQL(SqlCmd);
 SqlCmd.Format("INSERT INTO %sOBJECT(��Ŀ,�ܳɼ�,ƽ���ɼ�,��������,��������) VALUES('����',0,0,0,0)",m_string);
   theApp.m_DB.ExecuteSQL(SqlCmd);
  SqlCmd.Format("INSERT INTO %sTECHER(��Ŀ,�ο���ʦ) VALUES('','')",m_string);
   theApp.m_DB.ExecuteSQL(SqlCmd);
   
  }
   
CWnd *ppWnd=CWnd::FindWindow(NULL,"ѧ���ɼ�����");
((CLhwyDlg*) ppWnd)->m_bdlg.PostMessage(WM_CREATETABEL,k+3);

//m_comban.AddString(m_string);
 

}

void CCaDialog::OnDele() 
{
	// TODO: Add your control notification handler code here
   CString m_string;
   int k=m_Com.GetCurSel();
   if(k==CB_ERR )
   {
	AfxMessageBox("һ��Ҫѡ��༶");
	return;
   }
   else{
   m_Com.GetLBText(k,m_string);
   CString SqlCmd;
   SqlCmd.Format("DROP TABLE %sSTUDENT;",m_string); 
   theApp.m_DB.ExecuteSQL(SqlCmd);
   SqlCmd.Format("DROP TABLE %sOBJECT;",m_string);
   theApp.m_DB.ExecuteSQL(SqlCmd);
   SqlCmd.Format("DROP TABLE %sTECHER;",m_string);
   theApp.m_DB.ExecuteSQL(SqlCmd);
   SqlCmd.Format("%sɾ���ɹ�",m_string);
   AfxMessageBox(SqlCmd);
   }

 CWnd *ppWnd=CWnd::FindWindow(NULL,"ѧ���ɼ�����");
((CLhwyDlg*) ppWnd)->m_bdlg.PostMessage(WM_DELTABEL,k+3);



}

void CCaDialog::OnAddobject() 
{
	// TODO: Add your control notification handler code here
  CString m_string;
  CString m_Getstring;
   
 if(m_comobject.GetCurSel()==CB_ERR||m_comban.GetCurSel()==CB_ERR)
   {
	AfxMessageBox("һ��Ҫѡ��");
	return;
   }
   else{
   m_comobject.GetLBText(m_comobject.GetCurSel(),m_string);
   m_comban.GetLBText(m_comban.GetCurSel(),m_Getstring);
   CString SqlCmd;
   SqlCmd.Format("Alter Table %sSTUDENT Add %s REAL;",m_Getstring,m_string ); 
   theApp.m_DB.ExecuteSQL(SqlCmd);
    SqlCmd.Format("%s��%s��Ŀ����ɹ�",m_Getstring ,m_string);
	AfxMessageBox(SqlCmd);
   }

}

void CCaDialog::OnDelectobject() 
{
	// TODO: Add your control notification handler code here
  CString m_string;
  CString m_Getstring;
   
 if(m_comobject.GetCurSel()==CB_ERR||m_comban.GetCurSel()==CB_ERR)
   {
	AfxMessageBox("һ��Ҫѡ��");
	return;
   }
else{
   m_comobject.GetLBText(m_comobject.GetCurSel(),m_string);
   m_comban.GetLBText(m_comban.GetCurSel(),m_Getstring);
   CString SqlCmd;
   SqlCmd.Format("Alter Table %sSTUDENT Drop %s;",m_Getstring,m_string ); 
   theApp.m_DB.ExecuteSQL(SqlCmd);
    SqlCmd.Format("%s��%s��Ŀɾ���ɹ�",m_Getstring ,m_string);
	AfxMessageBox(SqlCmd);
   }
}
