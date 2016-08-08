#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
int n,m;
using namespace std;
class msg
{
public:
	msg();//Ĭ�Ϲ��캯��
	char inter_face();//��ҳ
	void add_person();//�����ϵ��
	void del_person();//ɾ����ϵ��
	void show_all();//��ʾ������ϵ��
	void alter();//�޸���Ϣ
	void select();//��ѯ��ϵ��
	void save_new();//���������ӵ���ϵ��
private:
    string name;//����
	string sex;//�Ա�
	string num;//�绰����
	string ad;//��ַ	
	string rl;//����
};
msg::msg()
{
	name = "\0";
	ad = "\0";
	num = "\0";
	sex = "\0";
	rl = "\0";
}
//��ҳ
char msg::inter_face()
{
	cout <<endl;
	cout<<"\t\t***********************************************" <<endl
		<<"\t\t��                                           ��" <<endl
		<<"\t\t��                ͨ    Ѹ   ¼              ��" <<endl 
		<<"\t\t��                                           ��" <<endl
		<<"\t\t��   1. �������ϵ��.    4. �޸���Ϣ.        ��" <<endl 
		<<"\t\t��                                           ��" <<endl
		<<"\t\t��   2. ɾ����ϵ��.      5. ��ѯ��ϵ��.      ��" <<endl
		<<"\t\t��                                           ��" <<endl
		<<"\t\t��   3.��ʾ������ϵ��.   0. �ر�ͨѸ¼.      ��" <<endl 
		<<"\t\t��                                           ��" <<endl
		<<"\t\t*****************************************"<<endl <<endl
		<<"\t\t\tѡ��:" ;
	char choose;
	cin >>choose;
	return choose;
}
//�����ϵ��
void msg::add_person()
{
	cout <<endl <<"����������ʾ��������ϵ����Ϣ" <<endl <<endl
		<<"����:" ;
	cin >>name;
	cout <<"�绰: ";
	cin >>num;	
	cout <<"���� : ";
	cin >>rl;	
	cout <<"�Ա�: ";
	cin >>sex;	
	cout <<"��ַ: ";
	cin >>ad;
	

	save_new();

	cout <<endl <<endl <<"����ϵ����Ϣ�Ѿ������!!!!!" <<endl ;
}

//ɾ����ϵ��
void msg::del_person()
{
	ofstream outData("temp.txt", ios::out);
	ifstream inData("pbook.txt", ios::in); //
	if (!outData || !inData)
	{
		cout <<endl <<"�Բ���!!!!�Ҳ����ļ�!!!!" <<endl;
		system("pause");
		return;
	}
	string sign;
	cout <<endl <<"��Ҫɾ������������绰��:";
	cin >>sign;
	string str1;
	bool flag = true;
	string str;
	while (inData >>name >>num)
	{
		getline(inData, str);

		if ((sign==name) || (sign==num))
		{
			cout <<endl <<"����ɾ������ϵ��:" <<endl <<endl;
			cout <<str1 <<endl;
			cout <<setiosflags(ios::left) <<setw(17) <<name
				<<" " <<num <<str <<endl;
			flag = false;
			break;
		}
		outData <<setiosflags(ios::left) <<setw(17) <<name
			<<" " <<num <<str <<endl;
	}
	if (flag)
	{
		cout <<endl <<"�Բ���!!!��ϵ����û���ҵ���!!!!" <<endl <<endl;
	}
	else
	{
		while (getline(inData, str))
		{
			outData <<str <<endl;
		}
		outData.close();
		inData.close();
		ofstream out("pbook.txt", ios::out);
		ifstream in("temp.txt", ios::in);
		if (!out || !in)
		{
			cout <<endl <<"�Բ����ܴ��ļ�!!!" <<endl <<endl;
			return;
		}
		while (getline(in, str))
		{
			out <<str <<endl;
		}
		out.close();//
		in.close();
		cout <<endl <<"����˵���Ϣ�Ѿ������ͨѸ¼��ɾ��!!!" <<endl <<endl;
	}  
}

