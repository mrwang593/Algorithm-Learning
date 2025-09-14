#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,L,S;
	cin>>n>>L>>S;

	set<pair<int,int>>s;//存储树的坐标
	unordered_map<int,vector<int>>mp;//存储树坐标为x的所有y坐标
	vector<pair<int,int>>a(n);

	for(int k=0;k<n;k++){
		int i,j;
		cin>>i>>j;
		a[i]={j,i};
		s.insert({j,i});
		mp[j].push_back(i);
	}
	vector<vector<int>>b(S+1,vector<int>(S+1));
	for(int i=0;i<=S;i++){
		for(int j=0;j<=S;j++){
			cin>>b[S-i][j];
		}
	}
	int res=0;
	for(int i=0;i<n;i++){
		int x=a[i].first,y=a[i].second;
		if(x+S>L||y+S>L) continue;
		bool ok=true;
		for(int j=0;j<=S;j++){
			int cnt1=0;
			for(int i=0;i<=S;i++){
				if(b[i][j]){
					int nx=x+j,ny=y+i;
					if(s.count({nx,ny})==0){
						ok=false;
					}
					cnt1++;
				}
			}
			int cnt2=0;
			for(int v:mp[j+x]){
				if(v-y>=0&&v-y<=S) cnt2++;
			}
			if(cnt1!=cnt2) ok=false;
		}

		if(ok)res++;
	}
	cout<<res;
	return 0;
}
/*
5 5 2
0 0
1 1
2 2
3 3
4 4
0 0 0
0 1 0
1 0 0

*/
