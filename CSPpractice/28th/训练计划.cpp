#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>pre(m+1),t(m+1);//
	vector<vector<int>>nxt(m+1);
	for(int i=1;i<=m;i++){
		cin>>pre[i];
		if(pre[i]!=0){
			nxt[pre[i]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++) cin>>t[i];
	bool ok=true;
	vector<int>l(m+1),r(m+1,-1);
	for(int i=1;i<=m;i++) {
		if(pre[i]==0) l[i]=1;
		else{
			l[i]=l[pre[i]]+t[pre[i]];
			if(t[i]+l[i]-1>n) ok=false;
		}
		cout<<l[i]<<" ";
	}
	cout<<"\n";
	if(ok){//前驱只可能有一个,但后驱可能有多个 
		for(int i=m;i>=1;i--){
			if(nxt[i].empty()) r[i]=n-t[i]+1;
			else {
				int tmp=INT_MAX;
				for(int j:nxt[i]){
					tmp=min(r[j]-t[i],tmp);
				}
				r[i]=tmp;
			}
		}
		for(int i=1;i<=m;i++) cout<<r[i]<<" ";
	}
	return 0;
} 
