#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>q(8,vector<int>(8));
vector<vector<int>>m(8,vector<int>(8,0));
vector<vector<double>>mp(8,vector<double>(8,0));
int n,T;
vector<int>a;
void f3(){
	int step=0;
	int now=0;
	while(now<n){
		int k=step%2;
		if(k==0){//往右上方向走 
			if(step<=7){
				for(int i=step;i>=0&&now<n;i--){
					m[i][step-i]=a[now];
					now++;
				}
			}
			else{
				for(int i=7;i>=(step-7)&&now<n;i--){
					m[i][step-i]=a[now];
					now++;
				}
			}
			
		}
		else{//往坐下方向走 
			if(step<=7){
				for(int j=step;j>=0&&now<n;j--){
					m[step-j][j]=a[now];
					now++;
				} 
			}
			else{
				for(int j=7;j>=(step-7)&&now<n;j--){
					m[step-j][j]=a[now];
					now++;
				}
			}
			
		}
		step++;
	}
}
void f4(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			m[i][j]*=q[i][j];
		}
	}
}
void f5(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			for(int u=0;u<8;u++){
				for(int v=0;v<8;v++){
					double au,av;
					if(u==0) au=sqrt(0.5);
					else au=1;
					if(v==0) av=sqrt(0.5);
					else av=1;
					mp[i][j]+=au*av*(double)m[u][v]*cos(acos(-1)/8*(0.5+i)*u)*cos(acos(-1)/8*(0.5+j)*v);
				 
				}
			}
			mp[i][j]/=4;
			mp[i][j]=round(mp[i][j]+128);
			if(mp[i][j]+1e-6>255) mp[i][j]=255;
			else if(mp[i][j]-1e-6<0) mp[i][j]=0;
			cout<<(int)mp[i][j]<<" ";
		}
		cout<<"\n";
	} 
}
int main(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>q[i][j];
		}
	}
	cin>>n>>T;
	a.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	if(T==0){
		f3();
		
	}else if(T==1){
		f3();
		f4();
	}
	else{
		f3();
		f4();
		f5();
		return 0; 
	}
	for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cout<<m[i][j]<<" ";
			}
			cout<<"\n";
	}
	return 0;
}
/*
16 11 10 16 24 40 51 61
12 12 14 19 26 58 60 55
14 13 16 24 40 57 69 56
14 17 22 29 51 87 80 62
18 22 37 56 68 109 103 77
24 35 55 64 81 104 113 92
49 64 78 87 103 121 120 101
72 92 95 98 112 100 103 99
26
1
-26 -3 0 -3 -2 -6 2 -4 1 -3 1 1 5 1 2 -1 1 -1 2 0 0 0 0 0 -1 -1

*/
