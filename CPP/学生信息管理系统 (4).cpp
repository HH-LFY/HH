#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
using namespace std;
int count=100;//���ѧ����
void seek();//��ѯ
void modify();//�޸���Ϣ
void insert();//����
void del();//ɾ��
void display();//���������Ϣ
void menu();//����
class Student //����ѧ����
{
public:
    char num[20];//ѧ��
    char name[20];//����
    char sex[3];//�Ա�
    char time[20];//��������
    char add[10];//����
    char yuan[10];//����ѧԺ
} stud[100];
int k=1,n=0;//����ȫ�ֱ���
void menu() //����
{
    int num;
    cout<<"\n\n\t\t\t\t����ѧ����Ϣ����ϵͳ\n\n"<<endl;
    cout<<"\t\t\t\t*****ϵͳ���ܲ˵�"<<endl;
    cout<<"\t\t--------------------\n"<<endl;
    cout<<"\t\t1.����ѧ����Ϣ\n"<<endl;
    cout<<"\t\t2.�޸�ѧ����Ϣ\n"<<endl;
    cout<<"\t\t3.��ѯѧ����Ϣ\n"<<endl;
    cout<<"\t\t4.��ѧ��ɾ����Ϣ\n"<<endl;
    cout<<"\t\t5.��ʾ��ǰ��Ϣ\n"<<endl;
    cout<<"\t\t6.�˳�ϵͳ\n"<<endl;
    cout<<"\t\t--------------------\n"<<endl;
    cout<<"\t\t��ѡ��˵����:";
    cin>>num;
    switch(num)
    {
    case 1:
        insert();
        break;
    case 2:
        modify();
        break;
    case 3:
        seek();
        break;
    case 4:
        del();
        break;
    case 5:
        display();
        break;
    case 6:
        k=0;
        break;
    default:
        cout<<"����1-6֮��ѡ��\n"<<endl;
    }
}
void seek()//��ѯ
{
    int item;//�Ӳ˵����
    int i;
    int flag;//�ж�ѧ���Ƿ����
    char s1[10];
    cout<<"--------------------\n"<<endl;
    cout<<"1.��ѧ�Ų�ѯ\n"<<endl;
    cout<<"2.��������ѯ\n"<<endl;
    cout<<"3.�˳����˵�\n"<<endl;
    cout<<"--------------------\n";
    while(1)
    {
        cout<<"��ѡ���Ӳ˵����:";
        cin>>item;
        flag=0;//�ȸ���������ֵ0
        switch(item)
        {
        case 1:
            cout<<"������Ҫ��ѯ��ѧ����ѧ��:\n";
            cin>>s1;
            for(i=0; i<n; i++){
                if(strcmp(stud[i].num,s1)==0)
                {
                    flag=1;//flag=1��ʾ���ڸ�ѧ��
                    cout<<"��ѧ��ѧ�ţ��������Ա𣬳������£����ᣬ����ѧԺ �ֱ�Ϊ:\n"<<endl;
                    cout<<stud[i].num<<"         ";
                    cout<<stud[i].name<<"         ";
                    cout<<stud[i].sex<<"          ";
                    cout<<stud[i].time<<"          ";
                    cout<<stud[i].add<<"          ";
                    cout<<stud[i].yuan<<"          "<<endl;
				}
			}
				if(flag==0) cout<<"��ѧ�Ų�����!\n"<<endl;
            break;
        case 2:
            cout<<"������Ҫ��ѯѧ��������\n"<<endl;
            cin>>s1;
            for(i=0; i<n; i++)
                if(strcmp(stud[i].name,s1)==0)
                {
                    flag=1;//���ڸ�����
                    cout<<"��ѧ��ѧ�ţ��������Ա𣬳������£����ᣬ����ѧԺ �ֱ�Ϊ:\n"<<endl;
                    cout<<stud[i].num<<"         ";
                    cout<<stud[i].name<<"         ";
                    cout<<stud[i].sex<<"          ";
                    cout<<stud[i].time<<"          ";
                    cout<<stud[i].add<<"          ";
                    cout<<stud[i].yuan<<"          "<<endl;
                }
            if(flag==0) cout<<"������������!\n"<<endl;
            break;//��ֹѭ��
        case 3:
            return;
        default:
            cout<<"����1-3֮��ѡ��\n"<<endl;
        }
    }
}
void insert()
{
    int j,x,k;
    cout<<"���������ӵ�ѧ����:\n";
    cin>>x;
    for(j=0; j<x; j++) //����x��ѧ������Ϣ
    {
        cout<<"������ѧ��ѧ��\n";
        cin>>stud[n].num;
        for(k=0; k<n; k++)
            if(strcmp(stud[n].num,stud[k].num)==0)
            {
                cout<<"���и�ѧ��,�������������!\n"<<endl;
				j=j-1;
                break;
            }
        if(k==n) //k==n��ʾ��ѧ���������ӵ�
        {
            cout<<"������ѧ��������:\n";
            cin>>stud[n].name;
            cout<<"������ѧ�����Ա�:\n";
            cin>>stud[n].sex;
            cout<<"������ѧ���ĳ�������:\n";
            cin>>stud[n].time;
            cout<<"������ѧ���ļ���:\n";
            cin>>stud[n].add;
            cout<<"������ѧ��������ѧԺ:\n";
            cin>>stud[n].yuan;
            cout<<"¼��ɹ�!!\n\n"<<endl;
			n=n+1;//ѧ��������1
        }
    }
}
void modify()
{
    int i,item,num,flag=0;
    char s1[10],s2[20];
    cout<<"������Ҫ�޸�ѧ����ѧ�� :\n";
	while(!flag)
	{
        cin>>s1;
        for(i=0; i<n; i++)//�жϸ�ѧ���Ƿ����
		{
            if(strcmp(s1,stud[i].num)==0) num=i,flag=1;
		}
		if(flag==0) cout<<"��ѧ�Ų����ڣ�����������!!!\n";
	}
        cout<<"--------------------\n"<<endl;
        cout<<"1.  ��  ��  ��  ��  \n"<<endl;
        cout<<"2.  ��  ��  ��  ��  \n"<<endl;
        cout<<"3.  ��  ��  ��  ��  ��  ��  \n"<<endl;
        cout<<"4.  ��  ��  ��  ��  \n"<<endl;
        cout<<"5.  ��  ��  ��  ��  ѧ  Ժ  \n"<<endl;
        cout<<"6.  ��  ��  ��  ��  ��  \n"<<endl;
        cout<<"--------------------\n"<<endl;
		while(1)
	{
		cout<<"��ѡ���Ӳ˵����\n";
        cin>>item;
        switch(item)
        {
        case 1:
            cout<<"�������µ�����:\n";
            cin>>s2;
            strcpy(stud[num].name,s2);
            break;
        case 2:
            cout<<"�������µ��Ա�:\n";
            cin>>s2;
            strcpy(stud[num].sex,s2);
            break;
        case 3:
            cout<<"�������µĳ�������:\n";
            cin>>s2;
            strcpy(stud[num].time,s2);
            break;
        case 4:
            cout<<"�������µļ���:\n";
            cin>>s2;
            strcpy(stud[num].add,s2);
            break;
        case 5:
            cout<<"�������µ�����ѧԺ:\n";
            cin>>s2;
            strcpy(stud[num].yuan,s2);
            break;
        case 6:
            return;
        default:
            cout<<"����1-6֮��ѡ��\n"<<endl;
		}
    }
}
void del()
{
    int i,x,j=0;
    char s1[10];
    cout<<"������Ҫɾ��ѧ����ѧ��:\n";
    cin>>s1;
    for(i=0; i<count; i++)
    {
        if(strcmp(stud[i].num,s1)==0)
        {
            for(x=i; x<count-1; x++)
            {
                stud[x]=stud[x+1];
                j++;
                count=count-1;
            }
            if(j==0) cout<<"��ѧ�Ų�����!\n"<<endl;
            if(j!=0) cout<<"ɾ���ɹ�����ʾ�����ѡ��˵�5\n"<<endl;
        }
    }
}
void display()
{
    int i;
    cout<<"����ѧ����ϢΪ:\n"<<endl;
    for(i=0; i<n; i++)
    {
       cout<<"ѧ�ţ��������Ա𣬳������£����ᣬ����ѧԺ�ֱ�Ϊ:\n"<<endl;
        cout<<stud[i].num<<"  ";
        cout<<stud[i].name<<"  ";
        cout<<stud[i].sex<<"  ";
        cout<<stud[i].add<<"  ";
        cout<<stud[i].yuan<<"  "<<endl;
    }
}
int main()
{
    while(k)menu();
    system("pause");//ϵͳ��ֹ
    return 0;
}
