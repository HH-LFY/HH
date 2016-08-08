// BaDialog.cpp : implementation file
//

#include "stdafx.h"
#include "lhwy.h"
#include "BaDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaDialog dialog
IMPLEMENT_SERIAL(CBaDialog, CDialog, VERSIONABLE_SCHEMA | 2 )

CBaDialog::CBaDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CBaDialog::IDD, pParent)
{ 
  
	//{{AFX_DATA_INIT(CBaDialog)
	//}}AFX_DATA_INIT
}


void CBaDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBaDialog)
	DDX_Control(pDX, IDC_EXPORT, m_ExportButtom);
	DDX_Control(pDX, IDC_STATR, m_StaButton);
	DDX_Control(pDX, IDC_DELECT, m_DelButton);
	DDX_Control(pDX, IDC_FIND, m_FindButton);
	DDX_Control(pDX, IDC_EDIT, m_EditButton);
	DDX_Control(pDX, IDC_ALL, m_AllButton);
	DDX_Control(pDX, IDC_ADD, m_AddButton);
	DDX_Control(pDX, IDC_COMBO1, m_cob);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrlb);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrll);
	DDX_Control(pDX, IDC_LIST3, m_ListCtrlx);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBaDialog, CDialog)
	//{{AFX_MSG_MAP(CBaDialog)
	ON_BN_CLICKED(IDC_STATR, OnStatr)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELECT, OnDelect)
	ON_BN_CLICKED(IDC_FIND, OnFind)
	ON_BN_CLICKED(IDC_ALL, OnAll)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST3, OnColumnclickList3)
    ON_MESSAGE(WM_CREATETABEL,OnCreateTabel)
	ON_MESSAGE(WM_DELTABEL,OnDelTabel)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_EXPORT, OnExport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaDialog message handlers

BOOL CBaDialog::OnInitDialog() 
{
   CDialog::OnInitDialog();
   CDRecordset m_Set(&theApp.m_DB);
   CBRecordset m_bSet(&theApp.m_DB);
   CTRecordset m_tSet(&theApp.m_DB);

    unsigned i=0;
	CODBCFieldInfo Info;
	m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,"一班STUDENT");
	m_ListCtrlx.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	for( i=0;i<m_Set.m_nFields;i++)
	{  
	    m_Set.GetODBCFieldInfo(i,Info);
		m_ListCtrlx.InsertColumn(i,Info.m_strName,LVCFMT_LEFT,70);
	}
    m_Set.Close();

	m_bSet.Open(AFX_DB_USE_DEFAULT_TYPE,"一班OBJECT");
	m_ListCtrlb.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	for( i=0;i<m_bSet.m_nFields;i++)
	{   
	    m_bSet.GetODBCFieldInfo(i,Info);
		m_ListCtrlb.InsertColumn(i,Info.m_strName,LVCFMT_LEFT,80);
	}
	
	
    m_bSet.Close();

	m_ListCtrll.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    m_ListCtrll.InsertColumn(0,_T("科目"),LVCFMT_IMAGE|LVCFMT_LEFT);
    m_ListCtrll.InsertColumn(1,"任课老师");
    for(i=0;i<2;i++)
	m_ListCtrll.SetColumnWidth(i,80);

   
   m_cob.SetCurSel(0);
   this->Enable(FALSE);
   m_Timer=SetTimer(1,2,NULL);
   m_bIsAsc=TRUE;
   m_bS=TRUE;

 
   
	GetModuleFileName(NULL,sPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);
	sPath.ReleaseBuffer ();
	int nPos;
	nPos=sPath.ReverseFind ('\\');
	sPath=sPath.Left (nPos);
	nPos=sPath.ReverseFind('\\');
    sPath=sPath.Left (nPos);
    lpszFile = sPath + "\\tect.txt";
    
    CFile aFile;
    CFileFind  fFind;
	BOOL bSuccess;
	bSuccess=fFind.FindFile( lpszFile);
	
	if(!bSuccess)
	 aFile.Open( lpszFile,CFile::modeCreate);
	else
	{
	aFile.Open( lpszFile,CFile::modeReadWrite);
    CArchive arr(&aFile,CArchive::load);
    Serialize( arr);
    if(m_Three=="三班")
    m_cob.AddString(m_Three);
    if(m_Four=="四班")
    m_cob.AddString(m_Four);
    if(m_Five=="五班")
    m_cob.AddString(m_Five);
    if(m_Six=="六班")
    m_cob.AddString(m_Six);
    if(m_Seven=="七班")
    m_cob.AddString(m_Seven);
     if(m_Eight=="八班")
    m_cob.AddString(m_Eight);
	}
   aFile.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBaDialog::OnStatr() 
{
	// TODO: Add your control notification handler code here
	m_ListCtrlx.DeleteAllItems();
	m_ListCtrlb.DeleteAllItems();
	m_ListCtrll.DeleteAllItems();
	if(m_Set.IsOpen())
	m_Set.Close();
	if(m_bSet.IsOpen())
	m_bSet.Close();

    m_cob.GetLBText(m_cob.GetCurSel(),m_Getstring);
   	this->Select();
    CString str;
	str.Format("%sTECHER",m_Getstring);
    m_tSet.Open(AFX_DB_USE_DEFAULT_TYPE,str);
 
    m_nRecordCount=this->Show();
    this->display();
    this->exhibit();
    m_bS = GetDlgItem(IDC_STATR)->EnableWindow(FALSE);
	this->Enable(TRUE);	
}

