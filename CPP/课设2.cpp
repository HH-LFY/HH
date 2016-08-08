#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#define N 20

struct book   //һ������Ӧ�ð��������ݣ����֣��鼮���룬���ߣ������磬��棩
{
    char name[N];   //����
    int num;    //�鼮����
    char author[N];//����
    char pub[N];    //������
    int total;      //�Ȿ���ܹ�����
    book *next;
}*head=NULL,*p1,*p2;

int n=0;


/********************�����鼮**********************/
book *creat()    //��������
{
    p1=new(book);            //���ٶ�̬�ڴ�洢�ռ����½��
    cout<<"������Ҫ���ӵ��鼮��ţ�����Ϊ0ʱֹͣ����: ";
    cin>>p1->num;

    while(p1->num!=0)
    {
        n++;
        if(n==1)
            head=p1;            //��һ����㸳��ͷ���
        else
            p2->next=p1;     //���������½����Ľ��
            cout<<"�������鼮���֣�";
            cin>>p1->name;
            cout<<"�������鼮���ߣ�";
            cin>>p1->author;
            cout<<"�������鼮�����磺";
            cin>>p1->pub;
            cout<<"������Ҫ��Ӹ��鼮��Ŀ��";
            cin>>p1->total;
            p2=p1;
            cout<<"������Ҫ���ӵ��鼮��ţ�����Ϊ0ʱֹͣ����: ";
        p1=new(book);        //�������ٶ�̬�ڴ�洢�ռ����½��
        cin>>p1->num;
    }
    cout<<endl<<endl;
    delete p1;                  //ֹͣ�����½��
    p2->next=NULL;
    return head;
}
/*********************�����ʾ��ǰ�鼮��Ϣ*******************/
void print(book *head)//�������
{
    book *p;
    p=head;
    if(p==NULL)
    {
        cout<<"�����û���鼮! "<<endl;
        return;
    }
    cout<<"Ŀǰ��������鼮��ϢΪ��"<<endl
        <<"���"<<"      "<<"����"<<"        "
        <<"����"<<"        "<<"������"<<"        "
        <<"��Ŀ"<<endl;
    do
    {
        cout<<p->num<<"      "<<p->name<<setw(10)
            <<p->author<<"    "<<p->pub<<setw(10)
            <<p->total<<endl;
        p=p->next;
    }
    while(p!=NULL);

}

/****************ɾ���鼮**************************/
book *del(book *head)         //ɾ�����
{
    book *p1,*p2;
    int num;
    if(head==NULL)          //���ԭ������Ϊ��
    {
        cout<<"�����û���鼮!"<<endl;
        return head;
    }
    cout<<"������Ҫɾ���鼮�ı��룺"<<endl;
    cin>>num;
    p1=head;
    while(num!=p1->num && p1->next!=NULL)     //�Ҳ�����Ӧ�Ľ������¼�������
    {
        p2=p1;
        p1=p1->next;
    }
    if(num==p1->num)         //�ҵ����
    {
        if(p1==head)            //����ǵ�һλ
            head=p1->next;
        else                    //��㲻�ǵ�һλ
            p2->next=p1->next;
        cout<<"ɾ���ɹ�"<<endl<<endl;
        n--;
        print(head);
    }
    else
        cout<<"�����ڸñ�ŵ��鼮"<<endl<<endl;


    return head;
}
/****************ͨ����Ų�ѯ�鼮**************************/
void find_num(book *head)         //ɾ�����
{
    book *p1;
    int num;
    cout<<"������Ҫ��ѯ���鼮��ţ�"<<endl;
    cin>>num;
    if(head==NULL)          //���ԭ������Ϊ��
    {
        cout<<"�����û���鼮!"<<endl;
        return;
    }
    p1=head;
    while(num!=p1->num && p1->next!=NULL)     //�Ҳ�����Ӧ�Ľ������¼�������
    {
        p1=p1->next;
    }
    if(num==p1->num)         //�ҵ����
    {
        cout<<"���ҵ����鼮��ϢΪ��"<<endl
        <<"���"<<"    "<<"����"<<"    "
        <<"����"<<"    "<<"������"<<"    "
        <<"��Ŀ"<<endl;
        cout<<p1->num<<setw(10)<<p1->name<<setw(7)
            <<p1->author<<setw(10)<<p1->pub<<setw(8)
            <<p1->total<<endl;
    }
    else
        cout<<"�Ҳ������鼮!"<<endl<<endl;

}
/****************ͨ��������ѯ�鼮**************************/
void find_name(book *head)         //ɾ�����
{
    book *p1;
    char name[N];
    cout<<"������Ҫ��ѯ���鼮���֣�"<<endl;
    cin>>name;

      if(head==NULL)          //���ԭ������Ϊ��
    {
        cout<<"�����û���鼮!"<<endl;
        return;
    }
    p1=head;
    while(strcmp(name,p1->name)!=0 && p1->next!=NULL)     //�Ҳ�����Ӧ�Ľ������¼�������
    {
        p1=p1->next;
    }
    if(strcmp(name,p1->name)==0)         //�ҵ����
    {
        cout<<"���ҵ����鼮��ϢΪ��"<<endl
        <<"���"<<"    "<<"����"<<"    "
        <<"����"<<"    "<<"������"<<"    "
        <<"��Ŀ"<<endl;
        cout<<p1->num<<setw(10)<<p1->name<<setw(7)
            <<p1->author<<setw(10)<<p1->pub<<setw(8)
            <<p1->total<<endl;
    }
    else
        cout<<"�Ҳ������鼮!"<<endl<<endl;

}
/*********************�����鼮*******************/
book *borrow(book *head)
{

    if(head==NULL)          //���ԭ������Ϊ��
    {
        cout<<"�����û���鼮!"<<endl;
        return head;
    }
    cout<<"������Ҫ�����鼮�����ƣ�"<<endl;
    char name[N];
    cin>>name;
    book *p1;
    p1=head;
    while(strcmp(name,p1->name)!=0 && p1->next!=NULL)     //�Ҳ�����Ӧ�Ľ������¼�������
    {
        p1=p1->next;
    }
    if(strcmp(name,p1->name)==0)         //�ҵ����
    {
        cout<<"���ҵ����鼮��ϢΪ��"<<endl
        <<"���"<<"    "<<"����"<<"    "
        <<"����"<<"    "<<"������"<<"    "
        <<"��Ŀ"<<endl;
        cout<<p1->num<<setw(10)<<p1->name<<setw(7)
            <<p1->author<<setw(10)<<p1->pub<<setw(8)
            <<p1->total<<endl;
        if(p1->total!=0)
        {
            cout<<"ȷ��Ҫ���ĸ��鼮��"<<endl
                <<"1.ȷ��"<<'\t'<<"2.ȡ��"<<endl;
            int num; cin>>num;
            switch(num)
            {
                case 1:
                        cout<<"���ĳɹ�!"<<endl;
                        (p1->total)--;break;
                case 2: break;
                default:cout<<"��������!"<<endl;break;
            }
        }
        else
            cout<<"�鼮��ȫ������!"<<endl;
    }
    else
        cout<<"�Ҳ������鼮!"<<endl<<endl;


    return head;

}
/*********************�黹�鼮*********************/
book *back(book *head)
{

    if(head==NULL)          //���ԭ������Ϊ��
    {
        cout<<"���δ������κ��鼮! "<<endl;
        return head;
    }
    cout<<"������Ҫ�黹�鼮�����ƣ�"<<endl;
    char name[N];
    cin>>name;
    book *p1;
    p1=head;
    while(strcmp(name,p1->name)!=0 && p1->next!=NULL)     //�Ҳ�����Ӧ�Ľ������¼�������
    {
        p1=p1->next;
    }
    if(strcmp(name,p1->name)==0)         //�ҵ����
    {

            cout<<"ȷ��Ҫ�黹���鼮��"<<endl
                <<"1.ȷ��"<<'\t'<<"2.ȡ��"<<endl;
            int num; cin>>num;
            switch(num)
            {
                case 1:
                        cout<<"����ɹ�!"<<endl;
                        (p1->total)++;break;
                case 2: break;
                default:cout<<"��������!"<<endl;break;
            }

    }
    else
        cout<<"�����ڸ��鼮!"<<endl<<endl;


    return head;

}
/***********************��ѯ�˵�***********************/
void find()
{
    int num;
    cout<<"   ***************************************************"<<endl;
    cout<<"   *           �������Ӧ���ܵ�������ɲ���          *"<<endl;
    cout<<"   *                 1.ͨ����Ų���                  *"<<endl;
    cout<<"   *                 2.ͨ����������                  *"<<endl;
    cout<<"   ***************************************************"<<endl;
    cin>>num;
    switch(num)
    {
    case 1:find_num(head);break;
    case 2:find_name(head);break;
    default:cout<<"��������!"<<endl;break;
    }
}

