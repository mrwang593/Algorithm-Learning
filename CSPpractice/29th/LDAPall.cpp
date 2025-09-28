#include<bits/stdc++.h>
using namespace std;
int ptr;//作为遍历s的指针 
string s;
vector<int>dn;
vector<vector<pair<int,int>>>atr;
string gettoken(){
	string res="";
	if(isdigit(s[ptr])){
		while(isdigit(s[ptr])){
			res+=s[ptr];
			++ptr;
		} 
	}
	else{
		res+=s[ptr];
		++ptr;
	}
	return res;
}
vector<int> work(vector<int>&tot){
	string t=gettoken();
	vector<int>res;
	if(!isdigit(t[0])){//如果是操作符 
		char op=t[0]; //保存操作符
		gettoken(); //跳过左括号
		vector<int>tmp1=work(tot);
		gettoken();//跳过右括号
		gettoken();//跳过左括号
		if(op=='&'){//如果是与直接从上一个集合中挑选符合这个的 
			res=work(tmp1);
		} 
		else{//如果是或就另开一个tmp，然后取交集 
			vector<int>tmp2=work(tot);
			tmp1.insert(tmp1.end(),tmp2.begin(),tmp2.end());
			sort(tmp1.begin(),tmp1.end());
			res.insert(res.end(),tmp1.begin(),unique(tmp1.begin(),tmp1.end())); 
		}
		gettoken();
	} 
	else{
		int k=stoi(t);
		char op=gettoken()[0];
		int v=stoi(gettoken());
		for(int i:tot){
			auto it=lower_bound(atr[i].begin(),atr[i].end(),{k,0});
			if(it==atr[i].end()||it->first!=k) continue;
			else{
				if((op==':'&&it->second==v)||(op=='~'&&it->second!=v)) res.push_back(i);
			}
		}
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	dn.resize(n),atr.resize(n);
	vector<int>tot(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>dn[i]>>x;
		atr[i].resize(x);
		for(int j=0;j<x;j++){
			int k,v;
			cin>>k>>v;
			atr[i][j]={k,v};
		}
		tot[i]=i;
	}
	int m;
	cin>>m;
	while(m--){
		cin>>s;
		ptr=0;
		vector<int>ans=work(tot);
		vector<int>res;
		for(int i:ans) res.push_back(dn[i]);
		sort(res.begin(),res.end());
		for(int i:res)cout<<i<<" ";
		cout<<"\n";
	}
	return 0; 
}
