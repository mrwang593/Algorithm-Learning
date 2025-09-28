#include<bits/stdc++.h>
using namespace std;
struct People{
	int DN;
	int attri_num;//属性格数
	unordered_map<int,int>attri_mp;
};
int n;
vector<People>p;
void fix(string s,vector<bool>&ok){
		int t=1;
		size_t pos=s.find(':');
		if(pos==string::npos){
			t=0;
			pos=s.find('~');
		}
		int tmp_attri=stoi(s.substr(0,pos));
		int tmp_val=stoi(s.substr(pos+1));
		for(int i=1;i<=n;i++){
			if(p[i].attri_mp[tmp_attri]!=0&&p[i].attri_mp[tmp_attri]==tmp_val&&t) ok[i]=true;
			if(p[i].attri_mp[tmp_attri]!=0&&p[i].attri_mp[tmp_attri]!=tmp_val&&!t) ok[i]=true;
		}
		
}
int main(){

	cin>>n;
	p.resize(n+1);
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
		vector<bool>ok(n+1,false);
		if(s.find('&')==string::npos&&s.find('|')==string::npos){//单个表达式 
			fix(s,ok);
		}
		else{
			int t=-1;
			vector<vector<bool>>ok1(2,vector<bool>(n+1));
			int l=0,r=0,cnt=0;
			for(int i=0;i<s.size();i++){
				if(s[i-1]=='(') l=i;
				if(s[i+1]==')'){
					r=i;
					fix(s.substr(l,r-l+1),ok1[cnt++]);
				} 
			}
			if(s[0]=='&'){
				for(int i=1;i<=n;i++){
					ok[i]=ok1[0][i]&&ok1[1][i];
				}
			}
			else {
				for(int i=1;i<=n;i++){
					ok[i]=ok1[0][i]||ok1[1][i];
				}
			}
		}
		vector<int>res;
		res.reserve(n+1);
		for(int i=1;i<=n;i++){
			if(ok[i]) res.push_back(p[i].DN);
		}
		sort(res.begin(),res.end());
		for(int i:res) cout<<i<<" ";
		cout<<endl;
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
|(|(1:2)(3:1))(&(1:2)(2:3))

*/
