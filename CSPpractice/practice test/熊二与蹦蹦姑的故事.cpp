#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,p;
	cin>>n>>p;
	vector<int>a(n);
	for(int i=1;i<n;i++) cin>>a[i];	
	queue<int>q;
	vector<bool>vis(n+1,false);
	for(int i=1;i<=p;i++){
		q.push(i);
		vis[i]=true;
		if(i==n){
			cout<<1;
			return 0;
		}
	}
	int step=1;
	while(!q.empty()){
		int s=q.size();
		for(int i=0;i<s;i++){
			int u=q.front();
			q.pop();
			int nu=u+a[u];
			if(nu==n){
				cout<<step+1;
				return 0;
			}
			if(nu>n) continue;
			if(!vis[nu]){
				vis[nu]=true;
				q.push(nu);
			}
			nu=u-a[u];
			if(nu<0) continue;
			if(!vis[nu]){
				vis[nu]=true;
				q.push(nu);
			}
		}
		step++; 
	}
	cout<<-1;
	return 0;
} 
