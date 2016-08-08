/*************************************************************************/
//
//               �Ƶ�ͷ�����
//
//**************************************��10��~17��~���ನ*************/
 
#include<iostream>
#include <string>
#include <fstream>
using namespace std;
// const int maxb=30;

class Customer				//���� 
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
	
	HotelRoom()			//������Ϣ��ʼ��
	{
		num=0;
		Price='0';
		Type="null";
		money=0;
		StayTiem=0;
		name="��";
		ID="0";
	};
	
	~HotelRoom(){};
	
};
/*******************************************************************************/

ofstream Str("�ͷ���Ϣ.txt",ios_base::trunc); //��������ļ������� Str�������ڶ�дǰ���ļ����Ƚض�Ϊ0

ofstream C("�ͻ���Ϣ.txt",ios_base::trunc);	//�������������C 


void set_CustomerInfo(HotelRoom *Room);			//���ù˿���Ϣ
void set_HotelRoomInfo(HotelRoom *Room);		//���ÿͷ���Ϣ
void Find_HotelRoom_num(HotelRoom *Room);			//�����Ų���
void Display_HotelRoomInfo(HotelRoom *Room);		//��ʾ������Ϣ 
void add_HotelRoomInfo(HotelRoom *Room);				//��ӷ�����Ϣ
void Find_HotelRoom_name(HotelRoom *Room);					//�����ֲ���
void Find_HotelRoom_Type(HotelRoom *Room);				//�����Ͳ���
void PrintAll(HotelRoom *Room);


void Change_HotelRoomInfo(HotelRoom *Room);			//���»��� 
void Set_Count(HotelRoom *Room);				//�ͻ��˷� 
void Delete_HotelRoom(HotelRoom *Room);				//ɾ��������Ϣ 
void Find_Choose(HotelRoom *Room);				// 
void Save_HotelRoomeInfo(HotelRoom *Room);		//���淿����Ϣ 
void Save_CustomerInfo(HotelRoom *Room);		//����˿���Ϣ 

void Write(HotelRoom *Room);			//��Ϣд�� 
void Read(HotelRoom *Room);				//��Ϣ���� 
/*********************************************************************/
//          ���������ܵ�ʵ��  
/********************************************************************/  

void Save_HotelRoomeInfo(HotelRoom *Room)			
{

	for (int i=0;i<30;i++)
	{
		if (Room[i].num!=0)					
		{
			Str<<"������룺"<<Room[i].num<<"\t"<<"�������ͣ�"<<"\t"
				<<Room[i].Type<<"\t"<<"����۸�"<<"\t"
				<<Room[i].Price<<endl<<endl;
		};
	};
};

void Save_CustomerInfo(HotelRoom *Room)
{
	for (int i=0;i<30;i++)
	{
		if (Room[i].num!=0 && Room[i].name!="��")
		{
			C<<"�������ͣ�";
			C<<Room[i].Type<<endl;
			C<<"����۸�";
			C<<Room[i].Price<<endl;
			C<<"�ͻ����֤���룺"<<endl;
			C<<Room[i].ID<<endl;
			C<<"�ͻ�����:";
			C<<Room[i].name<<endl;
			C<<"����";
			C<<Room[i].money<<endl;
			C<<"��ס������";
			C<<Room[i].StayTiem;
			C<<"��"<<endl<<endl;
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
			cout<<"������룺";
			cout<<Room[i].num<<"\t";
			cout<<"�������ͣ�";
			cout<<Room[i].Type<<"\t";
			cout<<"����۸�";
			cout<<Room[i].Price<<endl;
			t++;
		}
		else if(t==0 && i==29)
			cout<<"���޿շ���";
	};
	system("pause");
	system("cls");
};

void Find_Choose(HotelRoom *Room)					//�ͷ����ҹ���ʵ�� 
{

int P=0;

while(P==0)

{

cout<<"\n\n �ͷ�����ϵͳ \n\n"; cout<<" ---------------------------------- \n\n"; 

cout<<" 1.ͨ�����Ų�ѯ�ͷ� \n\n";

cout<<" 2.ͨ�����Ͳ�ѯ�ͷ� \n\n";

cout<<" 3.ͨ���ͻ�������ѯ�ͷ�\n\n";

cout<<" 4.��ѯ���пշ�\n\n";

cout<<" 5.�������˵� \n\n";

cout<<" ��ѡ��";

int choose=0;

cin>>choose;   
system("cls");
switch (choose) 			//ѡ��
{

case 1:Find_HotelRoom_num(Room); break; //����Ϣ

case 2:Find_HotelRoom_Type(Room);break; //������ס�Ǽ�

case 3:Find_HotelRoom_name(Room); break; //��Ϣ

case 4:Display_HotelRoomInfo(Room);break; //�ͻ��˷�

case 5: P=5;   break;

default :; break;

}

};

};

