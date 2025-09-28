#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	int res=0,x1,y1,x2,y2;
	for(int i=0;i<n;i++){
		cin>>x1>>y1>>x2>>y2;
		if(x1>=a||x2<=0||y1>=b||y2<=0) continue;
		x1=max(x1,0);
		x2=min(a,x2);
		y1=max(0,y1);
		y2=min(b,y2);
		res+=(x2-x1)*(y2-y1); 
	}
	cout<<res;
	
	return 0;
} 
