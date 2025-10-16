#include<bits/stdc++.h>
using namespace std;
vector<long long>a,prefix;
bool solve(int l,int r){
	if(l==r) return true;
	for(int i=l;i<=r;i++){
		long long suml=prefix[i]-prefix[l-1];
		long long sumr=prefix[r]-prefix[i];
		if(suml-sumr>=0&&suml-sumr<=1) {
			if(solve(l,i)&&solve(i+1,r)) return true;
		}
	}
	return false;
}
int main(){
	long long  n;
	cin>>n;
	a.resize(n+1);
	prefix.resize(n+1,0);
	for(int i=1;i<=n;i++) cin>>a[i],prefix[i]=prefix[i-1]+a[i]; 
	if(solve(1,n))
		cout<<"Yes";
	else cout<<"No";
	return 0;
} 
