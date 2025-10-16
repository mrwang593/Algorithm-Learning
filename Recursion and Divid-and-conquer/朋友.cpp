#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int p1[maxn],rk1[maxn];
int p2[maxn],rk2[maxn];
void init(int p[],int rk[],int n){
	for(int i=1;i<=n;i++) p[i]=i,rk[i]=1;
}
int Find(int x,int p[],int rk[]){
	if(p[x]==x) return x;
	else return p[x]=Find(p[x],p,rk);
}
void Union(int x,int y,int p[],int rk[]){
	int rt1=Find(x,p,rk);
	int rt2=Find(y,p,rk);
	if(rt1!=rt2){
		if(rk[rt1]>rk[rt2]){
			p[rt2]=rt1;
		} 
		else if(rk[rt2]>rk[rt1]){
			p[rt1]=rt2;
		}
		else {
			p[rt1]=rt2;
			rk[rt2]++;
		}
	}
}
int main(){
	int n,m,p,q;
	cin>>n>>m>>p>>q;
	init(p1,rk1,n);
	init(p2,rk2,m);
	
	while(p--){
		int x,y;
		cin>>x>>y;
		if(x<0) x=-x,y=-y;
		Union(x,y,p1,rk1);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x<0) x=-x,y=-y;
		Union(x,y,p2,rk2);
	}
	int cnt1=0,cnt2=0;;
	for(int i=1;i<=n;i++){
		if(Find(i,p1,rk1)==Find(1,p1,rk1)) cnt1++;
	}
	for(int i=1;i<=m;i++){
		if(Find(i,p2,rk2)==Find(1,p2,rk2))cnt2++;
	}
	cout<<min(cnt1,cnt2);
	return 0;
} 