void Delete_HotelRoom(HotelRoom *Room)		//ɾ���ͷ���Ϣ��ʵ�� 
{
	int Num;
	cout<<"������Ҫɾ���ķ���ţ�";
	cin>>Num;
	for(int i=0;i<30;i++)
	{
		if(Room[i].num=Num)
		{
			string B;
			cout<<"�������ҵ�:"<<endl;
			cout<<"��������";
			cout<<Room[i].Type<<endl;
			cout<<"����۸�"; 
			cout<<Room[i].Price<<endl;
			cout<<"�ͻ���Ϣ���£�";
			cout<<"�ͻ����֤���룺";
			cout<<Room[i].ID<<endl;
			cout<<"�ͻ�������"; 
			cout<<Room[i].name<<endl;
			cout<<"�ͻ�����";
			cout<<Room[i].money<<endl;
			cout<<"ȷ��Ҫɾ���ͷ���Ϣ����Y/N��"; 
			cin>>B;
			cout<<endl;
			if(B=="Y")
			{
				Room[i].Type="null";
				Room[i].num=0;
				Room[i].Price="0";
				
				Room[i].money=0;
				Room[i].StayTiem=0;
				Room[i].name="��";
				Room[i].ID="0";
				
				cout<<"ɾ���ɹ���"<<endl;	
			} 
			else if(B=="N")
			{
				cout<<"ɾ��ȡ����"<<endl;
			}
			else cout<<"��Ч�Ĳ���!"<<endl;
		};
		
	  }
		system("pause");		//���á�pause������ 
		system("cls");			//�����Ļ 
};

void Set_Count(HotelRoom *Room)			// �û��˷� 
{
	int Num;
	int t=0;
	cout<<"�����뷿����룺";
	cin>>Num;
	for(int i=0;i<30;i++)
	{
		if(Num==Room[i].num && Room[i].StayTiem!=0)
		{
			string B;
			cout<<"�������ҵ�:"<<endl;
			cout<<"��������";
			cout<<Room[i].Type<<endl;
			cout<<"����۸�"; 
			cout<<Room[i].Price<<endl;
			cout<<"�ͻ���Ϣ���£�";
			cout<<"�ͻ����֤���룺";
			cout<<Room[i].ID<<endl;
			cout<<"�ͻ�������"; 
			cout<<Room[i].name<<endl;
			cout<<"�ͻ�����";
			cout<<Room[i].money<<endl;
			cout<<"��ס������";
			cout<<Room[i].StayTiem<<"�졣"<<endl<<endl;
			cout<<"��ȷ���Ƿ�Ҫ�˷���Y/N��"<<endl;
			cin>>B;
			if(B=="Y")
			{
				Room[i].StayTiem=0;
				Room[i].money=0;
				Room[i].name="��";
				Room[i].ID="0";
				
				cout<<"�˷��ɹ���"<<endl; 
			}
			else if(B=="N")
			{
				cout<<"ȡ���˷���"<<endl; 
			}
			else if(Num==Room[i].num && Room[i].StayTiem==0)
			{
				cout<<"�˷�Ϊ�շ���";
				t++; 
			}
			else if(t==0 && i==29 && Room[i].Type=="null")
		 	cout<<"���޴˷���"<<endl; 
		};
	} 
	system("pause");
	system("cls");
};

void add_HotelRoomInfo(HotelRoom *Room)		//��ӿͷ�
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
				cout<<"������룺"<<Room[i].num;
				cout<<endl;
				cout<<"��������";
				cin>>Room[i].Type;
				cout<<endl;
				cout<<"����۸�";
				cin>>Room[i].Price;
				cout<<endl<<endl;
								 
				cout<<"������ӳɹ����Ƿ����?(Y/N)";
				cin>>P;
				break; 
			}
			else Number++;
		};
	}
	while(P=="Y");
	if(P=="N")
	cout<<"��ȡ����ӡ�";
	else cout<<"��Ч�Ĳ�����"<<endl<<endl; 
};

