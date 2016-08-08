/*************************************************************************/
//
//               酒店客房管理
//
//**************************************软工10班~17号~高青波*************/
 
#include<iostream>
#include <string>
#include <fstream>
using namespace std;
// const int maxb=30;

class Customer				//基类 
{
public:
	string name;
	string ID;
	int money;
	int StayTiem;
	Customer(){};
};

class HotelRoom:public Customer
{
public:
	int num;
	string Price;
	string Type;
	
	HotelRoom()			//房间信息初始化
	{
		num=0;
		Price='0';
		Type="null";
		money=0;
		StayTiem=0;
		name="无";
		ID="0";
	};
	
	~HotelRoom(){};
	
};
/*******************************************************************************/

ofstream Str("客房信息.txt",ios_base::trunc); //定义输出文件流对象 Str，并且在读写前将文件长度截断为0

ofstream C("客户信息.txt",ios_base::trunc);	//定义输出流对象C 


void set_CustomerInfo(HotelRoom *Room);			//设置顾客信息
void set_HotelRoomInfo(HotelRoom *Room);		//设置客房信息
void Find_HotelRoom_num(HotelRoom *Room);			//按房号查找
void Display_HotelRoomInfo(HotelRoom *Room);		//显示房间信息 
void add_HotelRoomInfo(HotelRoom *Room);				//添加房间信息
void Find_HotelRoom_name(HotelRoom *Room);					//按名字查找
void Find_HotelRoom_Type(HotelRoom *Room);				//按类型查找
void PrintAll(HotelRoom *Room);


void Change_HotelRoomInfo(HotelRoom *Room);			//更新换间 
void Set_Count(HotelRoom *Room);				//客户退房 
void Delete_HotelRoom(HotelRoom *Room);				//删除房间信息 
void Find_Choose(HotelRoom *Room);				// 
void Save_HotelRoomeInfo(HotelRoom *Room);		//保存房间信息 
void Save_CustomerInfo(HotelRoom *Room);		//保存顾客信息 

void Write(HotelRoom *Room);			//信息写入 
void Read(HotelRoom *Room);				//信息读出 
/*********************************************************************/
//          各函数功能的实现  
/********************************************************************/  

void Save_HotelRoomeInfo(HotelRoom *Room)			
{

	for (int i=0;i<30;i++)
	{
		if (Room[i].num!=0)					
		{
			Str<<"房间号码："<<Room[i].num<<"\t"<<"房间类型："<<"\t"
				<<Room[i].Type<<"\t"<<"房间价格："<<"\t"
				<<Room[i].Price<<endl<<endl;
		};
	};
};

void Save_CustomerInfo(HotelRoom *Room)
{
	for (int i=0;i<30;i++)
	{
		if (Room[i].num!=0 && Room[i].name!="无")
		{
			C<<"房间类型：";
			C<<Room[i].Type<<endl;
			C<<"房间价格：";
			C<<Room[i].Price<<endl;
			C<<"客户身份证号码："<<endl;
			C<<Room[i].ID<<endl;
			C<<"客户姓名:";
			C<<Room[i].name<<endl;
			C<<"定金：";
			C<<Room[i].money<<endl;
			C<<"入住天数：";
			C<<Room[i].StayTiem;
			C<<"天"<<endl<<endl;
		};
	};
};

void Display_HotelRoomInfo(HotelRoom *Room)
{
	int t=0;
	for (int i=0;i<30;i++)
	{
		if (Room[i].StayTiem==0 && Room[i].num!=0)
		{
			cout<<"房间号码：";
			cout<<Room[i].num<<"\t";
			cout<<"房间类型：";
			cout<<Room[i].Type<<"\t";
			cout<<"房间价格：";
			cout<<Room[i].Price<<endl;
			t++;
		}
		else if(t==0 && i==29)
			cout<<"暂无空房！";
	};
	system("pause");
	system("cls");
};

