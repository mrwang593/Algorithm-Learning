#include<bits/stdc++.h>
using namespace std;
void solve(int n){
	vector<int>a;
	int cnt=0;
	while(n){
		if(n&1) a.push_back(cnt);
		cnt++;
		n>>=1;
	}
	reverse(a.begin(),a.end());
	int m=a.size();
	for(int i=0;i<m;i++){
		cout<<2;
		if(a[i]!=1)cout<<"(";
		if(a[i]==0)cout<<"0";
		else if(a[i]>1)solve(a[i]);
		if(a[i]!=1)cout<<")";
		if(i!=m-1)cout<<"+";
	}
}
int main(){
	int n;
	cin>>n;
	solve(n); 
	return 0;
} 
