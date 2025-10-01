#include<bits/stdc++.h>
using namespace std;
const int NX=1025;
const int NY=2049 ;
char a[NX][NY]={' '};
void f(int l,int h,int n){
	if(n==1){
		int y=2;
		int x=1;
		a[x][y+1]='/';
		a[x][y+2]='\\' ;
		a[x+1][y-2]='/';
		a[x+1][y+3]='\\';
		a[x+2][y]=a[x+2][y+1]='_';
		return ; 
	}
	f(l+(1<<(n-1)),h,n-1);
	f(l,h+(1<<(n-1)),n-1);
	f(1+(1<<n),h+(1<<(n-1)),n-1);
}
int main(){
	int n;
	cin>>n;
	f(0,0,n);
	for(int i=1;i<=(1<<n);i++){
		for(int j=1;j<=(1<<(n+1));j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
} 
