#include<bits/stdc++.h>
using namespace std;
vector<int>cnt;
vector<vector<int>>a;
vector<int>inDegree,dp,pre;
int main(){
	int n;
	cin>>n;
	cnt.resize(n+1);
	for(int i=1;i<=n;i++) cin>>cnt[i];
	a.resize(n+1);
	inDegree.resize(n+1,0);
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			int x; cin>>x;
			if(x) a[i].push_back(j),inDegree[j]++;
		}
	}
	dp.resize(n+1,-1);
	pre.resize(n+1,-1);
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(inDegree[i]==0){
			q.push(i);
			dp[i]=cnt[i];
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:a[u]){
			if(cnt[v]+dp[u]>dp[v]){
				pre[v]=u;
				dp[v]=cnt[v]+dp[u];
			}
			inDegree[v]--;
			if(inDegree[v]==0) q.push(v);
		}
	}
	int maxm=-1,endNode=-1;
	for(int i=1;i<=n;i++) {
		if(dp[i]>maxm){
			maxm=dp[i];
			endNode=i;
		}
	}
	vector<int>path;
	while(endNode!=-1){
		path.push_back(endNode);
		endNode=pre[endNode];
	}
	reverse(path.begin(),path.end());
	for(int v:path)cout<<v<<" ";
	cout<<"\n";
	cout<<maxm;
	return 0;
}