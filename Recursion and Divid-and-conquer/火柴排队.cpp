#include<bits/stdc++.h>
using namespace std;
const int mod=1e8-3;
vector<int>id;
long long res=0;
void quer(int l,int r){
	if(l>=r) return ;
	int m=l+(r-l)/2;
	quer(l,m);
	quer(m+1,r);
	vector<int>tmp;
	tmp.reserve(r-l+1);
	int i=l,j=m+1;
	while(i<=m&&j<=r){
		if(id[i]<=id[j]){
			tmp.push_back(id[i]);
			i++;
		}
		else{
			tmp.push_back(id[j]);
			j++;
			res=(res+m-i+1)%mod;
		}
	} 
	while(i<=m){
		tmp.push_back(id[i++]);
	}
	while(j<=r){
		tmp.push_back(id[j++]);
	}
	for(int i=0;i<=r-l;i++) id[i+l]=tmp[i];
	
}
int main(){
	int n;
	cin>>n;
	vector<int>a(n),b(n),t1(n),t2(n),pos(n); 
	id.resize(n); 
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	t1=a,t2=b;
	//建立映射，a中得第几分别在那个位置 
	sort(t1.begin(),t1.end());
	for(int i=0;i<n;i++){
		auto it=lower_bound(t1.begin(),t1.end(),a[i]);
		pos[it-t1.begin()]=i;
	}
	sort(t2.begin(),t2.end());
	for(int i=0;i<n;i++){
		auto it=lower_bound(t2.begin(),t2.end(),b[i]);
		id[i]=pos[it-t2.begin()];
	}
	quer(0,n-1);
	cout<<res;
	return 0;
} 
