#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
const int LG = 20;
int n, q;
vector<int> h;
int st1[MAXN][LG] = {0}; // 最大值
int st2[MAXN][LG] = {0}; // 最小值
void solve()
{
	for (int i = 1; i <= n; i++)
	{
		st1[i][0] = h[i];
		st2[i][0] = h[i];
	}
	for (int i = 1; (1 << i) <= n; i++)
	{
		for (int j = 1; j + (1 << i) - 1 <= n; j++)
		{
			st1[j][i] = max(st1[j][i - 1], st1[j + (1 << (i - 1))][i - 1]);
			st2[j][i] = min(st2[j][i - 1], st2[j + (1 << (i - 1))][i - 1]);
		}
	}
}
int main()
{
	cin >> n >> q;
	h.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	solve();
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		int k = floor(log2(r - l + 1));
		int maxm = max(st1[l][k], st1[r - (1 << k) + 1][k]);
		int minm = min(st2[l][k], st2[r - (1 << k) + 1][k]);
		cout << maxm - minm << "\n";
	}
	return 0;
}
