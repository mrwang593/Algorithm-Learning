#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>>q,k,v;
vector<ll>w;
ll n,d;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void print(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	} 
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
void init(vector<vector<ll>>&q){
	for(ll i=0;i<n;i++){
		for(ll j=0;j<d;j++){
			q[i][j]=read();
		}
	}
}
void f(vector<vector<ll>>&x){
	vector<vector<ll>>y(d,vector<ll>(n));
	for(ll i=0;i<d;i++){
		for(ll j=0;j<n;j++){
			y[i][j]=x[j][i];
		} 
	}
	x=y;
}
vector<vector<ll>> multiply(vector<vector<ll>>&q,vector<vector<ll>>&k){
	ll l1=q.size(),r1=q[0].size();
	ll l2=k.size(),r2=k[0].size();
	vector<vector<ll>>res(l1,vector<ll>(r2,0));
	for( ll i=0;i<l1;i++){
		for(ll j=0;j<r2;j++){
			for(ll m=0;m<r1;m++){
					res[i][j]+=q[i][m]*k[m][j];
			}
		}
	}
	return res; 
}
int main(){
	n=read(),d=read();
	q.resize(n,vector<ll>(d)),k.resize(n,vector<ll>(d)),v.resize(n,vector<ll>(d));
	w.resize(n);
	init(q);
	init(k);
	init(v);
	for(ll i=0;i<n;i++) w[i]=read();
	f(k);
	vector<vector<ll>>tmp1=multiply(k,v);
	vector<vector<ll>>res=multiply(q,tmp1);
	for(ll i=0;i<n;i++){
		for(ll j=0;j<d;j++){
			res[i][j]*=w[i]; 
			print(res[i][j]);putchar(' ');
		}
		putchar('\n');
	}
	return 0;
} 
