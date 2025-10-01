#include<bits/stdc++.h>
using namespace std;
string s;
int n;
string f(string s,int &i){
	string res;
	i++;
	int m=0;
	while(isdigit(s[i])){
		m=m*10+(s[i]-'0');
		i++;
	}

	string t;
	 // 循环读取内容直到遇到 ']'
    while(s[i] != ']'){
        if(isalpha(s[i])){ 
            t += s[i];
            i++;
        }
        else if(s[i]=='['){ 
            t += f(s,i);
        }
    }
    i++; // 跳过 ']'
	for(int j=0;j<m;j++){
		res+=t;
	}
	return res;
}
int main(){
	cin>>s;
	n=s.size();
	for(int i=0;i<n;){
		if(isalpha(s[i])){
			cout<<s[i];
			i++;
		}
		else{
			cout<<f(s,i);
		}
	}
	return 0;
} 
