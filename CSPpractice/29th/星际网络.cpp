#include<bits/stdc++.h>
using namespace std;
int n,q;
map<pair<string,string>,int>mp;
void f1(){
	int id;
	string l,r;
	cin>>id>>l>>r;
	auto it=mp.upper_bound({l,r});
	if(it==mp.end()){
		mp.insert(it,{{l,r},id});
		cout<<"YES\n";
		return;
	}
	else{
		string L=prev(it)->first.second;
		string R=it->first.first;
		if(l>L&&r<R){
			mp.insert(it,{{l,r},id});
			cout<<"YES\n";
			return; 
		}
		else{
			if(l<=L&&r>L&&prev(it)->second==id){
				mp.insert(it,{{l,r},id});
				cout<<"YES\n";
				return;
			}
			if(r>=R&&l<R&&it->second==id){
				mp.insert(it,{{l,r},id});
				cout<<"YES\n";
				return;
			}
		}
	}
	cout<<"NO\n";
	return;
}
void f2(){
	string s;
	cin>>s;
	auto it=mp.upper_bound({s,s});
	it=prev(it);
	if(it==mp.end()){
		cout<<0<<"\n";
		return;
	}
	else{
		string l=it->first.first;
		string r=it->first.second;
		if(s>=l&&s<=r){
			cout<<it->second<<"\n";
			return;
		}
	}
	cout<<0<<"\n";
	return;
}
void f3(){
	string l,r;
	cin>>l>>r;
	auto it=mp.upper_bound({l,r});
	it=prev(it);
	if(it==mp.end()){
		cout<<0<<"\n";
		return;
	}
	if(it->first.first<=l&&it->first.second>=r) cout<<it->second<<"\n";
	else cout<<0<<"\n";
}
int main(){
 	cin>>n>>q;
 	int op;
 	while(q--){
 		cin>>op;
 		if(op==1) f1();
 		else if(op==2) f2();
 		else f3();
	}
	return 0;
} 