void Find_Choose(HotelRoom *Room)					//客房查找功能实现 
{

int P=0;

while(P==0)

{

cout<<"\n\n 客房管理系统 \n\n"; cout<<" ---------------------------------- \n\n"; 

cout<<" 1.通过房号查询客房 \n\n";

cout<<" 2.通过类型查询客房 \n\n";

cout<<" 3.通过客户姓名查询客房\n\n";

cout<<" 4.查询所有空房\n\n";

cout<<" 5.返回主菜单 \n\n";

cout<<" 请选择：";

int choose=0;

cin>>choose;   
system("cls");
switch (choose) 			//选择
{

case 1:Find_HotelRoom_num(Room); break; //房信息

case 2:Find_HotelRoom_Type(Room);break; //客人入住登记

case 3:Find_HotelRoom_name(Room); break; //信息

case 4:Display_HotelRoomInfo(Room);break; //客户退房

case 5: P=5;   break;

default :; break;

}

};

};

void Delete_HotelRoom(HotelRoom *Room)		//删除客房信息的实现 
{
	int Num;
	cout<<"请输入要删除的房间号：";
	cin>>Num;
	for(int i=0;i<30;i++)
	{
		if(Room[i].num=Num)
		{
			string B;
			cout<<"房间已找到:"<<endl;
			cout<<"房间类型";
			cout<<Room[i].Type<<endl;
			cout<<"房间价格："; 
			cout<<Room[i].Price<<endl;
			cout<<"客户信息如下：";
			cout<<"客户身份证号码：";
			cout<<Room[i].ID<<endl;
			cout<<"客户姓名："; 
			cout<<Room[i].name<<endl;
			cout<<"客户定金：";
			cout<<Room[i].money<<endl;
			cout<<"确定要删除客房信息？（Y/N）"; 
			cin>>B;
			cout<<endl;
			if(B=="Y")
			{
				Room[i].Type="null";
				Room[i].num=0;
				Room[i].Price="0";
				
				Room[i].money=0;
				Room[i].StayTiem=0;
				Room[i].name="无";
				Room[i].ID="0";
				
				cout<<"删除成功！"<<endl;	
			} 
			else if(B=="N")
			{
				cout<<"删除取消！"<<endl;
			}
			else cout<<"无效的操作!"<<endl;
		};
		
	  }
		system("pause");		//调用“pause”命令 
		system("cls");			//清楚屏幕 
};

void Set_Count(HotelRoom *Room)			// 用户退房 
{
	int Num;
	int t=0;
	cout<<"请输入房间号码：";
	cin>>Num;
	for(int i=0;i<30;i++)
	{
		if(Num==Room[i].num && Room[i].StayTiem!=0)
		{
			string B;
			cout<<"房间已找到:"<<endl;
			cout<<"房间类型";
			cout<<Room[i].Type<<endl;
			cout<<"房间价格："; 
			cout<<Room[i].Price<<endl;
			cout<<"客户信息如下：";
			cout<<"客户身份证号码：";
			cout<<Room[i].ID<<endl;
			cout<<"客户姓名："; 
			cout<<Room[i].name<<endl;
			cout<<"客户定金：";
			cout<<Room[i].money<<endl;
			cout<<"入住天数：";
			cout<<Room[i].StayTiem<<"天。"<<endl<<endl;
			cout<<"请确定是否要退房（Y/N）"<<endl;
			cin>>B;
			if(B=="Y")
			{
				Room[i].StayTiem=0;
				Room[i].money=0;
				Room[i].name="无";
				Room[i].ID="0";
				
				cout<<"退房成功！"<<endl; 
			}
			else if(B=="N")
			{
				cout<<"取消退房。"<<endl; 
			}
			else if(Num==Room[i].num && Room[i].StayTiem==0)
			{
				cout<<"此房为空房。";
				t++; 
			}
			else if(t==0 && i==29 && Room[i].Type=="null")
		 	cout<<"查无此房！"<<endl; 
		};
	} 
	system("pause");
	system("cls");
};

void add_HotelRoomInfo(HotelRoom *Room)		//添加客房
{
	static int Number=700;
	string P;
	do
	{
		int Number=700;
		for(int i=0;i<30;i++)
		{
			if(Room[i].num==0)
			{
				Room[i].num=Number++;
				cout<<"房间号码："<<Room[i].num;
				cout<<endl;
				cout<<"房间类型";
				cin>>Room[i].Type;
				cout<<endl;
				cout<<"房间价格：";
				cin>>Room[i].Price;
				cout<<endl<<endl;
								 
				cout<<"房间添加成功，是否继续?(Y/N)";
				cin>>P;
				break; 
			}
			else Number++;
		};
	}
	while(P=="Y");
	if(P=="N")
	cout<<"已取消添加。";
	else cout<<"无效的操作！"<<endl<<endl; 
};

