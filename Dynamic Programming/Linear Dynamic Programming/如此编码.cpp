#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1),c(n+1,1),b(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) c[i]=c[i-1]*a[i];
	int sum=0;
	for(int i=1;i<=n;i++){
		int t=m%c[i];
		b[i]=(t-sum)/c[i-1];
		sum+=c[i-1]*b[i];
	}
	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
	return 0;
}
/*


*/