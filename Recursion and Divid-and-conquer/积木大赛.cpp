#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long res=0;
	int last=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x>=last) res+=x-last;
		last=x;
	}
	cout<<res;
	return 0;
} 