void set_HotelRoomInfo(HotelRoom *Room)			//���ÿͷ���Ϣ 
{
	if(Room[0].num==0)
	{
		int size;
		cout<<"���޸÷�����Ϣ������ӣ�"<<endl;
		static int Number=700;
		cout<<"������Ҫ��ӵķ�������";
		cin>>size;
		for(int i=0;i<size;i++)
		{
			Room[i].num=Number++;
			cout<<"������룺"<<Room[i].num;
			cout<<endl; cout<<"�������ͣ�";
			cin>>Room[i].Type;
			cout<<"����۸�";
			cin>>Room[i].Price;
			cout<<endl<<endl;
		} ;
		cout<<"�ͷ���Ϣ¼��ɹ�!"<<endl<<endl;
	}	
	else
 	{
	string P;
	cout<<"�ͷ���Ϣ���У��Ƿ�Ҫ��ӷ��䣿��Y/N��"; cin>>P;
	if(P=="Y")
	add_HotelRoomInfo(Room);
	else if(P=="N")
	cout<<"��ȡ���������."<<endl<<endl;
	else cout<<"��Ч�Ĳ�����"<<endl<<endl;
	};
	system("pause");
	system("cls");
};
 
 void set_CustomerInfo(HotelRoom *Room)			//���ù˿���Ϣ 
 {
 	int Num;
	int t=0;
	cout<<"���뷿����룺";
	cin>>Num;
	for(int i=0;i<30;i++)
	{
	if(Num==Room[i].num && Room[i].StayTiem==0)
	{
	cout<<"�������ҵ���"<<endl;
	cout<<"��������:";
	cout<<Room[i].Type<<endl;
	cout<<"����۸�:";
	cout<<Room[i].Price<<endl;
	cout<<"������ͻ���Ϣ��"<<endl;
	cout<<"�Ƿ�ȷ��Ҫ��������Y/N��";
	string p;
	cin>>p;
		if(p=="Y")
		{
		cout<<"�ͻ����֤����:";
		cin>>Room[i].ID;
		cout<<"�ͻ�������";
		cin>>Room[i].name;
		cout<<"����:";
		cin>>Room[i].money;
		cout<<"��ס������";
		cin>>Room[i].StayTiem;cout<<"��"; 
		cout<<endl;
		cout<<"��Ϣ¼��ɹ�!"<<endl;
		}
		else if(p=="N") cout<<"������ȡ����";
    	else cout<<"��Ч�Ĳ�����";
    	t++;
 	}
 	else if(Num==Room[i].num && Room[i].StayTiem!=0)
 	{
	 	cout<<"�˷���ס";
		t++;
	}
	else if(t==0 && i==29)
	cout<<"���޴˷�";
 	};
 	system("pause");
	system("cls");
};

void Find_HotelRoom_num(HotelRoom *Room)		//�����Ų�ѯ 
{
	int Num; int t=0; 
	cout<<"����Ҫ���ҵķ�����룺";
	cin>>Num;
	for(int i=0;i<30;i++)
	{
		if(Num==Room[i].num && Room[i].StayTiem!=0)
		{
			cout<<"��������:"; 
			  cout<<Room[i].Type<<endl;
			cout<<"����۸�:"; 
			  cout<<Room[i].Price<<endl;
  			cout<<"�ͻ�������"; 
			  cout<<Room[i].name;
			cout<<endl; 
			cout<<"�ͻ����֤����:"; 
			  cout<<Room[i].ID;cout<<endl;
		    cout<<"����:"; 
			cout<<Room[i].money;
			cout<<endl<<endl; 
			cout<<"�˷���ס��";
		    cout<<Room[i].StayTiem<<"����˷���";
		    cout<<endl<<endl<<endl;
		    t++;
		}
		else if(Num==Room[i].num && Room[i].StayTiem==0)
		{
			cout<<"��������:";
			 cout<<Room[i].Type<<endl;
		    cout<<"����۸�:"; 
			  cout<<Room[i].Price<<endl;
		    cout<<"�ͻ�������"; 
			  cout<<Room[i].name;cout<<endl;
		    cout<<"�ͻ����֤����:";
			  cout<<Room[i].ID;cout<<endl; 
		    cout<<"����;";
			  cout<<Room[i].money;
		    cout<<endl<<endl; 
			t++;
		}
		else if(t==0 && i==29 && Room[i].Type=="null")
		cout<<"���޴˷�"<<endl<<endl;		
	};
	system("pause");
	system("cls");
};

