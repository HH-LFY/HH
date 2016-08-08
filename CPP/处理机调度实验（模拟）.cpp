#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<windows.h>
#include<time.h>
#include<conio.h>
#define getPcb(type) (type*)malloc(sizeof(type))
#define slp for(int i = 0;i < 3; ++i){printf(".");Sleep(500);} puts("");
using namespace std;
typedef struct Pcb {
	int ID;//进程ID
	int name;//进程名称
	char state;//进程状态
	int super;//优先数
	int ntime;//需要运行时间
	int rtime;//已用CPU时间
	int startblock;//进程阻塞时间
	int sb;//用来标记进程阻塞的时间
	int blocktime;//进程被阻塞的时间
	int bt;//用来标记进程被阻塞的时间
	struct Pcb *next;//下一个进程
} PCB;
void PcbInit(PCB * &p) {//初始化队列
	p = getPcb(PCB);//创建一个空进程，作为队列的头节点，头节点参与运行
	p->next = NULL;//将头结点的下一个进程标记为空
}
void PcbInsert(Pcb * &r, Pcb * p) {//往就绪队列里添加一个新的进程
	Pcb * t = r;
	while(t->next != NULL) {//找到就绪队列里的最后一个进程
		t = t->next;
	}
	p->next = t->next;//将新的进程添加到就绪队列队尾
	t->next = p;
}
void PcbDisp(PCB * L) {//显示进程状态信息
    PCB *p = L->next;
    if(p == NULL) return ;
    printf("进程名称     进程状态     需要用时     已用时间      阻塞时间   优先数\n");
    while(p != NULL) {
        printf("   %d        \t%c       \t%d      \t%d      \t\t%d    \t%d\n", p->name, p->state, p->ntime, p->rtime,p->startblock,p->super);
        p = p->next;
    }
    printf("\n");
}
void PcbDelete(Pcb * &r, int des) {//从队列里删除一个进程
	PCB * t = r, * p, *q;
	while(t != NULL && t->ID != des) {//找到要删除的进程
		q = t;
		t = t->next;
	}
	if(t == NULL) return ;
	p = t->next;
	q->next = p;
	free(t);
}
void PcbSort(PCB * &r) {//对队列进行升序排序
	if(r->next == NULL) return ;
	PCB *p, *pre, *q;
	p = r->next->next;
	r->next->next = NULL;
	while(p != NULL) {
		q = p->next;
		pre = r;
		while(pre->next != NULL && pre->next->super > p->super) {
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}
void PcbtoPcb(Pcb * &r, Pcb * p) {//将一个进程从一个队列转移到另一个队列
	PCB * t = r;
	PCB * s = getPcb(PCB);//创建一个临时进程
	s->ID = p->ID;
	s->name=p->name;
	s->state =  p->state;
	s->super =  p->super;
	s->ntime =  p->ntime;
	s->rtime =  p->rtime;
	s->startblock =  p->startblock;
	s->sb =  p->sb;
	s->blocktime = p->blocktime;
	s->bt = p->bt;
	s->next = NULL;
	while(t->next != NULL) {//找到要添加进程队列的最后一个进程
		t = t->next;
	}
	t->next = s;//将进程添加到队列中
}
void PcbSuper(Pcb * &r) {//就绪队列里的每个进程优先数加1
	PCB * t = r;
	if(t == NULL) return ;
	while(t != NULL) {
		t->super++;
		t = t->next;
	}
}
void PcbBlock(PCB * &r, PCB * &b) {//进程进入阻塞状态后,没执行一个时间片，被阻塞时间减1
	PCB * t = b->next;
	if(t == NULL) return ;
	while(t != NULL) {
		t->bt--;
		if(t->bt == 0) {//如果被阻塞时间为0，转移到就绪队列中，状态改为就绪W
			t->bt = t->blocktime;
			t->state = 'W';
			printf("\t\t进程%d进入就绪状态……\n", t->name);
			PcbtoPcb(r, t);
			PcbDelete(b, t->ID);//将 被阻塞时间为0的进程从阻塞队列里删除
		}
		t = t->next;
	}
}
void PcbRun(Pcb * &r, Pcb * &b) {//进程每次只执行一个时间片
	PCB * t = r;
	if(t->next == NULL) {//如果就绪队列为空，就从阻塞队列中将优先级最高的调入就绪队列中
		printf("\t就绪队列为空，从阻塞队列中将优先级最高的调入就绪队列中\n");
		PcbtoPcb(r, b->next);
		PcbDelete(b, b->next->ID);
	}
	while(1){
		t = r->next;
		t->state = 'R';//将要执行的进程的状态改为R
		cout << "开始执行进程状态:" << endl;
		PcbDisp(r);//打印进程运行时的状态信息
		PcbDisp(b);
		t->super -= 3;
		t->rtime++;
		t->sb--;
		PcbSuper(t->next);//就绪队列的每个进程的优先数加1
		PcbBlock(r, b);//阻塞队列的每个进程的被阻塞时间减1
		if(t->rtime == t->ntime) {//如果运行时间等于需要运行的时间，运行的进程就执行完成了
			t->state = 'F';//将状态改为完成F
			cout << "执行进程结束:" << endl;
			printf("\t\t进程%d执行完成……\n\n", t->name);
			PcbDisp(r);
			PcbDelete(r, t->ID);
			return ;
		} else if(t->sb == 0) {//如果阻塞时间为0，就将进程转移到阻塞队列中
			t->state = 'B';//将状态改为阻塞B
			t->sb = t->startblock;
			printf("\t\t进程%d进入阻塞状态……\n", t->name);
			PcbtoPcb(b, t);
			PcbDelete(r, t->ID);
			break;
		}
		// else {
		//	t->state = 'W';//将状态改为就绪W
		//}
		cout << "执行进程结束状态:" << endl;
		PcbDisp(r);//打印运行结束的进程状态信息
		PcbDisp(b);
	}

}
void input(Pcb * &r) {//初始化要执行的进程
	int num;
	PCB * p;
	printf("本测试程序只需要您输入测试进程数量即可\n");
    printf("进程ID将从1开始赋值，进程运行时间，优先级等将随机赋值！\n");
    printf("程序正在打开");
    slp;
	cout << "请输入进程数以进行处理机调度测试：";
	cin >> num;
	for(int i = 0; i < num; i++) {
		p = getPcb(PCB);
		p->ID = i+1;
		p->name=i+1;
		p->state = 'W';
		p->super =  rand() % num + 1;//随机生成优先数
		p->ntime = rand() % 5 + 1;//随机生成需要运行的时间
		p->rtime = 0;//将运行时间初始化为0
		p->startblock = rand() % (p->ntime) + 1;//随机生成阻塞时间
		p->sb = p->startblock;//将阻塞时间赋给用来标记进程阻塞的时间
		p->blocktime = rand() % p->startblock + 1;//随机生成被阻塞时间
		p->bt = p->blocktime;//将被阻塞时间赋给用来标记进程被阻塞的时间
		PcbInsert(r, p);//添加到就绪队列中
	}
}
int main() {
	PCB * ready;
	PCB * block;
	PcbInit(ready);
	PcbInit(block);
	input(ready);
	int t = 0;//t用来标记CPU被调用的次数
	while(ready->next != NULL || block->next != NULL) {//当就绪队列和阻塞队列都为空时，表示所有进程都执行完成了
		printf("第%d次调用CPU\n", ++t);
		system("pause");
		PcbSort(ready);//就绪队列排序
		PcbSort(block);//阻塞队列排序
		PcbRun(ready, block);//运行进程
	}
}