int  CBaDialog::Show()
{
  int i=0;
  
  m_Set.MoveFirst();
  if(m_Set.m_column1==0)
  {
	 m_Set.Close();
	 return i;
	 }
  do
  {  

  CString s;
  s.Format("%d",m_Set.m_column1);
  m_ListCtrlx.InsertItem(i,s,0);
  m_ListCtrlx.SetItemText(i,1,m_Set.m_column2);
  s.Format("%.1f",m_Set.m_column3);
  m_ListCtrlx.SetItemText(i,2,s);
  s.Format("%.1f",m_Set.m_column4);
  m_ListCtrlx.SetItemText(i,3,s);
  s.Format("%.1f",m_Set.m_column5);
  m_ListCtrlx.SetItemText(i,4,s);
  s.Format("%.1f",m_Set.m_column6);
  m_ListCtrlx.SetItemText(i,5,s);
  s.Format("%.1f",m_Set.m_column7);
  m_ListCtrlx.SetItemText(i,6,s);
  s.Format("%.1f",m_Set.m_column8);
  m_ListCtrlx.SetItemText(i,7,s);
  s.Format("%.2f",m_Set.m_column9);
  m_ListCtrlx.SetItemText(i,8,s);
		
  i++;
  m_Set.MoveNext();
		
  }  while(!m_Set.IsEOF());
  m_Set.Close();
  return i;
  
}


 void CBaDialog::display()
 {
   int i=0;
   m_bSet.MoveFirst();
   do
	 {  
    	CString s;
	    m_ListCtrlb.InsertItem(i,m_bSet.m_column1,0);
		s.Format("%.1f",m_bSet.m_column2);
		m_ListCtrlb.SetItemText(i,1,s);
	    s.Format("%.2f",m_bSet.m_column3);
        m_ListCtrlb.SetItemText(i,2,s);
        s.Format("%d",m_bSet.m_column4);
        m_ListCtrlb.SetItemText(i,3,s);
        s.Format("%d",m_bSet.m_column5);
        m_ListCtrlb.SetItemText(i,4,s);
      
		i++;
        m_bSet.MoveNext();
		
		} while(!m_bSet.IsEOF());
        m_bSet.Close();
 }


 void CBaDialog::exhibit()
 {
  int i=0;
  do
  {  
   m_ListCtrll.InsertItem(i,m_tSet.m_column1,0);
   m_ListCtrll.SetItemText(i,1,m_tSet.m_column2);
   i++;
   m_tSet.MoveNext();
  }while(!m_tSet.IsEOF());
   m_tSet.Close();
 }

 void CBaDialog::Enable( BOOL p)
 {
	 
	 GetDlgItem(IDC_ADD)->EnableWindow(p);
	 GetDlgItem(IDC_DELECT)->EnableWindow(p);
	 GetDlgItem(IDC_EDIT)->EnableWindow(p);
	 GetDlgItem(IDC_FIND)->EnableWindow(p);
	 GetDlgItem(IDC_ALL)->EnableWindow(p);
	 GetDlgItem(IDC_EXPORT)->EnableWindow(p);
 }

 CString CBaDialog::Select()
 {	
     CString str;
     str.Format("%sSTUDENT",m_Getstring);
	 m_Set.Open(AFX_DB_USE_DEFAULT_TYPE,str);
	 str.Format("%sOBJECT",m_Getstring);
     m_bSet.Open(AFX_DB_USE_DEFAULT_TYPE,str);
     
	 return m_Getstring;
 }  
 
 void CBaDialog::Equal()
 {  
	 for(int i=0;i<5;i++)
	 {  
    float p=0;
	if(i==0)
	  p=m_Set.m_column3;
   if(i==1)
	   p=m_Set.m_column4;
   if(i==2)
		p=m_Set.m_column5;
	if(i==3)
	    p=m_Set.m_column6;
    if(i==4)
		p=m_Set.m_column7;


      m_bSet.Edit();
	  if(Selec==FALSE)
	  {
	  m_bSet.m_column2-=p;
	  m_bSet.m_column3=(float)(m_bSet.m_column2/m_nRecordCount);
	  if(p>=60)
	  m_bSet.m_column4-=1;
	  if(p>=80)
	  m_bSet.m_column5-=1;
	  }
	  else
	  {
	  m_bSet.m_column2+=p;
	  m_bSet.m_column3=(float)(m_bSet.m_column2/m_nRecordCount);
	  if(p>=60)
	  m_bSet.m_column4+=1;
	  if(p>=80)
	  m_bSet.m_column5+=1;
	  }
	  
	  m_bSet.Update();
	  if(!m_bSet.IsEOF())
      m_bSet.MoveNext();
	  else
	  break;
	  }
 }

 void CBaDialog::Xuan()
 {
     m_ListCtrlb.DeleteAllItems();
	 this->display();
     m_ListCtrlx.DeleteAllItems();
     this->Show();
 }

