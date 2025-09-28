#include<bits/stdc++.h>
using namespace std;
string tot;
int ptr;

// 合并同类项（直接操作数组）
void merge_to_array(vector<pair<int,int>> &terms, vector<int>& arr) {
    for(auto &p : terms) {
        if(p.first >= 0 && p.first <= 20) { // 限制次数范围
            arr[p.first] += p.second;
        }
    }
}

// 应用循环到当前块
vector<pair<int,int>> apply_loop(vector<pair<int,int>> &terms, string loopcnt) {
    vector<pair<int,int>> res;
    for(auto&x : terms) {
        if(loopcnt == "n") {
            res.push_back({x.first + 1, x.second}); // 次数+1
        } else {
            res.push_back({x.first, x.second * stoi(loopcnt)}); // 系数相乘
        }
    }
    return res;
}

string gettoken(){
	string res;
	while(tot[ptr]==' '&&ptr<tot.size()) ptr++;
	while(tot[ptr]!=' '&&ptr<tot.size()) res+=tot[ptr++];
	return res;
}

int main(){
	string s;
	while(getline(cin,s)) tot+=" "+s; 
	
	vector<int> exp(21,0); // 用数组存储次数0~20的系数
	stack<string> stl;
	stack<vector<pair<int,int>>> sto; // 临时存储(次数,系数)对
	
	string t=gettoken();
	stl.push(t);
	sto.push({});
	
	while((t=gettoken())!=""){
		if(t=="op"){
			string op=gettoken();
			if(op=="n") sto.top().push_back({1,1});
			else sto.top().push_back({0,stoi(op)});
		}
		else if(t=="loop"){
			string tmp=gettoken();
			stl.push(tmp);
			sto.push({});
		}
		else if(t=="end"){
			string loopcnt=stl.top();stl.pop();
			vector<pair<int,int>> tmp=sto.top();sto.pop();
			
			// 合并当前块的同类项（关键修复）
			map<int,int> merged;
			for(auto&p : tmp) merged[p.first] += p.second;
			tmp.clear();
			for(auto&p : merged) tmp.push_back(p);
			
			if(loopcnt=="begin"){
				merge_to_array(tmp, exp); // 合并到最终数组
			}
			else{
				vector<pair<int,int>> loop_res = apply_loop(tmp, loopcnt);
				sto.top().insert(sto.top().end(), loop_res.begin(), loop_res.end());
			}
		} 	
	}

	// 输出处理
	vector<pair<int,int>> ans;
	for(int i=20;i>=0;i--){
		if(exp[i]!=0) ans.emplace_back(i, exp[i]);
	}
	
	if(ans.empty()){
		cout<<"0"<<endl;
		return 0;
	}
	
	for(int i=0;i<ans.size();i++){
		int degree=ans[i].first;
		int coeff=ans[i].second;
		
		// 符号处理
		if(i>0){
			if(coeff>0) cout<<"+";
		}else{
			if(coeff<0) cout<<"-";
		}
		int abs_coeff=abs(coeff);
		
		// 系数处理
		if(degree==0 || abs_coeff!=1) cout<<abs_coeff;
		
		// 变量和指数
		if(degree>0){
			cout<<"n";
			if(degree>1) cout<<"^"<<degree;
		}
	}
	cout<<endl;
	
	return 0;
}

