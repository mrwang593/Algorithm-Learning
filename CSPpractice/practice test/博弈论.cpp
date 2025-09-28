#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		long long tota=0, totb=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			tota+=x;
		}
		for(int i=1;i<=m;i++){
			int x;
			cin>>x;
			totb+=x;
		}
		if(tota>totb){
			cout<<"Alice\n";
		}
		else  if(totb>tota){
			cout<<"Bob\n";
		}
		else{
			cout<<"Draw\n";
		}
	}
	return 0;
}
