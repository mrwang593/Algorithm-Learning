#include<bits/stdc++.h>
using namespace std;
void solve(int k,int x,int y,int x0,int y0){//������ͼ�е����е�λ�ã��Լ�ͼ�����Ͻ�����
	if(k==0) return ; 
	int dx=x-x0+1,dy=y-y0+1;//ת��Ϊ��Сͼ�ϵ����� 
	int m=1<<(k-1);
	if(dx<=m&&dy<=m){//���Ͻ� 
		cout<<x0+m<<" "<<y0+m<<" "<<1<<endl;
		solve(k-1,x,y,x0,y0);
		solve(k-1,x0+m-1,y0+m,x0,y0+m);//���Ͻ� 
		solve(k-1,x0+m,y0+m-1,x0+m,y0);
		solve(k-1,x0+m,y0+m,x0+m,y0+m); 
	}
	else if(dx<=m&&dy>m){//���Ͻ� 
		cout<<x0+m<<" "<<y0+m-1<<" "<<2<<endl;
		solve(k-1,x0+m-1,y0+m-1,x0,y0);
		solve(k-1,x,y,x0,y0+m);
		solve(k-1,x0+m,y0+m-1,x0+m,y0);
		solve(k-1,x0+m,y0+m,x0+m,y0+m); 
	}
	else if(dx>m&&dy<=m){//���½� 
		cout<<x0+m-1<<" "<<y0+m<<" "<<3<<endl;
		solve(k-1,x0+m-1,y0+m-1,x0,y0);
		solve(k-1,x0+m-1,y0+m,x0,y0+m);
		solve(k-1,x,y,x0+m,y0);
		solve(k-1,x0+m,y0+m,x0+m,y0+m); 
	}
	else{//���½� 
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
