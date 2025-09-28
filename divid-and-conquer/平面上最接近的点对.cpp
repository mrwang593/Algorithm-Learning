#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<pair<int,int>>a(n);
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[i]={x,y};
	}
	double minm=1e10;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			minm=min(minm,sqrt(pow((double)a[i].first-a[j].first,2)+pow((double)a[i].second-a[j].second,2)));
		}
	}
	cout<<fixed<<setprecision(4)<<minm;
	return 0;
} 
