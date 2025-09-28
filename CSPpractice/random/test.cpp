#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	vector<string>v;
	stringstream ss(s);
	string token;
	while(getline(ss,token,' ')){
		v.push_back(token);
	}
	for(string s:v) cout<<s<<" ";
	return 0;
} 
