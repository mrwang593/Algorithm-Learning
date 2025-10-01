#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll fast_pow(int a,int b,int p){
	a%=p;
	ll res=1;
	while(b){
		if(b&1) res=(res*a)%p;
		a=(1ll*a*a)%p;
		b>>=1; 
	}
	return res;
}
int main(){
	int a,b,p;
	cin>>a>>b>>p;
	int res=fast_pow(a,b,p);
	cout<<a<<"^"<<b<<" mod "<<p<<"="<<res;
	return 0;
} 
