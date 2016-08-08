#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#define eps 1e-8
using  namespace std;

int main(){
	int kis[4]= {6,2,4,8};
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(!n){
			cout<<"1 1"<<endl;
			continue;
		}
		double ans = ((log10(2.0))*n);
		ans -= floor(ans);
		ans = floor(pow(10.0,ans) + eps);
		printf("%.f %d\n",ans,kis[n%4]);
	}
	return 0;
}