//��ʾ������ϵ��
void msg::show_all()
{
	ifstream inData("pbook.txt",ios::in);
	if (!inData)
	{
		cout <<endl <<"�Բ���!!!!û���ҵ��ļ�!!!!!" <<endl;
		return;
	}
	bool flag = true;
	string record;
	while (getline(inData, record))
	{
		if (flag)
		{
			cout <<endl <<"������ϵ����Ϣ����: "<<endl;
			cout<<"����"<<setw(18)<<"�绰"<<setw(15)<<"�Ա�"<<setw(21)<<"����"<<setw(15)<<"��ַ"<<endl;
		}
		
		cout <<record <<endl;
		flag = false;
	}
	if (flag)
	{
		cout <<endl <<"���ͨѸ¼��û����ϵ��!!!!!" <<endl <<endl;
	}
	else
	{
		cout <<endl <<"������ϵ���Ѿ�ȫ����ʾ����!!!!!" <<endl <<endl;
	}
}
//�޸���Ϣ
void msg::alter()
{
	ofstream outData("temp.txt", ios::out);
	ifstream inData("pbook.txt", ios::in); //
	if (!outData || !inData)
	{
		cout <<endl <<"�Բ���!!!!�Ҳ����ļ�!!!!" <<endl;
		return;
	}
	string sign;
	cout <<endl <<"��Ҫ�޸�����������绰��:";
	cin >>sign;
	string str1;
	bool flag = true;
	string str;
	while (inData >>name >>num)
	{
		getline(inData, str);
		if ((sign==name) || (sign==num))
		{
			cout <<endl <<"�����޸ĵ���ϵ��:" <<endl <<endl;
			cout <<str1 <<endl;
			cout <<setiosflags(ios::left) <<setw(17) <<name
				<<" " <<num <<str <<endl;
			cout <<endl <<"�����������ʾ�޸���Ϣ: " <<endl;
			cout <<"���� :" ;
			cin >>name;
			fflush(stdin);
			cout <<"�绰��:";
			cin >>num;
			fflush(stdin);
			cout <<"�Ա� :";
			cin >>sex;
			fflush(stdin);
			cout <<"���� :";
			cin >>rl;
			fflush(stdin);
			cout <<"��ַ :";
			cin >>ad;
			fflush(stdin);
			save_new();
			flag = false;
			break;
		}
		outData <<setiosflags(ios::left) <<setw(17) <<name
			<<" " <<num <<str <<endl;
	}
	if (flag)
	{
		cout <<endl <<"�Բ���!!!��ϵ����û���ҵ���!!!!" <<endl <<endl;
	}
	else
	{
		while (getline(inData, str))
		{
			outData <<str <<endl;
		}

		outData.close();
		inData.close();
		ofstream out("pbook.txt", ios::out);
		ifstream in("temp.txt", ios::in);
		if (!out || !in)
		{
			cout <<endl <<"�Բ����ܴ��ļ�!!!" <<endl <<endl;
			system("pause");
			return;
		}
		while (getline(in, str))
		{
			out <<str <<endl;
		}
		out.close();
		in.close();
		cout <<endl <<"����˵���Ϣ�Ѿ������ͨѸ¼���޸�!!!" <<endl <<endl;
	}
}
//��ѯ��ϵ��
void msg::select()
{
	ifstream inData("pbook.txt",ios::in);
	if (!inData)
	{
		cout <<endl <<"�Բ���!!!!�ļ��Ҳ���!!!!" <<endl;
		system("pause");
		return;
	}
	string sign;
	cout <<endl <<"����������ҵ���ϵ�˵�������绰����: ";
	cin >>sign;
	fflush(stdin);
	string str1;
	bool flag = true;
	string str;
	while (inData >>name >>num)
	{
		getline(inData, str);

		if ((name==sign) || (num==sign))
		{
			cout <<endl <<"��Ҫ���ҵ���ϵ����: " <<endl <<endl;
			cout <<str1 <<endl;
			cout <<setiosflags(ios::left) <<setw(17) <<name
				<<num <<str <<endl;
			flag = false;
			system("pause");
			break;
		}
	}
}
void msg::save_new()
{
	ofstream outData("pbook.txt", ios::app);

	if (!outData)
	{
		cout <<endl <<"�Բ���!!!���ļ�ʧ��!!!!" <<endl <<endl;
		system("pause");
		return;
	}
	outData << setiosflags(ios::left) << setw(17) << name
		<<" " << setw(16) << num <<" "
		<< setw(18) << sex <<" "
		<< setw(14) <<rl <<" "
		<< setw(20) << ad <<endl;
	outData.close();
}
void main()
{
	msg abj;
	do{
		cout <<endl;
	cout<<"\t\t***********************************************" <<endl
		<<"\t\t��                                           ��" <<endl
		<<"\t\t��                ͨ    Ѹ   ¼              ��" <<endl 
		<<"\t\t��                                           ��" <<endl
		<<"\t\t��   1. �������ϵ��.    4. �޸���Ϣ.        ��" <<endl 
		<<"\t\t��                                           ��" <<endl
		<<"\t\t��  2. ɾ����ϵ��.       5. ��ѯ��ϵ��.      ��" <<endl
		<<"\t\t��                                           ��" <<endl
		<<"\t\t��  3. ��ʾ������ϵ��.   0. �˳�ͨѸ¼.      ��" <<endl 
		<<"\t\t��                                           ��" <<endl
		<<"\t\t*****************************************"<<endl <<endl
		<<"\t\t\tѡ������Ҫ�Ĺ���:" ;
cin>>n;
       switch(n)
	   {
		case 1:
			abj.add_person();////�����ϵ��
			break;
		case 2:
			abj.del_person();////ɾ����ϵ��
			break;
		case 3:
			abj.show_all();////��ʾ������ϵ��
			break;
		case 4:
			abj.alter();////�޸���Ϣ
			break;
		case 5:
			abj.select();////��ѯ��ϵ��
			break;
		default:
			break;
		}
cout<<"\n ����1: ����;     ����0: �˳�\n";
cin>>m;
}
while(m==1);
}