#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<windows.h>
#include<conio.h>
#define ESC 27
using namespace std;
struct Friend //����һ��Friend�ṹ��
{
    char name[20]; //����
    int age; //����
    char sex[5];
    char guanxi[10]; //��ϵ����:���ѡ�ͬѧ������
    char number[20]; //�绰����
    char qnumber[20]; //QQ����
}  fri[20];

void add()
{
    system("cls");
    cout << "                �v               ��  ͨѶ¼  ��               �u\n";
	cout << "                  �v            ��    ����    ��            �u  \n";
	cout << "                    �v         ��    System    ��         �u    \n";
	cout << "                      �v      ��    �����Ϣ    ��      �u      \n";
    int i;
    char yn;
    Friend stu[20];
    cout<<"�밴˳��������ӵ���Ϣ:"<<endl;
    for(i = 3; i < 20; i++)   //��¼�뵽�ṹ����
    {
        cout << "����:";
        cin >> stu[i].name;
        cout << "����:";
        cin >> stu[i].age;
        cout << "�Ա�:";
        cin >> stu[i].sex;
        cout << "��ϵ:(A.���ѡ�B.ͬѧ��C.����)" << endl;
        char g;
        g = getch();
        if(g == 'a' || g == 'A')
        {
            strcpy(stu[i].guanxi,"����");
            cout << "���"<< stu[i].name << "�Ĺ�ϵ:����" << endl;
        }
        if(g == 'b' || g == 'B')
        {
            strcpy(stu[i].guanxi,"ͬѧ");
            cout << "���"<< stu[i].name << "�Ĺ�ϵ:ͬѧ" << endl;
        }
        if(g == 'c' || g == 'C')
        {
            strcpy(stu[i].guanxi,"����");
            cout << "���"<< stu[i].name << "�Ĺ�ϵ:����" << endl;
        }
        cout << "�绰����:";
        cin >> stu[i].number;
        cout << "QQ����:";
        cin >> stu[i].qnumber;
        fstream iofile("Frident.dat",ios::in|ios::out|ios::binary);
        if(! iofile)
        {
            cerr<<"�ļ���ʧ��!"<<endl;
            exit(1);
        }
        iofile.seekp(0,ios::end);  //�ҵ��ļ�ĩβ
        iofile.write((char *)&stu[i],sizeof(stu[i]));  //�ѽṹ������Ϣ��ӵ��ļ�ĩβ��
        iofile.close();
        cout << "��ESC���������˵�,����������������Ϣ" << endl;
        yn = getch();
        if(yn == ESC) break;
        else continue;
    }
}

