#include<bits/stdc++.h>
using namespace std;
vector<int>p;
vector<vector<int>>child;
vector<bool>has;
void dfs(int par,int &cnt){
	has[par]=false;
	cnt++;
	for(int v:child[par]){
		if(has[v]){
			dfs(v,cnt);
		}	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	p.resize(n,-1);
	child.resize(n);
	for(int i=1;i<n;i++){
		int x;
		cin>>x;
		p[i]=x;
		child[x].push_back(i);
	}
	has.resize(n,false);
	int q;
	cin>>q;
	while(q--){
		string op;
		int id;
		cin>>op>>id;
		if(op=="install"){
			int cnt=0;
			while(!has[id]){
				has[id]=true;
				cnt++;
				if(p[id]!=-1) id=p[id];
				else break;
			}
			cout<<cnt<<"\n";
		}
		else{
			int cnt=0;
			dfs(id,cnt);
			cout<<cnt<<"\n";
		}
	}
	return 0;
} 