void CBaDialog::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CString m_string;
    m_cob.GetLBText(m_cob.GetCurSel(),m_string);
	if(m_Getstring!=m_string)
	{
	GetDlgItem(IDC_STATR)->EnableWindow(TRUE);
	this->Enable(FALSE);
	}
	CDialog::OnTimer(nIDEvent);
}

void CBaDialog::OnAdd() 
{
	// TODO: Add your control notification handler code here
	Selec=TRUE;
	CAddialog dlg;
    if(dlg.DoModal()==IDOK)
	{
	 CString str=this->Select();
     if(str=="一班")
	  {
	    if(dlg.m_nxue>=200||dlg.m_nxue<100)
		{
		AfxMessageBox("一班学号在100—200之间");
	    m_Set.Close();
		m_bSet.Close();
        return;
		}
	   }
	  else if(str=="二班")
	  {
		if(dlg.m_nxue<200||dlg.m_nxue>=300)
		{
		AfxMessageBox("二班学号在200—300之间");
        m_Set.Close();
		m_bSet.Close();
		return;
		}
	   }
	  else if(str=="三班")
	  {
		 if(dlg.m_nxue<300||dlg.m_nxue>=400)
		 {
		 AfxMessageBox("三班学号在300—400之间");
         m_Set.Close();
		 m_bSet.Close();;
		   return;
		 }
	   }
	   else if(str=="四班")
	   {
		   if(dlg.m_nxue<400||dlg.m_nxue>=500)
		   {
			AfxMessageBox("三班学号在400—500之间");
            m_Set.Close();
		   m_bSet.Close();
		   return;
		   }
	   }
     else if(str=="五班")
	   {if(dlg.m_nxue<500||dlg.m_nxue>=600)
		   {AfxMessageBox("三班学号在500—600之间");
         m_Set.Close();
		   m_bSet.Close();
		   return;}
	 }
else if(str=="六班")
	   {if(dlg.m_nxue<600||dlg.m_nxue>=700)
		   {AfxMessageBox("六班学号在400—500之间");
        m_Set.Close();
		   m_bSet.Close();
		   return;}
}
else if(str=="七班")
	   {if(dlg.m_nxue<700||dlg.m_nxue>=800)
		   {AfxMessageBox("七班学号在700—800之间");
           m_Set.Close();
		   m_bSet.Close();;
		   return;}
}
else if(str=="八班")
	   {if(dlg.m_nxue<800||dlg.m_nxue>=900)
		   {AfxMessageBox("八班学号在800—900之间");
           m_Set.Close();
		   m_bSet.Close();
		   return;}
}
	  m_Set.AddNew();
	  m_nRecordCount+=1;
	  m_Set.m_column1=dlg.m_nxue;
	  m_Set.m_column2=dlg.m_strName;
      m_Set.m_column3=dlg.m_fmaths;
      m_Set.m_column4=dlg.m_fphysical;
      m_Set.m_column5=dlg.m_fchemistry;
	  m_Set.m_column6=dlg.m_fenglish;
	  m_Set.m_column7=dlg.m_fpolitic;
	  m_Set.m_column8=dlg.m_fmaths+dlg.m_fphysical+dlg.m_fchemistry+dlg.m_fenglish+dlg.m_fpolitic;
	  m_Set.m_column9=(float)(m_Set.m_column8/5);
      this->Equal();
	  m_Set.Update();//Update()一定放在Equal（）后
      m_Set.MoveFirst();
	  if(m_Set.m_column1==0)
	  {
		  m_Set.Delete();
		  m_Set.Requery();
	  } 
      m_Set.Requery();
	  this->Xuan();

	 }
}
	