void Find_HotelRoom_name(HotelRoom *Room)	// ���ͻ�����ѯ 
{
	int t=0;
	string Name;
	cout<<"����ͻ�������";
	cin>>Name;
	for(int i=0;i<30;i++)
	{
		if(Name==Room[i].name && Room[i].StayTiem!=0)
		{
			cout<<"��������:";
			cout<<Room[i].Type<<endl;
			cout<<"����۸�:";
			cout<<Room[i].Price<<endl;
			cout<<"�ͻ�������";
			cout<<Room[i].name;cout<<endl;
			cout<<"�ͻ����֤����:";
			cout<<Room[i].ID;cout<<endl;
			cout<<"����:";
			cout<<Room[i].money;
			cout<<endl<<endl;
			cout<<"�˷���ס��";
			cout<<Room[i].StayTiem<<"����˷���";
		 	cout<<endl<<endl<<endl;
			t++;
		}
		else if(Name==Room[i].name && Room[i].StayTiem==0)
	 	{
 			cout<<"��������:";
			cout<<Room[i].Type<<endl;
			cout<<"����۸�:";
			cout<<Room[i].Price<<endl;
			cout<<"�ͻ�������";
			cout<<Room[i].name;cout<<endl;
			cout<<"�ͻ����֤����:";
			cout<<Room[i].ID;cout<<endl;
			cout<<"����:";
			cout<<Room[i].money;
			cout<<endl<<endl;
			t++;
 		}
 		else if(t==0 && i==29)
 		cout<<"��ѯ�����˿ͻ���"<<endl<<endl;
	};
	system("pause");
	system("cls");
};

void Find_HotelRoom_Type(HotelRoom *Room)		//�������Ͳ�ѯ 
{
	int t=0;
	string type;
	cout<<"���뷿�����ͣ�";
	cin>>type;
	for(int i=0;i<30;i++)
	{
		if(type==Room[i].Type && Room[i].StayTiem!=0)
		{
			cout<<"��������:";
			cout<<Room[i].Type<<endl;
			cout<<"����۸�:";
			cout<<Room[i].Price<<endl;
			cout<<"�ͻ�������";
			cout<<Room[i].name;cout<<endl;
			cout<<"�ͻ����֤����:";
			cout<<Room[i].ID;cout<<endl;
			cout<<"����:";
			cout<<Room[i].money;cout<<endl<<endl;
			cout<<"�˷���ס��";
			cout<<Room[i].StayTiem<<"����˷���";
			cout<<endl<<endl<<endl;
			t++;
		}
		else if(type==Room[i].Type && Room[i].StayTiem==0)
		{
			cout<<"��������:";
			cout<<Room[i].Type<<endl;
			cout<<"����۸�:";
			cout<<Room[i].Price<<endl;
			cout<<"�ͻ�������";
			cout<<Room[i].name;cout<<endl;
			cout<<"�ͻ����֤����:";
			cout<<Room[i].ID;cout<<endl;
			cout<<"����:";
			cout<<Room[i].money;cout<<endl<<endl;
			t++;
		}
		else if(t==0 && i==29)
		cout<<"���޴��෿�䡣"<<endl<<endl;
	};
	system("pause");
	system("cls");
};

void PrintAll(HotelRoom *Room)			//��ʾ������Ϣ 
{
	int t=0;
	for(int i=0;i<30;i++)
	{
		if(Room[i].Type!="null")
		{
			cout<<"��������:"<<Room[i].Type<<"\t";
			cout<<"�����:"<<Room[i].num<<"\t";
			cout<<"�۸�:"<<Room[i].Price<<endl;
			
			cout<<"�ͻ�������"<<Room[i].name<<"\t";
			cout<<"�ͻ����֤���룺"<<Room[i].ID<<"\t";
			cout<<"����"<<Room[i].money<<endl;
			cout<<"����"<<Room[i].StayTiem<<"����˷���";
			cout<<endl<<endl<<endl;	
			
			t++;
		}
		if(t==0 && i==29) 
		cout<<"�����κοͷ���Ϣ!"<<endl<<endl;
	};
	system("pause");
	system("cls");
};

