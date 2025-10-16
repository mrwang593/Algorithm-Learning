#include<bits/stdc++.h>
using namespace std;
int a[4][4];
int vis[4][4]={false}; 
int res=10;
int dx[]={-1,1,0,0,0};
int dy[]={0,0,-1,1,0};
bool check(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(!a[i][j])return false;
		}
	}
	return true;
}
void change(int x,int y){
	for(int i=0;i<=4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>3||ny<0||ny>3)continue;
		a[nx][ny]=1-a[nx][ny];
	} 
}
void dfs(int tot){
//	if(tot>=res)return ; //剪枝的重要性 
	if(check()) {  //最后可能达不到全亮 
		res=min(res,tot);
		return ;
	}
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(!a[i][j]&&!vis[i][j]){
				vis[i][j]=true;
				change(i,j);
				dfs(tot+1);
				change(i,j);
				vis[i][j]=false;
			}
		}
	}
}
int main(){
	
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	dfs(0);
	cout<<res;
	return 0;
} 
