#include<bits/stdc++.h>
using namespace std;
struct T{
	int li,ri,lt,rt;
};
vector<T>t;
vector<int>p;
int solve(int i){
	if(i==0) return 0;
	int l=solve(t[i].lt);
	int r=solve(t[i].rt);
	if(l==0&&r==0){
		return (t[i].li+t[i].ri)/__gcd(t[i].li,t[i].ri);
	}
	else if(l==0&&r!=0){
		int fz=r*(t[i].li+t[i].ri);
		int fm=t[i].li;
		return fz/__gcd(fz,fm);
	}
	else if(l!=0&&r==0){
		int fz=l*(t[i].li+t[i].ri);
		int fm=t[i].ri;
		return fz/__gcd(fz,fm);
	}
	else{
		long long li=t[i].li,ri=t[i].ri;
		
		long long m=li*l*ri*r/__gcd(li*l,ri*r);
		return m/li+m/ri;
	}
}
int main(){
	int n;
	cin>>n;
	t.resize(n+1);
	p.resize(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>t[i].li>>t[i].ri>>t[i].lt>>t[i].rt;
		p[t[i].lt]=p[t[i].rt]=i;
	}
	int rt=-1;
	for(int i=1;i<=n;i++){
		if(p[i]==0) rt=i;
	}
	int res=solve(rt);
	cout<<res;
	return 0;
} 