void CBaDialog::OnDelect() 
{
	// TODO: Add your control notification handler code here
    CDelectDialog dlg;
	Selec=FALSE;
	if(dlg.DoModal()==IDOK)
	{
	if(dlg.m_nPass!=1234)
	AfxMessageBox("密码不正确!你没有权限删除记录");
    else
	{
	this->Select();
    m_Set.MoveFirst();
	BOOL sel=FALSE;
	do
	{
	 if(m_Set.m_column1!=dlg.m_nxue)
	 m_Set.MoveNext();	 
	 else
	 {
     m_nRecordCount-=1;
	 sel=TRUE;
     m_bSet.MoveFirst();
     this->Equal();
      m_Set.Delete();
	  m_Set.Requery();
	  break;
	 }
	}while(!m_Set.IsEOF());
 	if(sel==FALSE)
	{
	AfxMessageBox("没有此记录");
	return;
	}
	else
	this->Xuan();
	}
	}
	
}

void CBaDialog::OnFind() 
{
	// TODO: Add your control notification handler code here
CFinDialog dlg;
if( dlg.DoModal()==IDOK)
{ 
this->Select();
m_bSet.Close();

if(dlg.m_Getstring2==">=")
m_Set.m_strFilter.Format("[%s]>=%.2f",dlg.m_Getstring1,dlg.m_find);
if(dlg.m_Getstring2=="=")
m_Set.m_strFilter.Format("[%s]=%.2f",dlg.m_Getstring1,dlg.m_find);
if(dlg.m_Getstring2=="<=")
m_Set.m_strFilter.Format("[%s]<=%.2f",dlg.m_Getstring1,dlg.m_find);
m_ListCtrlx.DeleteAllItems();
m_Set.Requery();
if(m_Set.IsEOF())
{ 
 AfxMessageBox("没有符合条件的记录");
 m_Set.Close();
 return ;
 }
else
this->Show();

}
}

void CBaDialog::OnAll() 
{
	// TODO: Add your control notification handler code here
    
	this->Select();
	m_bSet.Close();
	
	m_Set.m_strFilter.Empty();
	m_Set.Requery();
	m_ListCtrlx.DeleteAllItems();
	this->Show();
}

