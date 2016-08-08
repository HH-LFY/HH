#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
int count=0;
class CData
{
  public:
 CData(){};
 virtual int Compare(CData &,int)=0;
 virtual void Show()=0;
 virtual ~CData(){};
};
class CNode
{
  private:
 CData *pData;
 CNode *pNext;
  public:
 CNode(){pData=0;pNext=0;};
 CNode(CNode &node)
 {
  pData=node.pData;
  pNext=node.pNext;
 }
 void InputData(CData *pdata){pData=pdata;}
 void ShowNode(){pData->Show();}
 CData *GetData(){return pData;}
 friend class CList;
};
class CList
{
 
 CNode *pHead;
  public:
 CList(){pHead=0;};
 ~CList(){DeleteList();}
 void AddNode(CNode *pnode);
 CNode *DeleteNode(CNode *);
 CNode *LookUp(CData &);
 bool LookUpF(CData &);
 void ShowList();
        void DeleteList();
 CNode *GetListHead(){return pHead;}
 CNode *GetListNextNode(CNode *pnode);
};
CNode *CList::GetListNextNode(CNode *pnode)
{
    CNode *p1=pnode;
    return p1->pNext;
};
void CList::AddNode(CNode *pnode)
{
 if (pHead==0)
 {
  pHead=pnode;
  pnode->pNext=0;
  return;
 }
 else
 {
  pnode->pNext=pHead;
  pHead=pnode;
 }
};
CNode *CList::DeleteNode(CNode *pnode)
{
 CNode *p1,*p2;
 p1=pHead;
 while(p1!=pnode&&p1->pNext!=0)
 {
  p2=p1;
  p1=p1->pNext;
 }
 if (p1==pHead)
 {
  pHead=pHead->pNext;
  return pnode;
 }
 p2->pNext=p1->pNext;
 return pnode;
}
CNode *CList::LookUp(CData &data)
{
 CNode *p1=pHead;
 while(p1)
 {
  if (p1->pData->Compare(data,1)==0)
   return p1;
  p1=p1->pNext;
 }
 return 0;
}
bool CList::LookUpF(CData &data)
{
 bool f1=false;
 CNode *p1=pHead;
 while(p1)
 {
     if (p1->pData->Compare(data,0)==0)
  {
   p1->ShowNode();
   f1=true;
  }
     p1=p1->pNext;
  
 }
 return f1;
}
void CList::ShowList()
{
 CNode *p1=pHead;
 while(p1)
 {
  p1->pData->Show();
  p1=p1->pNext;
 }
}
void CList::DeleteList()
{
 CNode *p1,*p2;
 p1=pHead;
 while(p1)
 {
  delete p1->pData;
  p2=p1;
  p1=p1->pNext;
  delete p2;
 }
}
class CTelRecord:public CData
{
  private :
 char szName[20];
 char szNumber[20];
 char szF;
  public:
 CTelRecord(){strcpy(szName,"\0");strcpy(szNumber,"\0");}
 CTelRecord(char *name,char *number)
 {
  strcpy(szName,name);
  strcpy(szNumber,number);
  szF=name[0];
 }
 void SetRecord(char *name, char *number)
 {
  strcpy(szName,name);
  strcpy(szNumber,number);
  szF=name[0];
 }
 int Compare(CData &,int);
 void Show();
};
int CTelRecord::Compare(CData&data,int choice)
{
 CTelRecord &temp=(CTelRecord &)data;
        if(choice==1)
   return strcmp(szName,temp.szName);
   else 
    return (szF==temp.szF ? 0:1);
}
void CTelRecord::Show()
{
 cout<<setw(15)<<szName<<setw(15)<<szNumber<<endl;
}
void AddRecord(CList &TelList)
{
 CNode *pNode;
 CTelRecord *pTel;
 char szName[20],szNumber[20];
 cout<<"请输入姓名（输入0退出，并进入系统菜单)"<<endl;
 cin.getline(szName,20);
 while(strcmp(szName,"0"))
 {
  cout<<"请输入电话号码:  "<<endl;
     cin.getline(szNumber,20);
  pTel=new CTelRecord;
     pTel->SetRecord(szName,szNumber);
     pNode=new CNode;
     pNode->InputData(pTel);
            TelList.AddNode(pNode);
            count++;
     cout<<"请输入姓名（输入0退出，并进入系统菜单） "<<endl;
     cin.getline(szName,20);
 }
 cout<<endl<<endl;
}

void DisplayRecord(CList&TelList)
{
 cout<<"目前共有 "<<count<<" 条记录，具体记录如下："<<endl;
 cout<<setw(15)<<"【姓名】"<<setw(15)<<"【电话号码】"<<endl;
 TelList.ShowList();
 cout<<endl<<endl;
        system("pause");
}

void LookUpRecord(CList&TelList)
{
 CNode *pLook;
 char szName[20];
 cout<<"请输入您需要查找的姓名（输入0退出，并进入系统菜单）"<<endl;
 cin.getline(szName,20);
 while (strcmp(szName,"0"))
 {
  CTelRecord tele(szName,"0");
  pLook=TelList.LookUp(tele);
  if (pLook)
  {
   cout<<"在电话簿中找到"<<szName<<",内容是："<<endl;
            cout<<setw(15)<<"【姓名】"<<setw(15)<<"【电话号码】"<<endl;
   pLook->ShowNode();
  }
  else 
   cout<<"在电话簿中找不到"<<szName<<","<<endl;
  cout<<"请输入您需要查找的姓名（输入0退出，并进入系统菜单）"<<endl;
  cin.getline(szName,20);
 }
 cout<<endl<<endl;
}

