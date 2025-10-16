#include<bits/stdc++.h>
using namespace std;
string s;
int ptr=0;
string gettoken(){
	string res="";
	while(ptr<s.size()&&s[ptr]==' ') ptr++;
	if(s[ptr]=='['||s[ptr]==']'){
		res+=s[ptr];
		ptr++;
		return res;	
	}
	else if(isalpha(s[ptr])){
		while(ptr<s.size()&&isalpha(s[ptr])){
			res+=s[ptr];
			ptr++;
		}
	}
	else if(ptr<s.size()&&isdigit(s[ptr])){
		while(ptr<s.size()&&isdigit(s[ptr])){
			res+=s[ptr];
			ptr++;
		}
	}
	return res;
}
long long solve(){
	long long res=0;
	string op;
	while(1){
		op=gettoken();
		if(op=="") return res;
		if(op=="[") continue;
		if(op=="]") return res;
		if(op=="FD"){
			int t=stoi(gettoken());
			res+=t;
		} 
		else if(op=="BK"){
			int t=stoi(gettoken());
			res-=t;
		}
		else if(op=="REPEAT"){
			int t=stoi(gettoken());
			long long s=solve(); 
			res+=t*s;
		}
	}
} 
int main(){
	getline(cin,s);
	long long res=solve();
	cout<<abs(res);
	return 0;
} 
