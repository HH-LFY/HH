#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#define PI acos(-1.0)
#define eps 1e-8
const int  inf =  (1<<30) - 10;
using namespace std;

struct Map{
    int m[4][4];
    int x1,x2,y1,y2;
    int num;
    int now;
    Map& operator= (Map& a){
        for(int i = 0;i < 4; ++i)
            for(int j = 0;j < 4; ++j)
                m[i][j] = a.m[i][j];
        x1 = a.x1;
        x2 = a.x2;
        y1 = a.y1;
        y2 = a.y2;
        num = a.num;
        now = a.now;
        return *this;
    }
}p[600009];
Map temp;
const int MOD = 43046747;
bool Hash[MOD];

int ok(int k){
    for(int i = 0;i < 4; ++i){
        if((p[k].m[i][0] == p[k].m[i][1] && p[k].m[i][0] == p[k].m[i][2] && p[k].m[i][0] == p[k].m[i][3]) ||
           (p[k].m[0][i] == p[k].m[1][i] && p[k].m[0][i] == p[k].m[2][i] && p[k].m[0][i] == p[k].m[3][i]))
            return 1;
    }
    if(p[k].m[0][0] == p[k].m[1][1] &&
       p[k].m[0][0] == p[k].m[2][2] &&
       p[k].m[0][0] == p[k].m[3][3] )
       return 1;
    if(p[k].m[0][3] == p[k].m[1][2] &&
       p[k].m[0][3] == p[k].m[2][1] &&
       p[k].m[0][3] == p[k].m[3][0] )
       return 1;
    return 0;
}

void swap(int x,int y,int xx,int yy,int know){
    temp.m[x][y] = temp.m[xx][yy];
    temp.m[xx][yy] = 0;
    if(know == 1) {
        temp.x1 = xx;
        temp.y1 = yy;
    }else{
        temp.x2 = xx;
        temp.y2 = yy;
    }
    temp.now = temp.m[x][y];
}

int hash(Map kk){
    long long value = 0;
    long long k = 1;
    for(int i = 0;i < 4; ++i){
        for(int j = 0;j < 4; ++j){
            value += k*kk.m[i][j];
            k *= 3;
        }
    }
    value %= MOD;
    if(Hash[value]){
        return 0;
    }
    Hash[value] = 1;
    return 1;
}

void BFS(){
    int front = 0;
    int rear = 1;
    int x1,x2,y1,y2;
    while(front != rear){
        if(ok(front)){
            cout<<p[front].num<<endl;
            break;
        }

        p[front].num++;
        x1 = p[front].x1;
        x2 = p[front].x2;
        y1 = p[front].y1;
        y2 = p[front].y2;

        if(x1 > 0 && p[front].m[x1 - 1][y1] != p[front].now){
            temp = p[front];
            swap(x1,y1,x1-1,y1,1);
            if(hash(temp)){
                p[rear++] = temp;
            }
        }
        if(x1 < 3 && p[front].m[x1 + 1][y1] != p[front].now){
            temp = p[front];
            swap(x1,y1,x1+1,y1,1);
            if(hash(temp)){
                p[rear++] = temp;
            }
        }
        if(y1 > 0 && p[front].m[x1][y1 - 1] != p[front].now){
            temp = p[front];
            swap(x1,y1,x1,y1-1,1);
            if(hash(temp)){
                p[rear++] = temp;
            }
        }
        if(y1 < 3 && p[front].m[x1][y1 + 1] != p[front].now){
            temp = p[front];
            swap(x1,y1,x1,y1+1,1);
            if(hash(temp)){
                p[rear++] = temp;
            }
        }


        if(x2 > 0 && p[front].m[x2 - 1][y2] != p[front].now){
            temp = p[front];
            swap(x2,y2,x2-1,y2,2);
            if(hash(temp)){
                p[rear++] = temp;
            }
        }
        if(x2 < 3 && p[front].m[x2 + 1][y2] != p[front].now){
            temp = p[front];
            swap(x2,y2,x2+1,y2,2);
            if(hash(temp)){
                p[rear++] = temp;
            }
        }
        if(y2 > 0 && p[front].m[x2][y2 - 1] != p[front].now){
            temp = p[front];
            swap(x2,y2,x2,y2-1,2);
            if(hash(temp)){
                p[rear++] = temp;
            }
        }
       if(y2 < 3 && p[front].m[x2][y2 + 1] != p[front].now){
            temp = p[front];
            swap(x2,y2,x2,y2+1,2);
            if(hash(temp)){
                p[rear++] = temp;
            }
        }
        front++;
    }
}

void show(int kk){
    for(int i = 0;i < 4; ++i){
        for(int j = 0;j < 4; ++j){
            printf("%d",p[kk].m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char c;
    int flag = 1;
    for(int i = 0;i < 4; ++i){
        for(int j = 0;j < 4; ++j){
            cin>>c;
            if(c == 'B'){
                p[0].m[i][j] = 2;
            }else if(c == 'W'){
                p[0].m[i][j] = 1;
            }else if(c == 'O'){
                if(flag){
                    flag = !flag;
                    p[0].x1 = i;
                    p[0].y1 = j;
                }else{
                    p[0].x2 = i;
                    p[0].y2 = j;
                }
            }
        }
        ///getchar();
    }
    //show(0);
    p[0].num = 0;
    p[0].now = 0;
    BFS();
    return 0;
}