void set_HotelRoomInfo(HotelRoom *Room)			//设置客房信息 
{
	if(Room[0].num==0)
	{
		int size;
		cout<<"暂无该房间信息，请添加！"<<endl;
		static int Number=700;
		cout<<"请输入要添加的房间数：";
		cin>>size;
		for(int i=0;i<size;i++)
		{
			Room[i].num=Number++;
			cout<<"房间号码："<<Room[i].num;
			cout<<endl; cout<<"房间类型：";
			cin>>Room[i].Type;
			cout<<"房间价格：";
			cin>>Room[i].Price;
			cout<<endl<<endl;
		} ;
		cout<<"客房信息录入成功!"<<endl<<endl;
	}	
	else
 	{
	string P;
	cout<<"客房信息已有，是否要添加房间？（Y/N）"; cin>>P;
	if(P=="Y")
	add_HotelRoomInfo(Room);
	else if(P=="N")
	cout<<"已取消房间添加."<<endl<<endl;
	else cout<<"无效的操作！"<<endl<<endl;
	};
	system("pause");
	system("cls");
};
 
 void set_CustomerInfo(HotelRoom *Room)			//设置顾客信息 
 {
 	int Num;
	int t=0;
	cout<<"输入房间号码：";
	cin>>Num;
	for(int i=0;i<30;i++)
	{
	if(Num==Room[i].num && Room[i].StayTiem==0)
	{
	cout<<"房间已找到："<<endl;
	cout<<"房间类型:";
	cout<<Room[i].Type<<endl;
	cout<<"房间价格:";
	cout<<Room[i].Price<<endl;
	cout<<"请输入客户信息！"<<endl;
	cout<<"是否确定要订房？（Y/N）";
	string p;
	cin>>p;
		if(p=="Y")
		{
		cout<<"客户身份证号码:";
		cin>>Room[i].ID;
		cout<<"客户姓名：";
		cin>>Room[i].name;
		cout<<"订金:";
		cin>>Room[i].money;
		cout<<"入住天数：";
		cin>>Room[i].StayTiem;cout<<"天"; 
		cout<<endl;
		cout<<"信息录入成功!"<<endl;
		}
		else if(p=="N") cout<<"订房已取消。";
    	else cout<<"无效的操作！";
    	t++;
 	}
 	else if(Num==Room[i].num && Room[i].StayTiem!=0)
 	{
	 	cout<<"此房已住";
		t++;
	}
	else if(t==0 && i==29)
	cout<<"查无此房";
 	};
 	system("pause");
	system("cls");
};

void Find_HotelRoom_num(HotelRoom *Room)		//按房号查询 
{
	int Num; int t=0; 
	cout<<"输入要查找的房间号码：";
	cin>>Num;
	for(int i=0;i<30;i++)
	{
		if(Num==Room[i].num && Room[i].StayTiem!=0)
		{
			cout<<"房间类型:"; 
			  cout<<Room[i].Type<<endl;
			cout<<"房间价格:"; 
			  cout<<Room[i].Price<<endl;
  			cout<<"客户姓名："; 
			  cout<<Room[i].name;
			cout<<endl; 
			cout<<"客户身份证号码:"; 
			  cout<<Room[i].ID;cout<<endl;
		    cout<<"订金:"; 
			cout<<Room[i].money;
			cout<<endl<<endl; 
			cout<<"此房已住，";
		    cout<<Room[i].StayTiem<<"天后退房！";
		    cout<<endl<<endl<<endl;
		    t++;
		}
		else if(Num==Room[i].num && Room[i].StayTiem==0)
		{
			cout<<"房间类型:";
			 cout<<Room[i].Type<<endl;
		    cout<<"房间价格:"; 
			  cout<<Room[i].Price<<endl;
		    cout<<"客户姓名："; 
			  cout<<Room[i].name;cout<<endl;
		    cout<<"客户身份证号码:";
			  cout<<Room[i].ID;cout<<endl; 
		    cout<<"订金;";
			  cout<<Room[i].money;
		    cout<<endl<<endl; 
			t++;
		}
		else if(t==0 && i==29 && Room[i].Type=="null")
		cout<<"查无此房"<<endl<<endl;		
	};
	system("pause");
	system("cls");
};