int del()
{
    system("cls");
    cout << "                �v               ��  ͨѶ¼  ��               �u\n";
	cout << "                  �v            ��    ����    ��            �u  \n";
	cout << "                    �v         ��    System    ��         �u    \n";
	cout << "                      �v      ��    ɾ����Ϣ    ��      �u      \n";
    while(true)
    {
        cout<<"����������:";
        string name;
        int temp = -1;
        int j = 1, i, k = 1;
        cin >> name;
        ifstream iofile("Frident.dat",ios::in|ios::out|ios::binary);
        if(! iofile)
        {
            cerr<<"�ļ���ʧ��!"<<endl;
            abort();
        }
        iofile.seekg(0,ios::beg); //�ҵ��ļ�ͷ
        for(i = 0; i < 20; i++)//���ļ��е�һ��
        {
            if(fri[i].age) k = 0;
            iofile.read((char *)&fri[i],sizeof(fri[i]));
            if(name == fri[i].name)
            {
                j = 0;   //�ҵ�����б��
                temp = i;  //�ҵ������
            }
        }
        iofile.close();
        if(k)
        {
            cout << "��Ǹ,ϵͳ���ݱ�������,�������˵������Ϣ��" << endl;
            Sleep(2000);
            cout << "���ڷ������˵�����" << endl;
            return 1;
        }
        if(j)
        {
            cout << "��Ǹ,ϵͳ�þ���ţ����֮����û���ҵ�" << name << endl;
            cout << "��ESC���������˵�,�����������ɾ����Ϣ" << endl;
            char yn;
            yn = getch();
            if(yn == ESC)
            {
                cout << "���ڷ������˵�����" << endl;
                Sleep(2000);
                return 1;
            }
            else continue;
        }
        if(temp != -1)
        {
            ofstream iofile("Frident.dat",ios::in|ios::out|ios::binary);
            if(! iofile)
            {
                cerr<<"�ļ���ʧ��!"<<endl;
                abort();
            }
            cout<<"ȷ��ɾ��[" << fri[temp].name << "]��?[y/n]"<<endl;
            char c;
            c = getch();
            if(c =='y')    //�Ѵ�ɾ��������ѧ����Ϣ��0������д���ļ�����ʵδ����ɾ��
            {
                fri[temp].name[0]='0';
                fri[temp].age=0;
                iofile.seekp(temp*sizeof(fri[temp]),ios::beg);
                iofile.write((char *)&fri[temp],sizeof(fri[temp]));
                cout<<"�Ѿ��ɹ�ɾ��!"<<endl;   //��ʵδ����ɾ��
            }
            if(c == 'n')
            {
                cout << "ȡ��ɾ��,���ڷ������˵�����" << endl;
                Sleep(2000);
                return 1;
            }
        }
        cout << "��ESC���������˵�,�����������ɾ����Ϣ" << endl;
        char yn;
        yn = getch();
        if(yn == ESC)
        {
            cout << "���ڷ������˵�����" << endl;
            Sleep(2000);
            return 1;
        }
        else continue;
    }
}

int change()
{
    system("cls");
    cout << "                �v               ��  ͨѶ¼  ��               �u\n";
	cout << "                  �v            ��    ����    ��            �u  \n";
	cout << "                    �v         ��    System    ��         �u    \n";
	cout << "                      �v      ��    �޸���Ϣ    ��      �u      \n";
    while(true)
    {
        cout<<"����������:";
        string name;
        int age, k = 1;
        char sex[5];
        char guanxi[10];
        char number[20];
        char qnumber[20];
        int j = 1, i, temp = -1;
        cin >> name;
        ifstream iofile("Frident.dat",ios::in|ios::out|ios::binary);
        if(! iofile)
        {
            cerr<<"�ļ���ʧ��!"<<endl;
            abort();
        }
        iofile.seekg(0,ios::beg);
        for(i=0;i<20;i++)
        {
            if(fri[i].age) k = 0;
            iofile.read((char *)&fri[i],sizeof(fri[i]));
            if(name == fri[i].name)
            {
                j = 0;
                temp = i;
            }
        }
        if(k)
        {
            cout << "��Ǹ,ϵͳ���ݱ�������,�������˵������Ϣ��" << endl;
            Sleep(2000);
            cout << "���ڷ������˵�����" << endl;
            return 1;
        }
        if(j)
        {
            cout << "��Ǹ,ϵͳ�þ���ţ����֮����û���ҵ�" << name << endl;
            cout << "��ESC���������˵�,������������޸���Ϣ" << endl;
            char yn;
            yn = getch();
            if(yn == ESC)
            {
                cout << "���ڷ������˵�����" << endl;
                Sleep(2000);
                return 1;
            }
            else continue;
        }
        iofile.close();
        if(temp != -1)
        {
            ofstream iofile("Frident.dat",ios::in|ios::out|ios::binary);
            if(! iofile)
            {
                cerr<<"�ļ���ʧ��!"<<endl;
                abort();
            }
            cout << "ȷ���޸�[" << fri[temp].name << "]��?[y/n]"<< endl;
            char c;
            c = getch();
            if(c=='y')
            {
                char name[20];
                cout << "����:";
                cin >> name;
                strcpy(fri[temp].name,name);
                cout << "����:";
                cin >> age;
                fri[temp].age = age;
                cout<<"�Ա�:";
                cin >> sex;
                strcpy(fri[temp].sex,sex);
                cout << "��ϵ:(A.���ѡ�B.ͬѧ��C.����)" << endl;
                char g;
                g = getch();
                if(g == 'a' || g == 'A')
                {
                    strcpy(fri[temp].guanxi,"����");
                    cout << "���"<< fri[temp].name << "�Ĺ�ϵ��Ϊ:����" << endl;
                }
                if(g == 'b' || g == 'B')
                {
                    strcpy(fri[temp].guanxi,"ͬѧ");
                    cout << "���"<< fri[temp].name << "�Ĺ�ϵ��Ϊ:ͬѧ" << endl;
                }
                if(g == 'c' || g == 'C')
                {
                    strcpy(fri[temp].guanxi,"����");
                    cout << "���"<< fri[temp].name << "�Ĺ�ϵ��:����" << endl;
                }
                cout << "�绰����:";
                cin >> number;
                strcpy(fri[temp].number,number);
                cout << "QQ:";
                cin >> qnumber;
                strcpy(fri[temp].qnumber,qnumber);
                iofile.seekp(temp*sizeof(fri[temp]),ios::beg);
                iofile.write((char *)&fri[temp],sizeof(fri[temp]));
                cout<<"�Ѿ��ɹ��޸ģ�"<<endl;
            }
            if(c == 'n')
            {
                cout << "ȡ���޸�,���ڷ������˵�����" << endl;
                Sleep(2000);
                return 1;
            }
        }
        cout << "��ESC���������˵�,������������޸���Ϣ" << endl;
        char yn;
        yn = getch();
        if(yn == ESC)
        {
            cout << "���ڷ������˵�����" << endl;
            Sleep(2000);
            return 1;
        }
        else continue;
    }
}

