#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a;
bool check(int mid){
	int tmp=0;
	int tot=0;
	for(int i=1;i<=n;i++){
		if(tot+a[i]<=mid){
			tot+=a[i];
		}
		else{
			if(mid<a[i]) return false;//±ß½çÌõ¼þ 
			else{
				tot=a[i];
				tmp++;
			}
			
		}
	}
	if(tot!=0) tmp++;
	return tmp<=m;
}
int main(){
	cin>>n>>m;
	a.resize(n+1);
	int tot=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot+=a[i];
	}
	int l=1,r=tot;
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
