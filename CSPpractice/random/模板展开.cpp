#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int ptr;
string s;
unordered_map<string,int>mp1;
unordered_map<string,vector<string>>mp2;
string gettoken() {
    string res = "";
    // 跳过空格
    while (ptr < s.size() && s[ptr] == ' ') ptr++;
    if (ptr >= s.size()) return res;

    // 连续的 [a-z0-9$] 都算一个 token
    while (ptr < s.size() && (isalnum(s[ptr]) || s[ptr] == '$')) {
        res += s[ptr++];
    }
    return res;
}
void dfs(string t,int &ret){
	if(mp2.count(t)==0){
		ret=(ret+mp1[t])%mod;
		return ;
	}
		for(string u:mp2[t]){
			if(u[0]=='$'){
				dfs(u.substr(1),ret);
			}
			else ret=(ret+u.size())%mod;
		}
}
void work(){
	char op=gettoken()[0];
	string name=gettoken();
if(op=='1'){
    string t;
    int ret=0; 
    while((t=gettoken())!=""){
        if(t[0]=='$') {
            string var = t.substr(1);
            ret = (ret + mp1[var]) % mod;  // 只能取已知值
        }
        else ret = (ret + t.size()) % mod;
    }
    mp1[name] = ret;
    mp2.erase(name);
}

	else if(op=='2'){
		string t; 
		mp2[name].clear();
		while((t=gettoken())!=""){
			mp2[name].push_back(t);
		}
		mp1.erase(name);
	}
	else{
		if(mp2.count(name)==0)
			cout<<mp1[name]%mod<<endl;
		else{
			string t=name;
			int ret=0;
			dfs(t,ret);
			cout<<ret%mod<<"\n";
		}
	}
}
int main(){
	int n;
	cin>>n;
	cin.ignore(); 
	while(n--){
		getline(cin,s);
		ptr=0;
		work();
	}
	return 0;
} 
/*
6
1 a hello
1 b world
2 c $a $b
3 c
1 a hi
3 c

*/
/*
5
1 var value
3 var
3 val
1 var $var $val $var
3 var

*/
/*
6
1 a hello
1 b world
2 c $a $b
3 c
1 a hi
3 c

*/
/*
5
1 var value
3 var
3 val
1 var $var $val $var
3 var

*/