void Find_HotelRoom_name(HotelRoom *Room)	// 按客户名查询 
{
	int t=0;
	string Name;
	cout<<"输入客户姓名：";
	cin>>Name;
	for(int i=0;i<30;i++)
	{
		if(Name==Room[i].name && Room[i].StayTiem!=0)
		{
			cout<<"房间类型:";
			cout<<Room[i].Type<<endl;
			cout<<"房间价格:";
			cout<<Room[i].Price<<endl;
			cout<<"客户姓名：";
			cout<<Room[i].name;cout<<endl;
			cout<<"客户身份证号码:";
			cout<<Room[i].ID;cout<<endl;
			cout<<"订金:";
			cout<<Room[i].money;
			cout<<endl<<endl;
			cout<<"此房已住，";
			cout<<Room[i].StayTiem<<"天后退房！";
		 	cout<<endl<<endl<<endl;
			t++;
		}
		else if(Name==Room[i].name && Room[i].StayTiem==0)
	 	{
 			cout<<"房间类型:";
			cout<<Room[i].Type<<endl;
			cout<<"房间价格:";
			cout<<Room[i].Price<<endl;
			cout<<"客户姓名：";
			cout<<Room[i].name;cout<<endl;
			cout<<"客户身份证号码:";
			cout<<Room[i].ID;cout<<endl;
			cout<<"订金:";
			cout<<Room[i].money;
			cout<<endl<<endl;
			t++;
 		}
 		else if(t==0 && i==29)
 		cout<<"查询不到此客户。"<<endl<<endl;
	};
	system("pause");
	system("cls");
};

void Find_HotelRoom_Type(HotelRoom *Room)		//按房类型查询 
{
	int t=0;
	string type;
	cout<<"输入房间类型：";
	cin>>type;
	for(int i=0;i<30;i++)
	{
		if(type==Room[i].Type && Room[i].StayTiem!=0)
		{
			cout<<"房间类型:";
			cout<<Room[i].Type<<endl;
			cout<<"房间价格:";
			cout<<Room[i].Price<<endl;
			cout<<"客户姓名：";
			cout<<Room[i].name;cout<<endl;
			cout<<"客户身份证号码:";
			cout<<Room[i].ID;cout<<endl;
			cout<<"订金:";
			cout<<Room[i].money;cout<<endl<<endl;
			cout<<"此房已住，";
			cout<<Room[i].StayTiem<<"天后退房！";
			cout<<endl<<endl<<endl;
			t++;
		}
		else if(type==Room[i].Type && Room[i].StayTiem==0)
		{
			cout<<"房间类型:";
			cout<<Room[i].Type<<endl;
			cout<<"房间价格:";
			cout<<Room[i].Price<<endl;
			cout<<"客户姓名：";
			cout<<Room[i].name;cout<<endl;
			cout<<"客户身份证号码:";
			cout<<Room[i].ID;cout<<endl;
			cout<<"订金:";
			cout<<Room[i].money;cout<<endl<<endl;
			t++;
		}
		else if(t==0 && i==29)
		cout<<"暂无此类房间。"<<endl<<endl;
	};
	system("pause");
	system("cls");
};

void PrintAll(HotelRoom *Room)			//显示所有信息 
{
	int t=0;
	for(int i=0;i<30;i++)
	{
		if(Room[i].Type!="null")
		{
			cout<<"房间类型:"<<Room[i].Type<<"\t";
			cout<<"房间号:"<<Room[i].num<<"\t";
			cout<<"价格:"<<Room[i].Price<<endl;
			
			cout<<"客户姓名："<<Room[i].name<<"\t";
			cout<<"客户身份证号码："<<Room[i].ID<<"\t";
			cout<<"订金："<<Room[i].money<<endl;
			cout<<"将于"<<Room[i].StayTiem<<"天后退房。";
			cout<<endl<<endl<<endl;	
			
			t++;
		}
		if(t==0 && i==29) 
		cout<<"暂无任何客房信息!"<<endl<<endl;
	};
	system("pause");
	system("cls");
};