int find()  //�����ֲ��Ҵ���
{
    system("cls");
    cout << "                �v               ��  ͨѶ¼  ��               �u\n";
	cout << "                  �v            ��    ����    ��            �u  \n";
	cout << "                    �v         ��    System    ��         �u    \n";
	cout << "                      �v      ��    ������Ϣ    ��      �u      \n";
    while(true)
    {
        cout<<"������Ҫ���ҵ�����:";
        string name;
        int j = 1, i, k = 1;
        cin>>name;
        fstream iofile("Frident.dat",ios::in|ios::binary);
        if(! iofile)
        {
            cerr<<"�ļ���ʧ��!"<<endl;
            abort();
        }
        iofile.seekg(0,ios::beg);
        for(i = 0; i < 20; i++)
        {
            if(fri[i].age) k = 0;
            iofile.read((char *)&fri[i],sizeof(fri[i]));
            if(name == fri[i].name)
            {
                j = 0;
                cout << "����:" << fri[i].name << "  ";
                cout << "����:" << fri[i].age << "  ";
                cout << "�Ա�:" << fri[i].sex << "  ";
                cout << "��ϵ:" << fri[i].guanxi << "  ";
                cout << "�绰:" << fri[i].number << "  ";
                cout << "QQ:" << fri[i].qnumber << endl;
            }
        }
        iofile.close();
        if(k)
        {
            cout << "��Ǹ,ϵͳ���ݱ�������,�������˵������Ϣ��" << endl;
            Sleep(2000);
            cout << "���ڷ������˵�����" << endl;
            return 1;
        }
        if(j)
        {
            cout << "��Ǹ,ϵͳ�þ���ţ����֮����û���ҵ�" << name << endl;
            cout << "��ESC���������˵�,�����������������Ϣ" << endl;
            char yn;
            yn = getch();
            if(yn == ESC)
            {
                cout << "���ڷ������˵�����" << endl;
                Sleep(2000);
                return 1;
            }
            else continue;
        }
        cout << "��ESC���������˵�,�����������������Ϣ" << endl;
        char yn;
        yn = getch();
        if(yn == ESC)
        {
            cout << "���ڷ������˵�����" << endl;
            Sleep(2000);
            return 1;
        }
        else continue;
    }
}

