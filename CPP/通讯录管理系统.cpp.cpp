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
	msg();//默认构造函数
	char inter_face();//首页
	void add_person();//添加联系人
	void del_person();//删除联系人
	void show_all();//显示所有联系人
	void alter();//修改信息
	void select();//查询联系人
	void save_new();//保存新增加的联系人
private:
    string name;//姓名
	string sex;//性别
	string num;//电话号码
	string ad;//地址	
	string rl;//类型
};
msg::msg()
{
	name = "\0";
	ad = "\0";
	num = "\0";
	sex = "\0";
	rl = "\0";
}
//首页
char msg::inter_face()
{
	cout <<endl;
	cout<<"\t\t***********************************************" <<endl
		<<"\t\t※                                           ※" <<endl
		<<"\t\t※                通    迅   录              ※" <<endl 
		<<"\t\t※                                           ※" <<endl
		<<"\t\t※   1. 添加新联系人.    4. 修改信息.        ※" <<endl 
		<<"\t\t※                                           ※" <<endl
		<<"\t\t※   2. 删除联系人.      5. 查询联系人.      ※" <<endl
		<<"\t\t※                                           ※" <<endl
		<<"\t\t※   3.显示所有联系人.   0. 关闭通迅录.      ※" <<endl 
		<<"\t\t※                                           ※" <<endl
		<<"\t\t*****************************************"<<endl <<endl
		<<"\t\t\t选择:" ;
	char choose;
	cin >>choose;
	return choose;
}
//添加联系人
void msg::add_person()
{
	cout <<endl <<"根据下面提示输入新联系人信息" <<endl <<endl
		<<"姓名:" ;
	cin >>name;
	cout <<"电话: ";
	cin >>num;	
	cout <<"类型 : ";
	cin >>rl;	
	cout <<"性别: ";
	cin >>sex;	
	cout <<"地址: ";
	cin >>ad;
	

	save_new();

	cout <<endl <<endl <<"新联系人信息已经保存好!!!!!" <<endl ;
}

//删除联系人
void msg::del_person()
{
	ofstream outData("temp.txt", ios::out);
	ifstream inData("pbook.txt", ios::in); //
	if (!outData || !inData)
	{
		cout <<endl <<"对不起!!!!找不到文件!!!!" <<endl;
		system("pause");
		return;
	}
	string sign;
	cout <<endl <<"你要删除输入姓名或电话号:";
	cin >>sign;
	string str1;
	bool flag = true;
	string str;
	while (inData >>name >>num)
	{
		getline(inData, str);

		if ((sign==name) || (sign==num))
		{
			cout <<endl <<"你想删除的联系人:" <<endl <<endl;
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
		cout <<endl <<"对不起!!!联系人中没你找的人!!!!" <<endl <<endl;
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
			cout <<endl <<"对不起不能打开文件!!!" <<endl <<endl;
			return;
		}
		while (getline(in, str))
		{
			out <<str <<endl;
		}
		out.close();//
		in.close();
		cout <<endl <<"这个人的信息已经从你的通迅录中删除!!!" <<endl <<endl;
	}  
}

//显示所有联系人
void msg::show_all()
{
	ifstream inData("pbook.txt",ios::in);
	if (!inData)
	{
		cout <<endl <<"对不起!!!!没有找到文件!!!!!" <<endl;
		return;
	}
	bool flag = true;
	string record;
	while (getline(inData, record))
	{
		if (flag)
		{
			cout <<endl <<"所有联系人信息如下: "<<endl;
			cout<<"姓名"<<setw(18)<<"电话"<<setw(15)<<"性别"<<setw(21)<<"类型"<<setw(15)<<"地址"<<endl;
		}
		
		cout <<record <<endl;
		flag = false;
	}
	if (flag)
	{
		cout <<endl <<"你的通迅录中没有联系人!!!!!" <<endl <<endl;
	}
	else
	{
		cout <<endl <<"所有联系人已经全部显示出来!!!!!" <<endl <<endl;
	}
}
//修改信息
void msg::alter()
{
	ofstream outData("temp.txt", ios::out);
	ifstream inData("pbook.txt", ios::in); //
	if (!outData || !inData)
	{
		cout <<endl <<"对不起!!!!找不到文件!!!!" <<endl;
		return;
	}
	string sign;
	cout <<endl <<"你要修改输入姓名或电话号:";
	cin >>sign;
	string str1;
	bool flag = true;
	string str;
	while (inData >>name >>num)
	{
		getline(inData, str);
		if ((sign==name) || (sign==num))
		{
			cout <<endl <<"你想修改的联系人:" <<endl <<endl;
			cout <<str1 <<endl;
			cout <<setiosflags(ios::left) <<setw(17) <<name
				<<" " <<num <<str <<endl;
			cout <<endl <<"请根据下面提示修改信息: " <<endl;
			cout <<"姓名 :" ;
			cin >>name;
			fflush(stdin);
			cout <<"电话号:";
			cin >>num;
			fflush(stdin);
			cout <<"性别 :";
			cin >>sex;
			fflush(stdin);
			cout <<"类型 :";
			cin >>rl;
			fflush(stdin);
			cout <<"地址 :";
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
		cout <<endl <<"对不起!!!联系人中没你找的人!!!!" <<endl <<endl;
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
			cout <<endl <<"对不起不能打开文件!!!" <<endl <<endl;
			system("pause");
			return;
		}
		while (getline(in, str))
		{
			out <<str <<endl;
		}
		out.close();
		in.close();
		cout <<endl <<"这个人的信息已经在你的通迅录中修改!!!" <<endl <<endl;
	}
}
//查询联系人
void msg::select()
{
	ifstream inData("pbook.txt",ios::in);
	if (!inData)
	{
		cout <<endl <<"对不起!!!!文件找不到!!!!" <<endl;
		system("pause");
		return;
	}
	string sign;
	cout <<endl <<"输入你想查找的联系人的姓名或电话号码: ";
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
			cout <<endl <<"你要查找的联系人是: " <<endl <<endl;
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
		cout <<endl <<"对不起!!!打开文件失败!!!!" <<endl <<endl;
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
		<<"\t\t※                                           ※" <<endl
		<<"\t\t※                通    迅   录              ※" <<endl 
		<<"\t\t※                                           ※" <<endl
		<<"\t\t※   1. 添加新联系人.    4. 修改信息.        ※" <<endl 
		<<"\t\t※                                           ※" <<endl
		<<"\t\t※  2. 删除联系人.       5. 查询联系人.      ※" <<endl
		<<"\t\t※                                           ※" <<endl
		<<"\t\t※  3. 显示所有联系人.   0. 退出通迅录.      ※" <<endl 
		<<"\t\t※                                           ※" <<endl
		<<"\t\t*****************************************"<<endl <<endl
		<<"\t\t\t选择你需要的功能:" ;
cin>>n;
       switch(n)
	   {
		case 1:
			abj.add_person();////添加联系人
			break;
		case 2:
			abj.del_person();////删除联系人
			break;
		case 3:
			abj.show_all();////显示所有联系人
			break;
		case 4:
			abj.alter();////修改信息
			break;
		case 5:
			abj.select();////查询联系人
			break;
		default:
			break;
		}
cout<<"\n 输入1: 继续;     输入0: 退出\n";
cin>>m;
}
while(m==1);
}