void CBaDialog::OnEdit() 
{
	// TODO: Add your control notification handler code here
    
	CEditDialog dlg;
	if(dlg.DoModal()==IDOK)
	{
    if(strcmp(dlg.m_pass,"1234")!=0)
	AfxMessageBox("你没有权限更改记录！请重输入密码：");
    else
	{
	 this->Select();
	 m_Set.m_strFilter.Format("[学号]=%d",dlg.m_xue);
	 m_Set.Requery();
	 if(m_Set.IsEOF())
	 AfxMessageBox("没有此记录");
	  else
	  {   
	  for(int i=0;i<5;i++)
	  {
	  float p=0,q=0;
	 if(i==0)
	 {
	  p=dlg.m_fmaths;
	  q=m_Set.m_column3;
	 }
     if(i==1)
	 {
	 p=dlg.m_fphysical;
	 q=m_Set.m_column4;
	 }
   if(i==2)
   {
   p=dlg.m_fchemistry;
   q=m_Set.m_column5;
   }
	if(i==3)
	{ 
	p=dlg.m_fenglish;
	 q=m_Set.m_column6;
	}
    if(i==4)
	{	
	p=dlg.m_fpolitic;
	q=m_Set.m_column7;
	}

	m_bSet.Edit();
    m_bSet.m_column2=m_bSet.m_column2+p-q;
	m_bSet.m_column3=m_bSet.m_column2/m_nRecordCount;
	if(p>=60 && q<60)
	m_bSet.m_column4+=1;
	if(p<60 && q>=60)
	m_bSet.m_column4-=1;

	if(p>=80 && q<80)
	m_bSet.m_column5+=1;
	if(p<80 && q>=80)
	m_bSet.m_column5-=1;

    m_bSet.Update();
   if(!m_bSet.IsEOF())
   m_bSet.MoveNext();
   else
  break;
	  }

      m_Set.Edit();
     m_Set.m_column2=dlg.m_strName;
      m_Set.m_column3=dlg.m_fmaths;
      m_Set.m_column4=dlg.m_fphysical;
      m_Set.m_column5=dlg.m_fchemistry;
	  m_Set.m_column6=dlg.m_fenglish;
	  m_Set.m_column7=dlg.m_fpolitic;
	  m_Set.m_column8=dlg.m_fmaths+dlg.m_fphysical+dlg.m_fchemistry+dlg.m_fenglish+dlg.m_fpolitic;
	  m_Set.m_column9=(float)(m_Set.m_column8/5);
      m_Set.Update();
	  
	  }
      m_Set.m_strFilter.Empty();
	  m_bSet.Close();
	  m_Set.Close();
	  m_ListCtrlx.DeleteAllItems();
	  m_ListCtrlb.DeleteAllItems();
	  this->Select();
	  this->Show();
	  this->display();
	 }
	}
}


void CBaDialog::Sort(BOOL isAsc,int secol)
{   
	if(m_Set.IsOpen())
      m_Set.Close();
	this->Select();
	m_bSet.Close();
	CODBCFieldInfo fieldInfo;
	m_Set.GetODBCFieldInfo(secol,fieldInfo);
	if(isAsc)
	{
		m_Set.m_strSort=fieldInfo.m_strName+" ASC";
       m_bIsAsc=TRUE;
	}
	else
	{
		m_Set.m_strSort=fieldInfo.m_strName+" DESC";
		m_bIsAsc=FALSE;
	}
	m_Set.Requery();	

}



void CBaDialog::OnColumnclickList3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	if(FALSE== m_bS)
	{
	  int k= pNMListView->iSubItem;
	  Sort(!m_bIsAsc,k);
	  m_ListCtrlx.DeleteAllItems();
	  this->Show();
	}
	*pResult = 0;
}
LRESULT CBaDialog::OnCreateTabel(WPARAM wParam, LPARAM lParam)
{   
	switch (wParam)
	{
	case 3:
		  m_Three=_T("三班");
		  m_cob.AddString("三班");
	      break;
	case 4:
		  m_Four="四班";
		  m_cob.AddString("四班");
		 break;
	case 5:
		m_Five="五班";
		m_cob.AddString("五班");
		break;
	case 6:
		m_Six="六班";
		m_cob.AddString("六班");
		break;
	case 7:
		m_Seven="七班";
		m_cob.AddString("七班");
		break;
	case 8:
		m_Eight="八班";
		m_cob.AddString("八班");
		break;

	default:
		break;
	}
   Save();
   return 0;
}





