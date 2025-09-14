#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<double>a(n+1);
	double sum=0;
	double sum2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		sum2+=a[i]*a[i];
	}
	double aver=sum/n;
	double d=(sum2-sum*sum/n)/n;
	for(int i=1;i<=n;i++){
		cout<<fixed<<setprecision(15)<<(a[i]-aver)/sqrt(d)<<"\n";
	}
	return 0;
}
