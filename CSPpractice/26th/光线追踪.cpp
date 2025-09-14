#include<bits/stdc++.h>
using namespace std;
struct T{
	int x,y;
};
unordered_map<int,vector<T>>id_map;
map<pair<int,int>,pair<int,double>>mp;//代表坐标镜面坐标的斜率和折损系数
void f1(int x1,int y1,int x2,int y2,double a,int id){
 int k=(y1-y2)/(x1-x2);
	if(x1>x2) swap(x1,x2),swap(y1,y2);
	for(int i=1;i<x2-x1;i++){
		mp[{x1+i,y1+k*i}]={k,a};
		id_map[id].push_back({x1+i,y1+k*i});//bug1变量名重复
	}
}
void f2(int id){
	for(auto [x,y]:id_map[id]){
		mp.erase({x,y});
	}
	id_map.erase(id);
}
//d=0 1 2 3
vector<int> f3(int x,int y,int d,double I,int t){
	vector<int>ans(3);
	for(int i=1;i<=t;i++){//bug2先走一步，不然不符合题目中对最后走到镜子写出反射后的光强的要求
			if(d==0) x++;
		else if(d==1) y++;
		else if(d==2) x--;
		else y--;
		if(mp.count({x,y})){
			auto [k,a]=mp[{x,y}];
			I*=a;

   			if((d==0&&k==-1)||(d==2&&k==1)) d=3;//y轴负
			else if((d==2&&k==-1)||(d==0&&k==1)) d=1;//y轴正//bug3
			else if((d==3&&k==-1)||(d==1&&k==1)) d=0;//x轴正
			else if((d==1&&k==-1)||(d==3&&k==1))d=2;
		}

	}
	I=floor(I);
	if(I==0) ans[0]=ans[1]=ans[2]=0;
	else ans[0]=x,ans[1]=y,ans[2]=I;
	return ans;
}
int main(){
	int m;
	cin>>m;
	int op;
	for(int i=1;i<=m;i++){
		cin>>op;
		if(op==1){
			int x1,y1,x2,y2; double a;
			cin>>x1>>y1>>x2>>y2>>a;
			f1(x1,y1,x2,y2,a,i);
		}
		else if(op==2){
			int id;
			cin>>id;
			f2(id);
		}
		else {
			int x,y,d,t;
			double I;
			cin>>x>>y>>d>>I>>t;
			auto ans=f3(x,y,d,I,t);
			cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
		}
	}
	return 0;
}