void Change_HotelRoomInfo(HotelRoom  *Room)		//�޸���Ϣ 
{
	int Num;
	cout<<"������Ҫ�޸ĵķ������:"<<endl;
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
			cout<<"��������:";
			cout<<Room[i].Type<<endl;
			cout<<"����۸�:";
			cout<<Room[i].Price<<endl;
			cout<<"�ͻ�������";
			cout<<Room[i].name;cout<<endl;
			cout<<"�ͻ����֤����:";
			cout<<Room[i].ID;cout<<endl;
			cout<<"����:";
			cout<<Room[i].money;
			cout<<"����"<<Room[i].StayTiem<<"����˷���"<<endl;
			cout<<"������Ϣ���ҵ�!"<<endl;
			cout<<"�Ƿ�ȷ��Ҫ�޸ķ�����Ϣ����Y/N��";
			string p;
			cin>>p;
			if(p=="Y")
			{
				cout<<"�ͻ�������";
				cin>>_name;
				Room[i].name=_name;
				cout<<endl;
				cout<<"�ͻ����֤����:";
				cin>>_ID;
				Room[i].ID=_ID;
				cout<<endl;
				cout<<"����:";
				cin>>_money;
				Room[i].money=_money;
				cout<<"�˷�ʱ���ӳ���";cin>>_StayTime;cout<<"���";
				Room[i].StayTiem=_StayTime;
				cout<<endl;
				Save_CustomerInfo(Room);
				cout<<"�޸ĳɹ�!"<<endl<<endl;
			}
			else if(p=="N") cout<<"��ȡ���޸ġ�";
			else cout<<"��Ч�Ĳ�����";
			t++; 
		}
		else if(t==0 && i==29 && Room[i].Type=="null")
		cout<<"���޴˷���"<<endl<<endl;
	};
	system("pause");
	system("cls");
};

void Write(HotelRoom *Room)				//д���ļ� 
{
	fstream file("Room.txt",ios::out);
	for (int i=0;i<=30;i++)
	if (Room[i].Type!="null")
	file.write((char *)&Room[i],sizeof(Room[i]));
	file.close();
};

void Read(HotelRoom *Room)			//�����ļ� 
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
	{												//����������
	 
	cout<<"\n\n                     �ͷ�����ϵͳ          \n\n"; 
	cout<<" ------------------------------------------------------------- \n\n";
	cout<<" 1.�ͷ���Ϣ��¼�� \n\n"; 
	cout<<" 2.������ס�Ǽ� \n\n"; 
	cout<<" 3.�ͷ���Ϣ���޸� \n\n"; 
	cout<<" 4.�����˷����� \n\n"; 
	cout<<" 5.��ѯ���пͷ���Ϣ \n\n"; 
	cout<<" 6.��ѯ��ʽ \n\n";
	cout<<" 7.ɾ���ͷ���Ϣ \n\n"; 
	cout<<" 8.�� �� ϵ ͳ \n\n";
	cout<<"***************************************************************"<<endl ; 
	cout<<"      ��ѡ��";
	
	int choose=0;
	cin>>choose;
	system("cls");
	switch (choose) 
	{
		case 1:set_HotelRoomInfo(Room); break; 			//����ͷ���Ϣ
		case 2:set_CustomerInfo(Room);break; 		//������ס�Ǽ�
		case 3:Change_HotelRoomInfo(Room); break; 	//�޸Ŀͷ���Ϣ
		case 4:Set_Count(Room);break; 			//�ͻ��˷�
		case 5:PrintAll(Room); break; 			//��ѯ���пͷ���Ϣ
	    case 6:Find_Choose(Room); break; 		//��ѯ
	    case 7:Delete_HotelRoom(Room);break; 		//ɾ���ͷ���Ϣ
	    case 8:Write(Room);
	    
	    						//������Ϣ 
	    Save_HotelRoomeInfo(Room);
		Save_CustomerInfo(Room);
		exit(0);    //�˳� default : break;
	}	
		
	}
	return 0;
}