void CBaDialog::Save() 
{
	// TODO: Add your control notification handler code here
    
  CFile bFile;
  try
  {bFile.Open( lpszFile,CFile::modeCreate | CFile::modeReadWrite);
  }
  catch(CFileException* e)
  { 
	  CString str;
	  str.Format("%s",e->m_cause);
	  AfxMessageBox(str);
  }

  CArchive art(&bFile,CArchive::store);
  art.m_pDocument=(CDocument *)&bFile;//重要
  if (art.m_pDocument != NULL)
  Serialize(art);
 
}

void CBaDialog::Serialize(CArchive& ar) 
{   
	if (ar.IsStoring())
	{	// storing code
    ar<<m_Three<<m_Four<<m_Five<<m_Six<<m_Seven<<m_Eight;
	}
	else
	{	// loading code
   ar>>m_Three>>m_Four>>m_Five>>m_Six>>m_Seven>>m_Eight;
	}
}
LRESULT CBaDialog::OnDelTabel(WPARAM wParam, LPARAM lParam)
{  int nIndex;
	switch (wParam)
	{
	case 3:
	m_Three=_T("");
    nIndex = 0;
   while ((nIndex=m_cob.FindString(nIndex, "三班")) != CB_ERR)
	{
     m_cob.DeleteString( nIndex );
	}
     break;
	case 4:
		  m_Four="";
		  nIndex = 0;
   while ((nIndex=m_cob.FindString(nIndex, "四班")) != CB_ERR)
	{
     m_cob.DeleteString( nIndex );
	}
		break;
	case 5:
		m_Five="";
    nIndex = 0;
   while ((nIndex=m_cob.FindString(nIndex, "五班"))!= CB_ERR)
	{
     m_cob.DeleteString( nIndex );
	}
	break;
	case 6:
	
		m_Six="";
    nIndex = 0;
   while ((nIndex=m_cob.FindString(nIndex,"六班" )) != CB_ERR)
	{
     m_cob.DeleteString( nIndex );
	}
		break;
	case 7:
	
		m_Seven="";
		nIndex = 0;
   while ((nIndex=m_cob.FindString(nIndex,"七班" )) != CB_ERR)
	{
     m_cob.DeleteString( nIndex );
	}
		break;
	case 8:
		m_Eight="";
	nIndex = 0;
   while ((nIndex=m_cob.FindString(nIndex,"八班" )) != CB_ERR)
	{
	   

     m_cob.DeleteString( nIndex );
	}
		break;

	default:
		break;
	}
   Save();
   return 0;
}


void CBaDialog::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	
}

void CBaDialog::OnExport() 
{
	// TODO: Add your control notification handler code here
    CFile aFile;
    CFileFind  fFind;
	BOOL bSuccess;
	CString str;
	str.Format("\\%s.txt",m_Getstring);
	CString lFile= sPath+str;
	
	
	bSuccess=fFind.FindFile(lFile);
	
	if(!bSuccess)
	 aFile.Open(lFile,CFile::modeCreate);
	else
	{
	aFile.Open(lFile,CFile::modeReadWrite);
    CArchive arr(&aFile,CArchive::store);
	this->Select();
	m_bSet.Close();
   int i=0;
  if(m_Set.m_column1==0)
  {  
	m_Set.Close();
	return ;
  }
  m_Set.MoveFirst();
  do
  { 
   CString str1,str2,str3,str4,str5,str6,str7,str8,str9;
   str1.Format("%d",m_Set.m_column1);
   str2=m_Set.m_column2;
   str3.Format("%.1f",m_Set.m_column3);
   str4.Format("%.1f",m_Set.m_column4);
   str5.Format("%.1f",m_Set.m_column5);
   str6.Format("%.1f",m_Set.m_column6);
   str7.Format("%.1f",m_Set.m_column7);
   str8.Format("%.1f",m_Set.m_column8);
   str9.Format("%.2f",m_Set.m_column9);
  
  arr<<str1<<m_Set.m_column2<<str3<<str4<<str5<<str6<<str7<<str8<<str9;
		
  i++;
  m_Set.MoveNext();
		
  }  while(!m_Set.IsEOF());
  m_Set.Close();
 
	} 

	aFile.Close();
}
