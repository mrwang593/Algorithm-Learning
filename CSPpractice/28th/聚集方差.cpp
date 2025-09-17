#include<bits/stdc++.h>
using namespace std;
long long f(long long x,long long y){
	return (x-y)*(x-y);
}
inline void print(long long x){
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
int main(){
	int n;
	cin>>n;
	vector<int>p(n+1,-1),v(n+1);
	vector<vector<int>>child(n+1);
	for(int i=2;i<=n;i++){
		cin>>p[i];
		child[p[i]].push_back(i);
	}
	for(int i=1;i<=n;i++) cin>>v[i]; 
	vector<multiset<long long>>vs(n+1);
	vector<long long>res(n+1,0);
	for(int i=n;i>=1;i--){
		for(int j:child[i]){
			for(int u:vs[j]) vs[i].insert(u);
		}
		vs[i].insert(v[i]);
		if(vs[i].size()==1) res[i]==0;
		else{

			for(auto it=vs[i].begin();it!=vs[i].end();it++){
				long long l=it==vs[i].begin()?LLONG_MAX:f(*it,*prev(it));
				long long r=next(it)==vs[i].end()?LLONG_MAX:f(*it,*next(it));//数据类型的选择尤为重要 
				res[i]+=min(l,r);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int v:vs[i])cout<<v;
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++) print(res[i]),putchar('\n');
	return 0;
} 
