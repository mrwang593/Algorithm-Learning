#include<bits/stdc++.h>
using namespace std;
const int maxn=1025;
bool ok[maxn][maxn];
void solve(int x0,int y0,int n){
	if(n<=0) return ;
	for(int i=x0;i<x0+(1<<(n-1));i++){
		for(int j=y0;j<y0+(1<<(n-1));j++){
			ok[i][j]=false;
		}
	}
	solve(x0+(1<<(n-1)),y0,n-1);
	solve(x0,y0+(1<<(n-1)),n-1);
	solve(x0+(1<<(n-1)),y0+(1<<(n-1)),n-1);
}
int main(){
	memset(ok,true,sizeof(ok));
	int n;
	cin>>n;
	solve(1,1,n);
	for(int i=1;i<=(1<<n);i++){
		for(int j=1;j<=(1<<n);j++){
			cout<<ok[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
