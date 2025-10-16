#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	__int128 t=0;
	for(int i=1;i<=n;i++){
		t=2*t+2;
	}
	print(t);
	return 0;
} 
