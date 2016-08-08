#include <windows.h>
#include<graphics.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define WS_EX_LAYERED 0x00080000
#pragma comment( lib, "MSIMG32.LIB")// 引用该库才能使用 TransparentBlt 函数
#pragma comment(lib,"Winmm.lib")
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )//不显示控制台

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
	//加载玫瑰花
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
	outtextxy(-680,-100,_T("献给群里热爱C语言的初学者和大神们"));
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
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 48;  // 设置字体高度为 48
	f.lfWidth=30;
	_tcscpy(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
//	settextstyle(20, 5, _T("宋体"));
	int i;
	for( i=0;i<10;i++)
	{
		settextcolor(HSLtoRGB(10,1,0.7f));
		outtextxy(-40,-100,"LOVE");
		outtextxy(-280,-30,"送给我亲爱的老婆");
		Sleep(200);
		settextcolor(HSVtoRGB(100,1,1));
		outtextxy(-40,-100,"LOVE");
		outtextxy(-280,-30,"送给我亲爱的老婆");
		Sleep(200);
	}
	settextcolor(WHITE);
	outtextxy(-40,-100,"LOVE");
	outtextxy(-280,-30,"送给我亲爱的老婆");
	Sleep(1000);
	putimage(-280,-100,&img4);

	
	IMAGE img6;
	getimage(&img6,-150,-120,750,600);
	gettextstyle(&f);
	f.lfHeight=20;
	f.lfWidth=12;
	f.lfWeight=800;
	_tcscpy(f.lfFaceName,_T("宋体"));
	settextcolor(HSLtoRGB(300,0.7,0.4));
	settextstyle(&f);
	outtextxy(-150,-120, _T("呵呵,相处快有一年了,想起"));
	Sleep(2000);
	outtextxy(-150,-90,  _T("去年的今天,那个时候我还没"));
	Sleep(2000);
	outtextxy(-150,-60,  _T("收获渴望已久的爱情呢,今天"));
	Sleep(2000);
	outtextxy(-150,-30,  _T("有空的时候,翻了翻你送我的"));
	Sleep(2000);
	outtextxy(-150,  0,  _T("朴有天明星片,哇，上面的点"));
	Sleep(2000);
	outtextxy(-150, 30,  _T("点滴滴,又浮现在我眼前了,突"));
	Sleep(2000);
	outtextxy(-150, 60,  _T("然之间觉得老婆好有爱呀,呵"));
	Sleep(2000); 
	outtextxy(-150, 90,  _T("呵,沙下蒙蒙的誓言,算命先生"));
	Sleep(6000);

	putimage(-150,-120,&img6);

	outtextxy(-150,-120, _T("的甜言蜜语,纠结猴猴配不配 "));
	Sleep(2000);
	outtextxy(-150,-90,  _T("KTV里的歌声,把许嵩的唱个遍"));
	Sleep(2000);
	outtextxy(-150,-60,  _T("老婆很体贴我,就像你写的那"));
	Sleep(2000);
	outtextxy(-150,-30,  _T("句话,当我在熟练地敲打键盘时,"));
	Sleep(2000);
	outtextxy(-150,  0,  _T("你心里是否想我!黄家湖畔的散"));
	Sleep(2000);
	outtextxy(-150, 30,  _T("步,我扮演的是猪八戒背媳妇的"));
	Sleep(2000);
	outtextxy(-150, 60,  _T("角色,生日礼物的小惊喜,躲在"));
	Sleep(2000);
	outtextxy(-150, 90,  _T("石头后面的你吓我一跳......"));
	Sleep(6000);
	putimage(-150,-120,&img6);
	
	outtextxy(-150,-60, _T("哈哈,多么美好的回忆呀,虽"));
	Sleep(2000);
	outtextxy(-150,-30, _T("然是异地恋,但我丝毫没有觉"));
	Sleep(2000);
	outtextxy(-150,  0, _T("得你离我很远,就像那首歌一"));
	Sleep(2000);
	outtextxy(-150, 30, _T("样,也许我在想你的时候你正"));
	Sleep(2000);
	outtextxy(-150, 60, _T("在想我,这样我就满足了!"));
	Sleep(6000);
	putimage(-150,-120,&img6);

	outtextxy(-150,-30, _T("我身边,我是你的superstar"));
	Sleep(2000);
	outtextxy(-150, 0,  _T("你是我的luckystar!"));
	Sleep(2000);
	outtextxy(-150, 30, _T("我爱你   一万年"));
	Sleep(2000);

    gettextstyle(&f);
	f.lfHeight=40;
	f.lfWidth=20;
	settextstyle(&f);
	for(i=0;i<20;i++)
	{
		settextcolor(HSLtoRGB(10,1,0.7f));
		outtextxy(-100,80,  _T("爱你一万年!!!"));
		Sleep(200);
		settextcolor(HSLtoRGB(300,0.7,0.4));
		outtextxy(-100,80,  _T("爱你一万年!!!"));
		Sleep(200);
	}
	putimage(-150,-120,&img6);
	outtextxy(-150,-30, _T("希望每个人都坚守"));
	Sleep(2000);
	outtextxy(-100, 30,  _T("自己的爱情"));
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
	outtextxy(-150,-200,_T("我爱你"));
	Sleep(1200);
	outtextxy(-200,-60,_T("把心交给我"));
	Sleep(1200);
	outtextxy(-240,80,_T("让我去疼你吧"));
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

void Frametransparent(HWND hwnd,bool frame)//去掉边框，只需调用EFrame(0);
{
	long style =GetWindowLong(hwnd,GWL_STYLE);
	if(frame)
	{
		style |= WS_CAPTION;//加上边框
	}
	else
	{
		style &= ~ WS_CAPTION;//去掉边框
	}	
	SetWindowLong(hwnd,GWL_STYLE,style);//设置完成 
}



bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{
	// 创建文件
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	// 查找资源文件中、加载资源到内存、得到资源大小
	HRSRC	hRes	= ::FindResource(NULL, strResName, strResType);
	HGLOBAL	hMem	= ::LoadResource(NULL, hRes);
	DWORD	dwSize	= ::SizeofResource(NULL, hRes);
	
	// 写入文件
	DWORD dwWrite = 0;  	// 返回写入字节
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