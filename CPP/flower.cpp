#include <windows.h>
#include<graphics.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define WS_EX_LAYERED 0x00080000
#pragma comment( lib, "MSIMG32.LIB")// ���øÿ����ʹ�� TransparentBlt ����
#pragma comment(lib,"Winmm.lib")
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )//����ʾ����̨

#define PI 3.141592653


bool SetWindowTransparent(HWND hwnd,COLORREF crkcolor,BYTE bAlpha,DWORD dwFlags);
void Frametransparent(HWND hwnd,bool frame);
bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName);
void playmusic();
void drawaixin(HDC dstDC,HDC srcDC);
void aixin(HDC dstDC,HDC srcDC);
void shuzi();
void puman(HDC dstDC,HDC srcDC);
void shuaxin();
void meiguihua();
void huaban();
void puman2();

int chang=GetSystemMetrics(SM_CXSCREEN);//1366
int gao=GetSystemMetrics(SM_CYSCREEN);//768

void main()
{
	initgraph(chang,gao);
	playmusic();
	setorigin(chang/2,gao/2);//683,384
	setbkcolor(WHITE);
	cleardevice();
	HWND hwnd = GetHWnd();
	Frametransparent(hwnd,0);
	SetWindowTransparent(hwnd,WHITE,100,0x1);
	SetWindowPos(hwnd,HWND_DESKTOP,0,0,0,0,SWP_NOSIZE);
	//����õ�廨
	IMAGE img1;
	loadimage(&img1,"IMAGE",_T("img1"));
	HDC dstDC = GetImageHDC();
    HDC srcDC = GetImageHDC(&img1);
		
	drawaixin(dstDC,srcDC);
	aixin(dstDC,srcDC);
	shuzi();
	puman(dstDC,srcDC);
	shuaxin();
	
	Sleep(1000);
	
	huaban();
	meiguihua();
	puman2();
	shuaxin();
	outtextxy(-680,-100,_T("�׸�Ⱥ���Ȱ�C���Եĳ�ѧ�ߺʹ�����"));
	outtextxy(-680,0,   _T("                         ----DERL"));
	outtextxy(-680,100, _T("                   ----LOVE C"));
	Sleep(10000);

	
}
 
void puman2()
{
	IMAGE img[4];

	loadimage(&img[0],_T("IMAGE"),_T("zise"));
	loadimage(&img[1],_T("IMAGE"),_T("img1"));
	loadimage(&img[2],_T("IMAGE"),_T("juhua"));
	loadimage(&img[3],_T("IMAGE"),_T("fenhong"));
	HDC dstDC=GetImageHDC();
	HDC srcDC;

	int i;
	int x,y;

	srcDC=GetImageHDC(&img[1]);
	TransparentBlt(dstDC,x,y,100,100,srcDC,0,0,100,100,0x000000);
	

	for(i=0;i<100;i++)
	{	
		srand((unsigned int)time(NULL));
		int count=fabs(rand()%4);
		x=rand()%chang-chang/2;
		y=rand()%gao-gao/2;
		switch (count)
		{
			case 0:	
			{
				srcDC=GetImageHDC(&(img[0]));
				TransparentBlt(dstDC,x,y,500,500,srcDC,0,0,500,500,0x000000);
				FlushBatchDraw();
				break;
			}
			case 1:
			{
				srcDC=GetImageHDC(&img[1]);
				TransparentBlt(dstDC,x,y,100,100,srcDC,0,0,100,100,0x000000);
				FlushBatchDraw();
				break;
			}
			case 2:
			{
				srcDC=GetImageHDC(&img[2]);
				TransparentBlt(dstDC,x,y,200,200,srcDC,0,0,200,200,0x000000);
				FlushBatchDraw();
				break;
			}
			case 3:
			{
				srcDC=GetImageHDC(&img[3]);
				TransparentBlt(dstDC,x,y,200,200,srcDC,0,0,200,200,0x000000);
				FlushBatchDraw();
				break;
			}
		}
		Sleep(100);
	}
}


