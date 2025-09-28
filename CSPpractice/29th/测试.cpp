#include<bits/stdc++.h>
using namespace std;

int main(){
	map<pair<string,string>,int>mp={{{"adc","abd"},1}};
	auto it=mp.upper_bound({"abc","abd"});
	mp.insert(it,{{"dsaf","fasd"},1});
	for(auto it:mp){
		cout<<it.first.first<<" "<<it.second<<endl;
	}
	return 0;
} 
