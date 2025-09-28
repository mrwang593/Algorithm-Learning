#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int>t,c;
bool check(int mid){
	long long need=0;
	for(int i=1;i<=n;i++){
		if(t[i]<=mid) continue;
		need+=(t[i]-mid)*c[i];
	}
	return need<=m;
}
int main(){
	cin>>n>>m>>k;
	t.resize(n+1),c.resize(n+1);
	for(int i=1;i<=n;i++) cin>>t[i]>>c[i];
	int l=k,r=1e5;
	int ans=-1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
 	return 0;
} 
