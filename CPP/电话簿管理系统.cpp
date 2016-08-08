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
 cout<<"����������������0�˳���������ϵͳ�˵�)"<<endl;
 cin.getline(szName,20);
 while(strcmp(szName,"0"))
 {
  cout<<"������绰����:  "<<endl;
     cin.getline(szNumber,20);
  pTel=new CTelRecord;
     pTel->SetRecord(szName,szNumber);
     pNode=new CNode;
     pNode->InputData(pTel);
            TelList.AddNode(pNode);
            count++;
     cout<<"����������������0�˳���������ϵͳ�˵��� "<<endl;
     cin.getline(szName,20);
 }
 cout<<endl<<endl;
}

void DisplayRecord(CList&TelList)
{
 cout<<"Ŀǰ���� "<<count<<" ����¼�������¼���£�"<<endl;
 cout<<setw(15)<<"��������"<<setw(15)<<"���绰���롿"<<endl;
 TelList.ShowList();
 cout<<endl<<endl;
        system("pause");
}

void LookUpRecord(CList&TelList)
{
 CNode *pLook;
 char szName[20];
 cout<<"����������Ҫ���ҵ�����������0�˳���������ϵͳ�˵���"<<endl;
 cin.getline(szName,20);
 while (strcmp(szName,"0"))
 {
  CTelRecord tele(szName,"0");
  pLook=TelList.LookUp(tele);
  if (pLook)
  {
   cout<<"�ڵ绰�����ҵ�"<<szName<<",�����ǣ�"<<endl;
            cout<<setw(15)<<"��������"<<setw(15)<<"���绰���롿"<<endl;
   pLook->ShowNode();
  }
  else 
   cout<<"�ڵ绰�����Ҳ���"<<szName<<","<<endl;
  cout<<"����������Ҫ���ҵ�����������0�˳���������ϵͳ�˵���"<<endl;
  cin.getline(szName,20);
 }
 cout<<endl<<endl;
}

void DeleteRecord(CList&TelList)
{
 CNode *pLook;
 char szName[20];
        cout<<"����������Ҫɾ��������������0�˳���������ϵͳ�˵���"<<endl;
 cin.getline(szName,20);
 while(strcmp(szName,"0"))
 {
  CTelRecord tel(szName,"0");
  pLook=TelList.LookUp(tel);
  if (pLook)
  {
   cout<<"�ڵ绰�����ҵ�"<<szName<<",�����ǣ�"<<endl;
               pLook->ShowNode();
   cout<<"��ȷ���Ƿ�ɾ���˼�¼��Y/N)��ȷ��ɾ��������Y��y,ȡ��ɾ��������N��n��:"<<endl;
   char ok;
   cin>>ok;
                        cin.ignore();
   if (ok=='Y'||ok=='y')
   {
       TelList.DeleteNode(pLook);
       cout<<szName<<"������ɾ���ɹ���"<<endl;
       delete pLook;
       count--;
   }
   else if(ok=='N'||ok=='n')
    cout<<szName<<"������ɾ��ʧ��"<<endl;
  }
  else
    cout<<"�ڵ绰�����Ҳ���"<<szName<<","<<endl;
  cout<<"����������Ҫɾ��������������0�˳���������ϵͳ�˵���"<<endl;
        cin.getline(szName,20);
 }
 cout<<endl<<endl;
}
void ModifyRecord(CList &TelList)
{
 CNode *pLook;
 CTelRecord *pTel;
 char szName[20],szNumber[20];
 cout<<"����������Ҫ�޸ĵ�����������0�˳���������ϵͳ�˵���"<<endl;
 cin.getline(szName,20);
 while(strcmp(szName,"0"))
 {
        CTelRecord tel(szName,"0");
  pLook=TelList.LookUp(tel);
  if (pLook)
  {
   cout<<"�ڵ绰�����ҵ�"<<szName<<",�����ǣ�"<<endl;
               pLook->ShowNode();
                        cout<<"-----���濪ʼ�޸�-----"<<endl<<"�������޸ĺ������:  "<<endl;
   cin.getline(szName,20);
   cout<<"�������޸ĺ�ĵ绰����:"<<endl;
            cin.getline(szNumber,20);
      cout<<"��ȷ���Ƿ��޸Ĵ˼�¼��Y/N)��ȷ���޸�������Y��y,ȡ���޸�������N��n��:"<<endl;
   char ok;
   cin>>ok;
                        cin.ignore();
   if (ok=='Y'||ok=='y')
   {
     pTel=new CTelRecord;
     *pTel=tel;
     pTel->SetRecord(szName,szNumber);
     pLook->InputData(pTel);
                          cout<<szName<<"�������޸ĳɹ���"<<endl;
   }
                        else if(ok=='N'||ok=='n')
                cout<<szName<<"�������޸�ʧ�ܣ�"<<endl;
  }
               else
    cout<<"  �ڵ绰�����Ҳ���"<<szName<<","<<endl;
        cout<<"  ����������Ҫ�޸ĵ�����������0�˳���������ϵͳ�˵���";
        cin.getline(szName,20);
 }
}

void StoreFile(CList&TelList)
{
 ofstream outfile("TELEPHONE.DAT",ios::binary);
 if (!outfile)
 {
  cout<<"  ���ݿ��ļ��򿪴���û�н����ݴ����ļ�!\n";
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
    else cout<<"�Բ�����������������������������ѡ��:  "<<endl;
}
void LoadFile(CList &TelList)
{
 fstream infile("TELEPHONE.DAT",ios::binary);
 if (!infile)
 {
  cout<<"û�������ļ�!\n\n";
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
  cout<<"   --------------******��ӭ����绰������ϵͳ******-------------\n";
        cout<<"*******************************************************************"<<endl;
  LoadFile(TelList);
  string strChoice;
  do
  {   cout<<"-------------����ӭ����ϵͳ�˵���-------------  "<<endl;
   cout<<"              1.��������                        "<<endl;
   cout<<"              2.��������                        "<<endl;
   cout<<"              3.��ѯ����                        "<<endl;
   cout<<"              4.ɾ������                        "<<endl;
   cout<<"              5.ȫ������                        "<<endl;
   cout<<"              6.��    ��                        "<<endl;
   cout<<"������������ѡ�񡿣�"<<endl;
   cin>>strChoice;
   cin.ignore();
   Operate(strChoice,TelList);
  }while(strChoice!="6");
                StoreFile(TelList);
  cout<<"*******************************************************************"<<endl;
  cout<<"   ------------******��ӭ�ٴ�ʹ�õ绰������ϵͳ******----------    "<<endl;
        cout<<"*******************************************************************"<<endl;
  system("pause");
                return 0;
}