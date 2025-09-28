#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	unordered_map<string,int>mp; 
	for(int i=0;i<n;i++){
		string t;
		for(int j=0;j<8;j++){
			cin>>s;
			t+=s;
		}
		mp[t]++;
		cout<<mp[t]<<"\n";
	}

	return 0;
} 