void Change_HotelRoomInfo(HotelRoom  *Room)		//修改信息 
{
	int Num;
	cout<<"请输入要修改的房间号码:"<<endl;
	cin>>Num;
	string _name;
	string _ID;
	int _money;
	int _StayTime;
	string _Price;
	string _Type;
	int t=0;
	for(int i=0;i<30;i++)
	{
		if(Num==Room[i].num)
		{
			cout<<"房间类型:";
			cout<<Room[i].Type<<endl;
			cout<<"房间价格:";
			cout<<Room[i].Price<<endl;
			cout<<"客户姓名：";
			cout<<Room[i].name;cout<<endl;
			cout<<"客户身份证号码:";
			cout<<Room[i].ID;cout<<endl;
			cout<<"订金:";
			cout<<Room[i].money;
			cout<<"将于"<<Room[i].StayTiem<<"天后退房。"<<endl;
			cout<<"房间信息已找到!"<<endl;
			cout<<"是否确定要修改房间信息？（Y/N）";
			string p;
			cin>>p;
			if(p=="Y")
			{
				cout<<"客户姓名：";
				cin>>_name;
				Room[i].name=_name;
				cout<<endl;
				cout<<"客户身份证号码:";
				cin>>_ID;
				Room[i].ID=_ID;
				cout<<endl;
				cout<<"订金:";
				cin>>_money;
				Room[i].money=_money;
				cout<<"退房时间延长至";cin>>_StayTime;cout<<"天后";
				Room[i].StayTiem=_StayTime;
				cout<<endl;
				Save_CustomerInfo(Room);
				cout<<"修改成功!"<<endl<<endl;
			}
			else if(p=="N") cout<<"已取消修改。";
			else cout<<"无效的操作！";
			t++; 
		}
		else if(t==0 && i==29 && Room[i].Type=="null")
		cout<<"查无此房！"<<endl<<endl;
	};
	system("pause");
	system("cls");
};

void Write(HotelRoom *Room)				//写入文件 
{
	fstream file("Room.txt",ios::out);
	for (int i=0;i<=30;i++)
	if (Room[i].Type!="null")
	file.write((char *)&Room[i],sizeof(Room[i]));
	file.close();
};

void Read(HotelRoom *Room)			//读出文件 
{
	int top;
	HotelRoom b;
	top=-1;
	fstream file("Room.txt",ios::in);
	while (1)
	{
		file.read((char *)&b,sizeof(b));
		if (!file) break;
		top++;
		Room[top]=b;
	}
	file.close();
};

/*******************************************************************************/

int main()
{
	HotelRoom Room[200];
	Read(Room);
	while(1)
	{												//主界面设置
	 
	cout<<"\n\n                     客房管理系统          \n\n"; 
	cout<<" ------------------------------------------------------------- \n\n";
	cout<<" 1.客房信息的录入 \n\n"; 
	cout<<" 2.客人入住登记 \n\n"; 
	cout<<" 3.客房信息的修改 \n\n"; 
	cout<<" 4.客人退房结算 \n\n"; 
	cout<<" 5.查询所有客房信息 \n\n"; 
	cout<<" 6.查询方式 \n\n";
	cout<<" 7.删除客房信息 \n\n"; 
	cout<<" 8.退 出 系 统 \n\n";
	cout<<"***************************************************************"<<endl ; 
	cout<<"      请选择：";
	
	int choose=0;
	cin>>choose;
	system("cls");
	switch (choose) 
	{
		case 1:set_HotelRoomInfo(Room); break; 			//输入客房信息
		case 2:set_CustomerInfo(Room);break; 		//客人入住登记
		case 3:Change_HotelRoomInfo(Room); break; 	//修改客房信息
		case 4:Set_Count(Room);break; 			//客户退房
		case 5:PrintAll(Room); break; 			//查询所有客房信息
	    case 6:Find_Choose(Room); break; 		//查询
	    case 7:Delete_HotelRoom(Room);break; 		//删除客房信息
	    case 8:Write(Room);
	    
	    						//保存信息 
	    Save_HotelRoomeInfo(Room);
		Save_CustomerInfo(Room);
		exit(0);    //退出 default : break;
	}	
		
	}
	return 0;
}



