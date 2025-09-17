#include<bits/stdc++.h>
using namespace std;
int n;
double i;
double f(double x,double k){
	return x*pow(1+i,-k);
}
int main(){
	cin>>n>>i;
	double sum=0;
	for(int i=0;i<=n;i++){
		double x;
		cin>>x;
		sum+=f(x,(double)i);
	}
	cout<<fixed<<setprecision(3)<<sum;
	return 0;
} 
