#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxx = 9999;
const int maxsize = 1010;
const int dlen = 4;

class BigNum
{
private:
    int a[1000];///可以控制大数的位数
    int len;
public:
    BigNum(){len = 1;memset(a,0,sizeof(a));}
    BigNum(const long long);
    BigNum(const char*);
    BigNum(const BigNum &);
    BigNum & operator = (const BigNum &);
    friend istream& operator>>(istream & , BigNum&);
    friend ostream& operator<<(ostream & , BigNum&);

    BigNum operator + (const BigNum&)const;
    BigNum operator - (const BigNum&)const;
    BigNum operator * (const BigNum&)const;
    BigNum operator / (const int&)const;
    ///BigNum operator ^ (const BigNum&)const;

    void print(); ///输出
};

BigNum::BigNum(const long long b){
    int c,d=b;
    len=0;
    memset(a,0,sizeof(a));
    while(d>maxx){
        c = d-(d/(maxx+1))*(maxx+1);
        d = d/(maxx+1);
        a[len++]=c;
    }
    a[len++]=d;
}

BigNum::BigNum(const BigNum&T):len(T.len){
    int i;
    memset(a,0,sizeof(a));
    for(i = 0;i < len; ++i){
        a[i] = T.a[i];
    }
}

BigNum & BigNum::operator=(const BigNum &n){
    int i;
    len = n.len;
    memset(a,0,sizeof(a));
    for(i = 0;i < len; ++i){
        a[i] = n.a[i];
    }
    return *this;
}

BigNum BigNum::operator + (const BigNum &T)const{
    BigNum t(*this);
    int i;
    int big;
    big = T.len>len?T.len:len;
    for(i = 0;i < big; ++i){
        t.a[i] += T.a[i];
        if(t.a[i]>maxx){
            t.a[i+1]++;
            t.a[i] -= maxx+1;
        }
    }
    if(t.a[big]!=0)
        t.len = big+1;
    else t.len = big;
    return t;
}

BigNum BigNum::operator * (const BigNum&T)const{
    BigNum ret;
    int i, j, up;
    int temp,temp1;

    for(i = 0;i < len; ++i){
        up = 0;
        for(j = 0;j < T.len; ++j){
            temp = a[i] * T.a[j] + ret.a[i+j] + up;
            if(temp>maxx){
                temp1 = temp - temp/(maxx+1)*(maxx+1);
                up = temp/(maxx+1);
                ret.a[i+j] = temp1;
            }else{
                up = 0;
                ret.a[i+j] = temp;
            }
        }
        if(up!=0){
            ret.a[i+j] = temp;
        }
    }
    ret.len = i+j;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--;
    return ret;
}

BigNum BigNum::operator/(const int &b)const{
    BigNum ret;
    int i,down = 0;
    for(i = len-1;i >= 0; --i){
        ret.a[i] = (a[i] + down*(maxx + 1))/b;
        down = a[i] + down*(maxx + 1) - ret.a[i]*b;
    }
    ret.len = len;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--;
    return ret;
}

istream & operator>>(istream &in,BigNum &b){
    char str[maxsize*4];
    int i = -1;
    in>>str;
    int len = strlen(str);
    int count = 0;
    int sum = 0;
    for(i = len-1;i>=0;){
        sum = 0;
        int t = 1;
        for(int j = 0;j < 4 && i >= 0; ++j,--i,t*=10){
            sum += (str[i]-'0')*t;
        }
        b.a[count] = sum;
        count++;
    }
    b.len = count++;
    return in;
}

void BigNum::print(){
    int i;
    printf("%d",a[len-1]);
    for(i = len-2;i >= 0; --i){
        printf("%04d",a[i]);
    }
    printf("\n");
}

int main(){
    int T;
    int o = 1;
    long long n;
    cin>>T;
    while(T--){
        scanf("%I64d",&n);
        BigNum ans;
        long long now = n;
        long long p, q, mid;

        for(long long i = 2;i <= n; ++i){
            mid = n/i;
            if(mid+1 == now) break;
            p = n%now;
            q = n%(mid+1);


            ///cout<<p<<endl;
            ///cout<<q<<endl;

            BigNum P(p+q),Q(now-mid);
            BigNum sum(BigNum(P*Q/2));
            ans = ans + sum;
            now = mid;
        }
        for(long long i = 1;i <= now; ++i){
            ans = ans + BigNum(n%i);
        }
        printf("Case %d:",o++);
        ans.print();
    }
    return 0;
}
