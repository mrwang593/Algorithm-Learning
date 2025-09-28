#include<bits/stdc++.h>
using namespace std;
struct People{
	int DN;
	int attri_num;// Ù–‘∏Ò ˝
	unordered_map<int,int>attri_mp;
};
int main(){
	int n;
	cin>>n;
	vector<People>p(n+1);
	for(int i=1;i<=n;i++){
		cin>>p[i].DN>>p[i].attri_num;
		for(int j=1;j<=p[i].attri_num;j++) {
			int x,y;
			cin>>x>>y;
			p[i].attri_mp[x]=y;
		}
	}
	int m;
	cin>>m;
	while(m--){
		string s;
		cin>>s;
		int t=1;
		size_t pos=s.find(':');
		if(pos==string::npos){
			t=0;
			pos=s.find('~');
		}
		int tmp_attri=stoi(s.substr(0,pos));
		int tmp_val=stoi(s.substr(pos+1));
		vector<int>tmp;
		for(int i=1;i<=n;i++){
			if(p[i].attri_mp[tmp_attri]!=0&&p[i].attri_mp[tmp_attri]==tmp_val&&t) tmp.push_back(p[i].DN);
			if(p[i].attri_mp[tmp_attri]!=0&&p[i].attri_mp[tmp_attri]!=tmp_val&&!t) tmp.push_back(p[i].DN);
		}
		sort(tmp.begin(),tmp.end());
		for(int i:tmp) cout<<i<<" ";
		cout<<"\n";
	}
	return 0;
} 

/*

2
1 2 1 2 2 3
2 2 2 3 3 1
4
1:2
3~2
&(1:2)(2:3)
|(1:2)(3:1)

*/