int rea()   //��ȡ�ļ������е�����ѧ����Ϣ
{
    system("cls");
    cout << "                �v               ��  ͨѶ¼  ��               �u\n";
	cout << "                  �v            ��    ����    ��            �u  \n";
	cout << "                    �v         ��    System    ��         �u    \n";
	cout << "                      �v      ��  ��ʾ������Ϣ  ��      �u      \n";
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t��ȡ�С���" << endl;
    Sleep(2000);
    system("cls");
    int i , j = 1;
    fstream iofile("Frident.dat",ios::in|ios::binary);
    if(! iofile)
    {
        cerr<<"�ļ���ʧ��!"<<endl;
        abort();
    }
    iofile.seekg(0,ios::beg);
    for(i = 0; i < 20; i++)   //��ѧ��Ϊ��0�Ķ���
    {
        iofile.read((char *)&fri[i],sizeof(fri[i]));
        if(fri[i].age!=0)
        {
            j = 0;
            cout << "����:" << fri[i].name << "  ";
            cout << "����:" << fri[i].age << "  ";
            cout << "�Ա�:" << fri[i].sex << "  ";
            cout << "��ϵ:" << fri[i].guanxi << "  ";
            cout << "�绰:" << fri[i].number << "  ";
            cout << "QQ:" << fri[i].qnumber << endl;
        }
    }
    iofile.close();
    if(j)
    {
        cout << "��Ǹ,ϵͳ���ݱ�������,�������˵������Ϣ��" << endl;
        Sleep(2000);
        cout << "���ڷ������˵�����" << endl;
        return 1;
    }
    cout << "\n\n\n��ESC�������˵�" << endl;
    char r;
    r = getch();
    if(r == ESC) return 1;
}

void message()
{
    cout << "\n\n\n\n\n\t\t**************************************************" << endl;
	cout << "\t\t\t *  ��ӭ����ͨѶ¼��Ϣ����ϵͳ  *" << endl;
	cout << "\t\t**************************************************" << endl << endl;
	cout << "                �v               ��  ͨѶ¼  ��               �u\n";
	cout << "                  �v            ��    ����    ��            �u  \n";
	cout << "                    �v         ��    System    ��         �u    \n";
	cout << "                      �v      ��                ��      �u      \n";
	cout << "                      �u           �������             �v      \n";
	cout << "                    �u        ͨѶ¼��Ϣ����ϵͳ          �v    \n";
	cout << "                  �u                                        �v  \n";
	cout << "                �u                                            �v\n";
	cout << "\n\n���ڼ������˵�,���Ժ򡭡�";
	Sleep(2000);
}

void menu()
{
    system("cls");
	cout << "\n\n\n\n\t\t====================���˵�========================\n\n\n" << endl;
	cout << "\t\t\t  ��   1.��1������ͨѶ¼��Ϣ   ��" << endl;
	cout << "\t\t\t  ��   2.��2��ɾ��ͨѶ¼��Ϣ   ��" << endl;
	cout << "\t\t\t  ��   3.��3���޸�ͨѶ¼��Ϣ   ��" << endl;
	cout << "\t\t\t  ��   4.��4������ͨѶ¼��Ϣ   ��" << endl;
    cout << "\t\t\t  ��   5.��5����ȡ������Ϣ  �� ��" << endl;
	cout << "\t\t\t  ��   6.��ESC���˳�����   ��  ��\n\n\n" << endl;
	cout << "\t\t====================@@@@@@========================" << endl << endl;
}

int main()
{
    message();
    menu();
    while(true) //ͨ��whileѭ���ﵽѭ��������Ŀ��
    {
        char control;
        control = getch();
        if(control == '1') {add();menu();} //����ͨѶ¼��Ϣ
        if(control == '2') if(del()){menu();} //ɾ��ͨѶ¼��Ϣ
        if(control == '3') if(change()){menu();} //�޸�ͨѶ¼��Ϣ
        if(control == '4') if(find()){menu();} //����ͨѶ¼��Ϣ
        if(control == '5') if(rea()){menu();} //��ȡ������Ϣ
        if(control == ESC) break; //�˳�����
    }
    return 0;
}