/***********************����˵�***********************/
void manage()
{
    int num1;
    cout<<"���������Ա����(123456)��"<<endl;        //�涨ֻ�й���Ա����Ȩ������ͼ��
    cin>>num1;
    if(num1==123456)
    {
        int num;
        cout<<"   ***************************************************"<<endl;
        cout<<"   *           �������Ӧ���ܵ�������ɲ���          *"<<endl;
        cout<<"   *                     1.�����鼮                  *"<<endl;
        cout<<"   *                     2.ɾ���鼮                  *"<<endl;
        cout<<"   ***************************************************"<<endl;
        cin>>num;
        switch(num)
        {
        case 1:head=creat();
                print(head);
                break;
        case 2:head=del(head);break;
        default:cout<<"��������!"<<endl;break;
        }
    }
    else
        cout<<"���������û��Ȩ���޸�ͼ�����ϵͳ!"<<endl;
}


void displaymain()
{
    cout<<"   ***************************************************"<<endl;
    cout<<"   *           �������Ӧ���ܵ�������ɲ���          *"<<endl;
    cout<<"   *                     1.��ѯ                      *"<<endl;
    cout<<"   *                     2.����                      *"<<endl;
    cout<<"   *                     3.����                      *"<<endl;
    cout<<"   *                     4.����                      *"<<endl;
    cout<<"   *                     5.���                      *"<<endl;
    cout<<"   *                     6.�˳�                      *"<<endl;
    cout<<"   ***************************************************"<<endl;
}

int main()
{
    cout<<endl<<"                        ��ӭʹ��ͼ�����ϵͳ"<<endl<<endl;
    int choice=1;
    while(choice!=0)
    {
        displaymain();
        cin>>choice;
        switch(choice)
        {
            case 1: find();break;
            case 2: head=borrow(head);break;
            case 3: head=back(head);break;
            case 4: manage();break;
            case 5: print(head);break;
            case 6: choice=0;break;
            default:cout<<"������������������!"<<endl;break;

        }
    }
    cout<<"   ***************************************************"<<endl;
    cout<<"   *                                                 *"<<endl;
    cout<<"   *                  ��л����ʹ��!                  *"<<endl;
    cout<<"   *                                                 *"<<endl;
    cout<<"   *     designer������           from:�Զ���1122    *"<<endl;
    cout<<"   *                                                 *"<<endl;
    cout<<"   ***************************************************"<<endl;

    return 0;
}
