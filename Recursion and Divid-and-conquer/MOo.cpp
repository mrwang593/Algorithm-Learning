#include<bits/stdc++.h>
using namespace std;
vector<long long>a;
char f(int n,int i){
	if(i==0){
		string s=" moo";
		return s[n];
	}
	if(n<=a[i-1]) return f(n,i-1);
	else if(n>a[i-1]&&n<=a[i-1]+i+3){
		n-=a[i-1];
		string t=" m";
		for(int j=0;j<i+2;j++)t+="o";
		return t[n];
	}
	else{
		n-=a[i-1]+i+3;
		return f(n,i-1);
	}
}
int main(){
	int n;
	cin>>n;
	a.resize(31,0);
	a[0]=3;
	int i;
	for(i=1;i<=30;i++){
		a[i]=2*a[i-1]+a[0]+i;
		if(a[i]>=n) break;
	}
	char res=f(n,i);
	cout<<res;
	return 0;
} 
