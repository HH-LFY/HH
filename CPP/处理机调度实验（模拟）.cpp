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
	int ID;//����ID
	int name;//��������
	char state;//����״̬
	int super;//������
	int ntime;//��Ҫ����ʱ��
	int rtime;//����CPUʱ��
	int startblock;//��������ʱ��
	int sb;//������ǽ���������ʱ��
	int blocktime;//���̱�������ʱ��
	int bt;//������ǽ��̱�������ʱ��
	struct Pcb *next;//��һ������
} PCB;
void PcbInit(PCB * &p) {//��ʼ������
	p = getPcb(PCB);//����һ���ս��̣���Ϊ���е�ͷ�ڵ㣬ͷ�ڵ��������
	p->next = NULL;//��ͷ������һ�����̱��Ϊ��
}
void PcbInsert(Pcb * &r, Pcb * p) {//���������������һ���µĽ���
	Pcb * t = r;
	while(t->next != NULL) {//�ҵ���������������һ������
		t = t->next;
	}
	p->next = t->next;//���µĽ�����ӵ��������ж�β
	t->next = p;
}
void PcbDisp(PCB * L) {//��ʾ����״̬��Ϣ
    PCB *p = L->next;
    if(p == NULL) return ;
    printf("��������     ����״̬     ��Ҫ��ʱ     ����ʱ��      ����ʱ��   ������\n");
    while(p != NULL) {
        printf("   %d        \t%c       \t%d      \t%d      \t\t%d    \t%d\n", p->name, p->state, p->ntime, p->rtime,p->startblock,p->super);
        p = p->next;
    }
    printf("\n");
}
void PcbDelete(Pcb * &r, int des) {//�Ӷ�����ɾ��һ������
	PCB * t = r, * p, *q;
	while(t != NULL && t->ID != des) {//�ҵ�Ҫɾ���Ľ���
		q = t;
		t = t->next;
	}
	if(t == NULL) return ;
	p = t->next;
	q->next = p;
	free(t);
}
void PcbSort(PCB * &r) {//�Զ��н�����������
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
void PcbtoPcb(Pcb * &r, Pcb * p) {//��һ�����̴�һ������ת�Ƶ���һ������
	PCB * t = r;
	PCB * s = getPcb(PCB);//����һ����ʱ����
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
	while(t->next != NULL) {//�ҵ�Ҫ��ӽ��̶��е����һ������
		t = t->next;
	}
	t->next = s;//��������ӵ�������
}
void PcbSuper(Pcb * &r) {//�����������ÿ��������������1
	PCB * t = r;
	if(t == NULL) return ;
	while(t != NULL) {
		t->super++;
		t = t->next;
	}
}
void PcbBlock(PCB * &r, PCB * &b) {//���̽�������״̬��,ûִ��һ��ʱ��Ƭ��������ʱ���1
	PCB * t = b->next;
	if(t == NULL) return ;
	while(t != NULL) {
		t->bt--;
		if(t->bt == 0) {//���������ʱ��Ϊ0��ת�Ƶ����������У�״̬��Ϊ����W
			t->bt = t->blocktime;
			t->state = 'W';
			printf("\t\t����%d�������״̬����\n", t->name);
			PcbtoPcb(r, t);
			PcbDelete(b, t->ID);//�� ������ʱ��Ϊ0�Ľ��̴�����������ɾ��
		}
		t = t->next;
	}
}
void PcbRun(Pcb * &r, Pcb * &b) {//����ÿ��ִֻ��һ��ʱ��Ƭ
	PCB * t = r;
	if(t->next == NULL) {//�����������Ϊ�գ��ʹ����������н����ȼ���ߵĵ������������
		printf("\t��������Ϊ�գ������������н����ȼ���ߵĵ������������\n");
		PcbtoPcb(r, b->next);
		PcbDelete(b, b->next->ID);
	}
	while(1){
		t = r->next;
		t->state = 'R';//��Ҫִ�еĽ��̵�״̬��ΪR
		cout << "��ʼִ�н���״̬:" << endl;
		PcbDisp(r);//��ӡ��������ʱ��״̬��Ϣ
		PcbDisp(b);
		t->super -= 3;
		t->rtime++;
		t->sb--;
		PcbSuper(t->next);//�������е�ÿ�����̵���������1
		PcbBlock(r, b);//�������е�ÿ�����̵ı�����ʱ���1
		if(t->rtime == t->ntime) {//�������ʱ�������Ҫ���е�ʱ�䣬���еĽ��̾�ִ�������
			t->state = 'F';//��״̬��Ϊ���F
			cout << "ִ�н��̽���:" << endl;
			printf("\t\t����%dִ����ɡ���\n\n", t->name);
			PcbDisp(r);
			PcbDelete(r, t->ID);
			return ;
		} else if(t->sb == 0) {//�������ʱ��Ϊ0���ͽ�����ת�Ƶ�����������
			t->state = 'B';//��״̬��Ϊ����B
			t->sb = t->startblock;
			printf("\t\t����%d��������״̬����\n", t->name);
			PcbtoPcb(b, t);
			PcbDelete(r, t->ID);
			break;
		}
		// else {
		//	t->state = 'W';//��״̬��Ϊ����W
		//}
		cout << "ִ�н��̽���״̬:" << endl;
		PcbDisp(r);//��ӡ���н����Ľ���״̬��Ϣ
		PcbDisp(b);
	}

}
void input(Pcb * &r) {//��ʼ��Ҫִ�еĽ���
	int num;
	PCB * p;
	printf("�����Գ���ֻ��Ҫ��������Խ�����������\n");
    printf("����ID����1��ʼ��ֵ����������ʱ�䣬���ȼ��Ƚ������ֵ��\n");
    printf("�������ڴ�");
    slp;
	cout << "������������Խ��д�������Ȳ��ԣ�";
	cin >> num;
	for(int i = 0; i < num; i++) {
		p = getPcb(PCB);
		p->ID = i+1;
		p->name=i+1;
		p->state = 'W';
		p->super =  rand() % num + 1;//�������������
		p->ntime = rand() % 5 + 1;//���������Ҫ���е�ʱ��
		p->rtime = 0;//������ʱ���ʼ��Ϊ0
		p->startblock = rand() % (p->ntime) + 1;//�����������ʱ��
		p->sb = p->startblock;//������ʱ�丳��������ǽ���������ʱ��
		p->blocktime = rand() % p->startblock + 1;//������ɱ�����ʱ��
		p->bt = p->blocktime;//��������ʱ�丳��������ǽ��̱�������ʱ��
		PcbInsert(r, p);//��ӵ�����������
	}
}
int main() {
	PCB * ready;
	PCB * block;
	PcbInit(ready);
	PcbInit(block);
	input(ready);
	int t = 0;//t�������CPU�����õĴ���
	while(ready->next != NULL || block->next != NULL) {//���������к��������ж�Ϊ��ʱ����ʾ���н��̶�ִ�������
		printf("��%d�ε���CPU\n", ++t);
		system("pause");
		PcbSort(ready);//������������
		PcbSort(block);//������������
		PcbRun(ready, block);//���н���
	}
}
