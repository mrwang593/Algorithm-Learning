#include<bits/stdc++.h>
using namespace std;
int ptr;//��Ϊ����s��ָ�� 
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
	if(!isdigit(t[0])){//����ǲ����� 
		char op=t[0]; //���������
		gettoken(); //����������
		vector<int>tmp1=work(tot);
		gettoken();//����������
		gettoken();//����������
		if(op=='&'){//�������ֱ�Ӵ���һ����������ѡ��������� 
			res=work(tmp1);
		} 
		else{//����ǻ����һ��tmp��Ȼ��ȡ���� 
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
