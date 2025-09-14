#include <bits/stdc++.h>
using namespace std;

struct Point { int x,y; };
unordered_map<int, vector<Point>> id_map;
map<pair<int,int>, pair<int,double>> mp;
map<int, set<int>> row, col; // row[y] 存这一行的镜子点x, col[x] 存这一列的镜子点y

void f1(int x1,int y1,int x2,int y2,double a,int id){
    if(x1>x2) swap(x1,x2), swap(y1,y2);
    int k = (y2-y1 == x2-x1 ? 1 : -1);
    for(int step=1; step<x2-x1; step++){
        int nx = x1+step, ny = y1+k*step;
        mp[{nx,ny}] = {k,a};
        row[ny].insert(nx);
        col[nx].insert(ny);
        id_map[id].push_back({nx,ny});
    }
}

void f2(int id){
    for(auto [x,y]:id_map[id]){
        mp.erase({x,y});
        row[y].erase(x);
        col[x].erase(y);
    }
    id_map.erase(id);
}

vector<int> f3(int x,int y,int d,double I,int t){
    while(t>0 && I>=1){
        int nx=x,ny=y;
        if(d==0){ // →
            auto it = row[y].upper_bound(x);
            int dist = it==row[y].end()? t : min(t, *it-x);
            nx = x+dist, ny=y;
            t -= dist;
            if(it!=row[y].end() && *it==nx ){//还能走到镜子那里
                auto [k,a]=mp[{nx,ny}];
                I*=a;
                if(k==1){ if(d==0)d=1; else if(d==1)d=0; else if(d==2)d=3; else d=2; }
                else    { if(d==0)d=3; else if(d==3)d=0; else if(d==1)d=2; else d=1; }
            }
        }
        else if(d==2){ // ←
            auto it = row[y].lower_bound(x);
            if(it==row[y].begin()){ int dist=t; nx=x-dist; ny=y; t=0; }
            else {
                --it;
                int dist = min(t, x-*it);
                nx=x-dist; ny=y; t-=dist;
                if(*it==nx ){
                    auto [k,a]=mp[{nx,ny}];
                    I*=a;
                    if(k==1){ if(d==0)d=1; else if(d==1)d=0; else if(d==2)d=3; else d=2; }
                    else    { if(d==0)d=3; else if(d==3)d=0; else if(d==1)d=2; else d=1; }
                }
            }
        }
        else if(d==1){ // ↑
            auto it = col[x].upper_bound(y);
            int dist = it==col[x].end()? t : min(t, *it-y);
            nx=x; ny=y+dist; t-=dist;
            if(it!=col[x].end() && *it==ny ){
                auto [k,a]=mp[{nx,ny}];
                I*=a;
                if(k==1){ if(d==0)d=1; else if(d==1)d=0; else if(d==2)d=3; else d=2; }
                else    { if(d==0)d=3; else if(d==3)d=0; else if(d==1)d=2; else d=1; }
            }
        }
        else { // ↓
            auto it = col[x].lower_bound(y);
            if(it==col[x].begin()){ int dist=t; nx=x; ny=y-dist; t=0; }
            else {
                --it;
                int dist=min(t,y-*it);
                nx=x; ny=y-dist; t-=dist;
                if(*it==ny ){
                    auto [k,a]=mp[{nx,ny}];
                    I*=a;
                    if(k==1){ if(d==0)d=1; else if(d==1)d=0; else if(d==2)d=3; else d=2; }
                    else    { if(d==0)d=3; else if(d==3)d=0; else if(d==1)d=2; else d=1; }
                }
            }
        }
        x=nx; y=ny;
    }
    if(I<1) return {0,0,0};
    return {x,y,(int)floor(I)};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; cin>>m;
    for(int i=1;i<=m;i++){
        int op; cin>>op;
        if(op==1){
            int x1,y1,x2,y2; double a;
            cin>>x1>>y1>>x2>>y2>>a;
            f1(x1,y1,x2,y2,a,i);
        }
        else if(op==2){
            int id; cin>>id;
            f2(id);
        }
        else {
            int x,y,d,t; double I;
            cin>>x>>y>>d>>I>>t;
            auto ans=f3(x,y,d,I,t);
            cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
        }
    }
}
