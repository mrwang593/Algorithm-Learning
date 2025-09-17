#include<bits/stdc++.h>
using namespace std;
__int128 f(__int128 x,__int128 y){
	return (x-y)*(x-y);
}
inline void print(__int128 x){
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
int main(){
	multiset<__int128>vs={0,1000000000};
	__int128 res=0;
	for(auto it=vs.begin();it!=vs.end();it++){
				__int128 l=it==vs.begin()?INT_MAX:f(*it,*prev(it));
				__int128 r=next(it)==vs.end()?INT_MAX:f(*it,*next(it));
				res+=min(l,r);
	}
	cout<<acos(-1);
	return 0;
} 
