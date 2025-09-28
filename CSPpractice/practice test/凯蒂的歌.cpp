#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int>d(n+1);
	d[1]=a[1];
	int tot=0;
	if(n==1){
		cout<<0<<" "<<0;
		return 0;
	}
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1]; 
		tot+=abs(d[i]);
	}
	int maxm=-1,minm=INT_MAX;//两个小点酿成大错 
	maxm=max(maxm,tot-abs(d[2])+abs(d[2]+k));
	maxm=max(maxm,tot-abs(d[2])+abs(d[2]-k));//
	minm=min(minm,tot-abs(d[2])+abs(d[2]+k));
	minm=min(minm,tot-abs(d[2])+abs(d[2]-k));
	maxm=max(maxm,tot-abs(d[n])+abs(d[n]+k));
	maxm=max(maxm,tot-abs(d[n])+abs(d[n]-k));
	minm=min(minm,tot-abs(d[n])+abs(d[n]+k));
	minm=min(minm,tot-abs(d[n])+abs(d[n]-k));
	for(int i=2;i<n;i++){
		maxm=max(maxm,tot-abs(d[i])-abs(d[i+1])+abs(d[i]+k)+abs(d[i+1]-k));
		maxm=max(maxm,tot-abs(d[i])-abs(d[i+1])+abs(d[i]-k)+abs(d[i+1]+k));
		minm=min(minm,tot-abs(d[i])-abs(d[i+1])+abs(d[i]+k)+abs(d[i+1]-k));
		minm=min(minm,tot-abs(d[i])-abs(d[i+1])+abs(d[i]-k)+abs(d[i+1]+k));
	}
	cout<<maxm<<" "<<minm;
	return 0;
} 