void huaban()
{
	IMAGE img[7];
	IMAGE img0;
	IMAGE image;
	getimage(&img0,-chang/2,-gao/2,chang,gao);
	loadimage(&img[0],_T("IMAGE"),_T("hua00"));
	loadimage(&img[1],_T("IMAGE"),_T("hua02"));
	loadimage(&img[2],_T("IMAGE"),_T("hua03"));
	loadimage(&img[3],_T("IMAGE"),_T("hua04"));
	loadimage(&img[4],_T("IMAGE"),_T("hua05"));
	loadimage(&img[5],_T("IMAGE"),_T("hua06"));
	loadimage(&img[6],_T("IMAGE"),_T("hua06"));
	HDC h1=GetImageHDC();
	HDC h2;
	int i,j,k;
	srand((unsigned int )time(NULL));
	j=-gao/2;
	while(j<=(gao/2-100))
	{
		putimage(-chang/2,-gao/2,&img0);
		for(i=-chang/2;i<=chang/2;i+=200)
		{
			
			int m=rand()%7;
			m=fabs(m);
			h2=GetImageHDC(&(img[m]));
			TransparentBlt(h1,i,j,200,200,h2,0,0,200,200,0x000000);
			FlushBatchDraw();
		}
		j+=20;
		Sleep(100);
			
	}
	getimage(&image,-chang/2,gao/2-400,chang,400);
	putimage(-chang/2,gao/2-400,&image);
	Sleep(2000);
	
	j=-gao/2;
	while(j<=(gao/2-100))
	{
		putimage(-chang/2,-gao/2,&img0);
		putimage(-chang/2,gao/2-400,&image);
		for(i=-chang/2+50;i<=chang/2;i+=200)
		{
			
			int m=rand()%7;
			m=fabs(m);
			h2=GetImageHDC(&(img[m]));
			TransparentBlt(h1,i,j,200,200,h2,0,0,200,200,0x000000);
			FlushBatchDraw();
		}
		j+=20;
		Sleep(100);		
	}
	getimage(&image,-chang/2,gao/2-400,chang,400);
	putimage(-chang/2,gao/2-400,&image);
	Sleep(2000);

	j=-gao/2;
	while(j<=(gao/2-100))
	{
		putimage(-chang/2,-gao/2,&img0);
		putimage(-chang/2,gao/2-400,&image);
		for(i=-chang/2+100;i<=chang/2;i+=200)
		{
			
			int m=rand()%7;
			m=fabs(m);
			h2=GetImageHDC(&(img[m]));
			TransparentBlt(h1,i,j,200,200,h2,0,0,200,200,0x000000);
			FlushBatchDraw();
		}
		j+=20;
		Sleep(100);		
	}
	
	getimage(&image,-chang/2,gao/2-400,chang,400);
	putimage(-chang/2,gao/2-400,&image);
	Sleep(2000);

	j=-gao/2;
	while(j<=(gao/2-100))
	{
		putimage(-chang/2,-gao/2,&img0);
		putimage(-chang/2,gao/2-400,&image);
		for(i=-chang/2+100;i<=chang/2;i+=200)
		{
			
			int m=rand()%7;
			m=fabs(m);
			h2=GetImageHDC(&(img[m]));
			TransparentBlt(h1,i,j,200,200,h2,0,0,200,200,0x000000);
			FlushBatchDraw();
		}
		j+=20;
		Sleep(80);		
	}
	
	getimage(&image,-chang/2,gao/2-400,chang,400);
	putimage(-chang/2,gao/2-400,&image);
	Sleep(2000);
}
void meiguihua()
{
	IMAGE img,img1;
	IMAGE image;
	loadimage(&img, _T("IMAGE"),_T("meigui1"));	

	HDC dstDC=GetImageHDC();
	HDC srcDC=GetImageHDC(&img);
	
	int i=-chang/2,j;
	while(i<=chang/2)
	{
		for(j=-gao/2;j<=0;j+=10)
		{	
			getimage(&img1,i,j,300,400);
			putimage(-chang,gao/2-400,&img1);

			TransparentBlt(dstDC,i,j,300,400,srcDC,0,0,300,400,0x000000);
			FlushBatchDraw();
			Sleep(100);
			putimage(i,j,&img1);
		}
		TransparentBlt(dstDC,i,j,300,400,srcDC,0,0,300,400,0x000000);
		FlushBatchDraw();
		getimage(&image,-chang,gao/2-400,chang,400);
		i+=200;
	}

	Sleep(7000);
}

void shuaxin()
{
	IMAGE img;
	loadimage(&img,_T("IMAGE"),_T("kongbai"));
	for(int i=-chang/2;i<700;i+=10)
	{
		putimage(i,-gao/2,&img);
		Sleep(70);
	}
	Sleep(3000);
}

