#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>h;
	h.reserve(1e5+5);
	int x;
	while(cin>>x) h.push_back(x);
	int n=h.size();
	vector<int>t;
	for(int i=n-1;i>=0;i--){//反过来求解最长非递减子序列
		auto it=upper_bound(t.begin(),t.end(),h[i]);
		if(it==t.end()) t.push_back(h[i]);
		else t[it-t.begin()]=h[i];
	}
	cout<<t.size()<<"\n";
	cout<<1<<"\n";
	return 0;
}