void DeleteRecord(CList&TelList)
{
 CNode *pLook;
 char szName[20];
        cout<<"请输入您需要删除的姓名（输入0退出，并进入系统菜单）"<<endl;
 cin.getline(szName,20);
 while(strcmp(szName,"0"))
 {
  CTelRecord tel(szName,"0");
  pLook=TelList.LookUp(tel);
  if (pLook)
  {
   cout<<"在电话簿中找到"<<szName<<",内容是："<<endl;
               pLook->ShowNode();
   cout<<"请确定是否删除此记录（Y/N)【确定删除请输入Y或y,取消删除请输入N或n】:"<<endl;
   char ok;
   cin>>ok;
                        cin.ignore();
   if (ok=='Y'||ok=='y')
   {
       TelList.DeleteNode(pLook);
       cout<<szName<<"的资料删除成功！"<<endl;
       delete pLook;
       count--;
   }
   else if(ok=='N'||ok=='n')
    cout<<szName<<"的资料删除失败"<<endl;
  }
  else
    cout<<"在电话簿中找不到"<<szName<<","<<endl;
  cout<<"请输入您需要删除的姓名（输入0退出，并进入系统菜单）"<<endl;
        cin.getline(szName,20);
 }
 cout<<endl<<endl;
}
void ModifyRecord(CList &TelList)
{
 CNode *pLook;
 CTelRecord *pTel;
 char szName[20],szNumber[20];
 cout<<"请输入您需要修改的姓名（输入0退出，并进入系统菜单）"<<endl;
 cin.getline(szName,20);
 while(strcmp(szName,"0"))
 {
        CTelRecord tel(szName,"0");
  pLook=TelList.LookUp(tel);
  if (pLook)
  {
   cout<<"在电话簿中找到"<<szName<<",内容是："<<endl;
               pLook->ShowNode();
                        cout<<"-----下面开始修改-----"<<endl<<"请输入修改后的姓名:  "<<endl;
   cin.getline(szName,20);
   cout<<"请输入修改后的电话号码:"<<endl;
            cin.getline(szNumber,20);
      cout<<"请确定是否修改此记录（Y/N)【确定修改请输入Y或y,取消修改请输入N或n】:"<<endl;
   char ok;
   cin>>ok;
                        cin.ignore();
   if (ok=='Y'||ok=='y')
   {
     pTel=new CTelRecord;
     *pTel=tel;
     pTel->SetRecord(szName,szNumber);
     pLook->InputData(pTel);
                          cout<<szName<<"的资料修改成功！"<<endl;
   }
                        else if(ok=='N'||ok=='n')
                cout<<szName<<"的资料修改失败！"<<endl;
  }
               else
    cout<<"  在电话簿中找不到"<<szName<<","<<endl;
        cout<<"  请输入您需要修改的姓名（输入0退出，并进入系统菜单）";
        cin.getline(szName,20);
 }
}

void StoreFile(CList&TelList)
{
 ofstream outfile("TELEPHONE.DAT",ios::binary);
 if (!outfile)
 {
  cout<<"  数据库文件打开错误，没有将数据存入文件!\n";
  return;
 }
 CNode *pnode;
 CTelRecord *pTel;
 string strName,strNumber;
 pnode=TelList.GetListHead();
 while(pnode)
 {
  pTel=(CTelRecord *)pnode->GetData();
  outfile.write((char *)pTel,sizeof(CTelRecord));
  pnode=TelList.GetListNextNode(pnode);
 }
 outfile.close();
}
void Operate(string &strChoice,CList&TelList)
{
     if (strChoice=="1")
 AddRecord(TelList);
 else if (strChoice=="5")
             DisplayRecord(TelList);
   
            else if (strChoice=="3")
  LookUpRecord(TelList);
       
         else if (strChoice=="4")
    DeleteRecord(TelList);
           else if(strChoice=="2")
             ModifyRecord(TelList);
             else if (strChoice=="6")
     
        StoreFile(TelList);
    else cout<<"对不起，您的输入有误，请重新输入您的选择:  "<<endl;
}
void LoadFile(CList &TelList)
{
 fstream infile("TELEPHONE.DAT",ios::binary);
 if (!infile)
 {
  cout<<"没有数据文件!\n\n";
  return;
 }
 CNode *pNode;
 CTelRecord *pTel;
 while (!infile.eof())
 {
  pTel=new CTelRecord;
  infile.read((char*)pTel,sizeof(CTelRecord));
  pNode=new CNode;
  pNode->InputData(pTel);
  TelList.AddNode(pNode);
 }
 TelList.DeleteNode(pNode); 
 infile.close();
}

int main()
{
  CList TelList;
  system("cls");
  cout<<"*******************************************************************"<<endl;
  cout<<"   --------------******欢迎进入电话簿管理系统******-------------\n";
        cout<<"*******************************************************************"<<endl;
  LoadFile(TelList);
  string strChoice;
  do
  {   cout<<"-------------【欢迎进入系统菜单】-------------  "<<endl;
   cout<<"              1.增加数据                        "<<endl;
   cout<<"              2.更新数据                        "<<endl;
   cout<<"              3.查询数据                        "<<endl;
   cout<<"              4.删除数据                        "<<endl;
   cout<<"              5.全部数据                        "<<endl;
   cout<<"              6.退    出                        "<<endl;
   cout<<"【请输入您的选择】："<<endl;
   cin>>strChoice;
   cin.ignore();
   Operate(strChoice,TelList);
  }while(strChoice!="6");
                StoreFile(TelList);
  cout<<"*******************************************************************"<<endl;
  cout<<"   ------------******欢迎再次使用电话簿管理系统******----------    "<<endl;
        cout<<"*******************************************************************"<<endl;
  system("pause");
                return 0;
}