void shuzi()
{
	IMAGE img4;
	getimage(&img4,-280,-100,700,200);
	LOGFONT f;
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 48;  // ��������߶�Ϊ 48
	f.lfWidth=30;
	_tcscpy(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
//	settextstyle(20, 5, _T("����"));
	int i;
	for( i=0;i<10;i++)
	{
		settextcolor(HSLtoRGB(10,1,0.7f));
		outtextxy(-40,-100,"LOVE");
		outtextxy(-280,-30,"�͸����װ�������");
		Sleep(200);
		settextcolor(HSVtoRGB(100,1,1));
		outtextxy(-40,-100,"LOVE");
		outtextxy(-280,-30,"�͸����װ�������");
		Sleep(200);
	}
	settextcolor(WHITE);
	outtextxy(-40,-100,"LOVE");
	outtextxy(-280,-30,"�͸����װ�������");
	Sleep(1000);
	putimage(-280,-100,&img4);

	
	IMAGE img6;
	getimage(&img6,-150,-120,750,600);
	gettextstyle(&f);
	f.lfHeight=20;
	f.lfWidth=12;
	f.lfWeight=800;
	_tcscpy(f.lfFaceName,_T("����"));
	settextcolor(HSLtoRGB(300,0.7,0.4));
	settextstyle(&f);
	outtextxy(-150,-120, _T("�Ǻ�,�ദ����һ����,����"));
	Sleep(2000);
	outtextxy(-150,-90,  _T("ȥ��Ľ���,�Ǹ�ʱ���һ�û"));
	Sleep(2000);
	outtextxy(-150,-60,  _T("�ջ�����Ѿõİ�����,����"));
	Sleep(2000);
	outtextxy(-150,-30,  _T("�пյ�ʱ��,���˷������ҵ�"));
	Sleep(2000);
	outtextxy(-150,  0,  _T("����������Ƭ,�ۣ�����ĵ�"));
	Sleep(2000);
	outtextxy(-150, 30,  _T("��ε�,�ָ���������ǰ��,ͻ"));
	Sleep(2000);
	outtextxy(-150, 60,  _T("Ȼ֮��������ź��а�ѽ,��"));
	Sleep(2000); 
	outtextxy(-150, 90,  _T("��,ɳ�����ɵ�����,��������"));
	Sleep(6000);

	putimage(-150,-120,&img6);

	outtextxy(-150,-120, _T("����������,�������䲻�� "));
	Sleep(2000);
	outtextxy(-150,-90,  _T("KTV��ĸ���,�����Եĳ�����"));
	Sleep(2000);
	outtextxy(-150,-60,  _T("���ź�������,������д����"));
	Sleep(2000);
	outtextxy(-150,-30,  _T("�仰,�������������ô����ʱ,"));
	Sleep(2000);
	outtextxy(-150,  0,  _T("�������Ƿ�����!�ƼҺ��ϵ�ɢ"));
	Sleep(2000);
	outtextxy(-150, 30,  _T("��,�Ұ��ݵ�����˽䱳ϱ����"));
	Sleep(2000);
	outtextxy(-150, 60,  _T("��ɫ,���������С��ϲ,����"));
	Sleep(2000);
	outtextxy(-150, 90,  _T("ʯͷ�����������һ��......"));
	Sleep(6000);
	putimage(-150,-120,&img6);
	
	outtextxy(-150,-60, _T("����,��ô���õĻ���ѽ,��"));
	Sleep(2000);
	outtextxy(-150,-30, _T("Ȼ�������,����˿��û�о�"));
	Sleep(2000);
	outtextxy(-150,  0, _T("�������Һ�Զ,�������׸�һ"));
	Sleep(2000);
	outtextxy(-150, 30, _T("��,Ҳ�����������ʱ������"));
	Sleep(2000);
	outtextxy(-150, 60, _T("������,�����Ҿ�������!"));
	Sleep(6000);
	putimage(-150,-120,&img6);

	outtextxy(-150,-30, _T("�����,�������superstar"));
	Sleep(2000);
	outtextxy(-150, 0,  _T("�����ҵ�luckystar!"));
	Sleep(2000);
	outtextxy(-150, 30, _T("�Ұ���   һ����"));
	Sleep(2000);

    gettextstyle(&f);
	f.lfHeight=40;
	f.lfWidth=20;
	settextstyle(&f);
	for(i=0;i<20;i++)
	{
		settextcolor(HSLtoRGB(10,1,0.7f));
		outtextxy(-100,80,  _T("����һ����!!!"));
		Sleep(200);
		settextcolor(HSLtoRGB(300,0.7,0.4));
		outtextxy(-100,80,  _T("����һ����!!!"));
		Sleep(200);
	}
	putimage(-150,-120,&img6);
	outtextxy(-150,-30, _T("ϣ��ÿ���˶�����"));
	Sleep(2000);
	outtextxy(-100, 30,  _T("�Լ��İ���"));
	Sleep(4000);
	putimage(-150,-120,&img6);	
	
}
void drawaixin(HDC dstDC,HDC srcDC)
{
	double i;
	int x;
	int y;
	int R1=340;
	for(i=30;i<=150;i+=5)
	{
		x=-70+340-R1*cos(i*PI/180);
		y=-80+16-R1*sin(i*PI/180);
		TransparentBlt(dstDC, x, y, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
		FlushBatchDraw();
		Sleep(100);	
	}
	TransparentBlt(dstDC,570,-210, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	double j;
	int R2=600;
	for(j=-10;j>=-60;j-=3)
	{
		x=-10+R2*cos(j*PI/180);
		y=-300-R2*sin(j*PI/180);
		TransparentBlt(dstDC, x,y, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
		FlushBatchDraw();
		Sleep(100);
	}
	TransparentBlt(dstDC,290,210, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,260,225, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,230,240, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,200,255, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,170,270, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,140,283, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,110,296, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,80,306, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,50,314, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,20,320, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-10,326, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-40,320, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-70,314, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-100,306, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-130,296, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	TransparentBlt(dstDC,-160,283, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-190,270, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-220,255, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-250,240, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-280,225, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-310,210, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	for(j=-120;j>=-140;j-=3)
	{
		x=-15+R2*cos(j*PI/180);
		y=-310-R2*sin(j*PI/180);
		TransparentBlt(dstDC, x,y, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
		FlushBatchDraw();
		Sleep(100);
	}
	TransparentBlt(dstDC,-480,70, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-506,50, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-530,30, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-550,10, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-565,-10, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-583,-35, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-598,-60, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-608,-85, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-618,-110, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-626,-130, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-634,-150, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-640,-170, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-646,-190, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-644,-210, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	
	for(i=30;i<=150;i+=5)
	{
		x=-340-R1*cos(i*PI/180);
		y=-80+16-R1*sin(i*PI/180);
		TransparentBlt(dstDC, x, y, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
		FlushBatchDraw();
		Sleep(100);	
	}

}
void aixin(HDC dstDC,HDC srcDC)
{
	TransparentBlt(dstDC,-330,-200, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-305,-200, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-280,-200, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-255,-200, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-230,-200, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-280,-160, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-280,-130, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-280,-100, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-280,-70, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-280,-40, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-280,-10, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-280, 20, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-330,60, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-305,60, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-280,60, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-255,60, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,-230,60, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(500);
	
	TransparentBlt(dstDC,150,-200, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	TransparentBlt(dstDC,150,-170, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	
	TransparentBlt(dstDC,150,-140, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	TransparentBlt(dstDC,150,-110, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	TransparentBlt(dstDC,150,-80, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	
	TransparentBlt(dstDC,150,-50, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	TransparentBlt(dstDC,150,-20, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	TransparentBlt(dstDC,160,0, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	TransparentBlt(dstDC,180,20, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	TransparentBlt(dstDC,200,40, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	TransparentBlt(dstDC,220,53, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	
	TransparentBlt(dstDC,240,60, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	TransparentBlt(dstDC,260,60, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	TransparentBlt(dstDC,280,60, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);

	TransparentBlt(dstDC,300,53, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,320,40, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,340,20, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,360,0, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,370,-20, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,370,-50, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,370,-80, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,370,-110, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,370,-140, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,370,-170, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(100);
	TransparentBlt(dstDC,370,-200, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(500);

	IMAGE img5;
	getimage(&img5,-290,-180,585,328);


	setbkmode(TRANSPARENT);
	IMAGE img3;
	loadimage(&img3,_T("IMAGE"),_T("aixin"));
	putimage(-290,-180,&img3,SRCAND);
	Sleep(2000);
	
	IMAGE img0;
	int i,j;
	for(i=-290,j=-180;i>=-883&&j<=534;i-=10,j+=4)
	{	
		getimage(&img0,i,j,585,328);
		BeginBatchDraw();
		
		putimage(i,j,&img3,SRCAND);
		FlushBatchDraw();
		Sleep(80);
		putimage(i,j,&img0);
	}
	EndBatchDraw();
	putimage(i,j,&img3,SRCAND);
	

	for(i=-290,j=-180;i>=-903&&j>=-534;i-=10,j-=6)
	{
		getimage(&img0,i,j,585,328);
		BeginBatchDraw();
		putimage(i,j,&img3,SRCAND);
		FlushBatchDraw();
		Sleep(80);
		putimage(i,j,&img0);
	}
	EndBatchDraw();
	putimage(i,j,&img3,SRCAND);


	for(i=-290,j=-180;i<=283&&j<=184;i+=10,j+=4)
	{
		getimage(&img0,i,j,585,328);
		BeginBatchDraw();
		putimage(i,j,&img3,SRCAND);
		FlushBatchDraw();
		Sleep(80);
		putimage(i,j,&img0);
	}
	EndBatchDraw();
	putimage(i,j,&img3,SRCAND);
	
	
	for(i=-290,j=-180;i<=273&&j>=-584;i+=11,j-=7)
	{
		getimage(&img0,i,j,585,328);
		BeginBatchDraw();
		putimage(i,j,&img3,SRCAND);
		FlushBatchDraw();
		Sleep(80);
		putimage(i,j,&img0);
	}
	EndBatchDraw();
	putimage(i,j,&img3,SRCAND);
	Sleep(2000);
	putimage(-290,-180,&img5);

	Sleep(2000);
}


void puman(HDC dstDC,HDC srcDC)
{
	int x,y;
	srand((unsigned int) time (NULL));
	for(int i=0;i<1200;i++)
	{
		x=rand()%chang-chang/2-50;
		y=rand()%gao-gao/2-50;
		TransparentBlt(dstDC,x,y,100,100,srcDC ,0,0,100,100,0x000000);
		FlushBatchDraw();
		Sleep(30);
	}
	
	Sleep(1000);
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight=100;
	f.lfWidth=40;
	settextstyle(&f);
	outtextxy(-150,-200,_T("�Ұ���"));
	Sleep(1200);
	outtextxy(-200,-60,_T("���Ľ�����"));
	Sleep(1200);
	outtextxy(-240,80,_T("����ȥ�����"));
	Sleep(3000);
}

bool SetWindowTransparent(HWND hwnd,COLORREF crkcolor,BYTE bAlpha,DWORD dwFlags)
{
	HINSTANCE hm=GetModuleHandle(_T("USER32.DLL"));
	if(hm)
	{
		FARPROC fun=GetProcAddress(hm,"SetLayeredWindowAttributes");
		bool (WINAPI *SetLayeredWindowAttributes)(HWND,COLORREF,BYTE,DWORD)=(bool (WINAPI*) (HWND,COLORREF,BYTE,DWORD))fun;

		if(SetLayeredWindowAttributes)
		{
			LONG ret=GetWindowLong(hwnd,GWL_EXSTYLE);
			ret|=WS_EX_LAYERED;
			SetWindowLong(hwnd,GWL_EXSTYLE,ret);
			SetLayeredWindowAttributes(hwnd,crkcolor,bAlpha,dwFlags);
		}
		FreeLibrary(hm);
		return true;
	}
	else
	{
		return false;
	}
}

void Frametransparent(HWND hwnd,bool frame)//ȥ���߿�ֻ�����EFrame(0);
{
	long style =GetWindowLong(hwnd,GWL_STYLE);
	if(frame)
	{
		style |= WS_CAPTION;//���ϱ߿�
	}
	else
	{
		style &= ~ WS_CAPTION;//ȥ���߿�
	}	
	SetWindowLong(hwnd,GWL_STYLE,style);//������� 
}



bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{
	// �����ļ�
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	// ������Դ�ļ��С�������Դ���ڴ桢�õ���Դ��С
	HRSRC	hRes	= ::FindResource(NULL, strResName, strResType);
	HGLOBAL	hMem	= ::LoadResource(NULL, hRes);
	DWORD	dwSize	= ::SizeofResource(NULL, hRes);
	
	// д���ļ�
	DWORD dwWrite = 0;  	// ����д���ֽ�
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	::CloseHandle(hFile);

	return true;
}

void playmusic()
{
	char s[300];
	char tmpmp3[_MAX_PATH];
	::GetTempPath(_MAX_PATH, tmpmp3);
	strcat(tmpmp3, "playmp3_mu.mp3");
	ExtractResource(tmpmp3, _T("misic"), _T("mu.mp3"));
	sprintf(s, "open \"%s\" alias mymusic", tmpmp3);
	mciSendString(s, NULL, 0, NULL);
	mciSendString(_T("play mymusic repeat"), NULL, 0, NULL);
	//mciSendString("play mymusic repeat",NULL,0,NULL);//
}  