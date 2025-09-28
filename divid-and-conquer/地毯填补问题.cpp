#include<bits/stdc++.h>
using namespace std;
void solve(int k,int x,int y,int x0,int y0){//在这张图中的已有的位置，以及图的左上角坐标
	if(k==0) return ; 
	int dx=x-x0+1,dy=y-y0+1;//转换为在小图上的坐标 
	int m=1<<(k-1);
	if(dx<=m&&dy<=m){//左上角 
		cout<<x0+m<<" "<<y0+m<<" "<<1<<endl;
		solve(k-1,x,y,x0,y0);
		solve(k-1,x0+m-1,y0+m,x0,y0+m);//右上角 
		solve(k-1,x0+m,y0+m-1,x0+m,y0);
		solve(k-1,x0+m,y0+m,x0+m,y0+m); 
	}
	else if(dx<=m&&dy>m){//右上角 
		cout<<x0+m<<" "<<y0+m-1<<" "<<2<<endl;
		solve(k-1,x0+m-1,y0+m-1,x0,y0);
		solve(k-1,x,y,x0,y0+m);
		solve(k-1,x0+m,y0+m-1,x0+m,y0);
		solve(k-1,x0+m,y0+m,x0+m,y0+m); 
	}
	else if(dx>m&&dy<=m){//左下角 
		cout<<x0+m-1<<" "<<y0+m<<" "<<3<<endl;
		solve(k-1,x0+m-1,y0+m-1,x0,y0);
		solve(k-1,x0+m-1,y0+m,x0,y0+m);
		solve(k-1,x,y,x0+m,y0);
		solve(k-1,x0+m,y0+m,x0+m,y0+m); 
	}
	else{//右下角 
		cout<<x0+m-1<<" "<<y0+m-1<<" "<<4<<endl;
		solve(k-1,x0+m-1,y0+m-1,x0,y0);
		solve(k-1,x0+m-1,y0+m,x0,y0+m);
		solve(k-1,x0+m,y0+m-1,x0+m,y0);
		solve(k-1,x,y,x0+m,y0+m);
	}
	
}
int main(){
	int k,x,y;
	cin>>k>>x>>y;
	solve(k,x,y,1,1); 
	return 0;
}
