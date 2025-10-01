#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c(int n,int m){
	if(m==0||n==m) return 1;
	ll res=1;
	for(int i=1;i<=m;i++){
		res=res*(n-i+1)/i;
	} 
	return res;
}
int main(){
	vector<int>s;
	s.reserve(30);
	int x;
	while(cin>>x){
		s.push_back(x) ;
	}
	int n=s.size();
	ll t=0;
	for(int i=0;i<=n-1;i++){
		t+=c(n-1,i);
	}
	ll res=0;
	for(int i:s) res+=t*i;
	cout<<res;
	return 0;
}
