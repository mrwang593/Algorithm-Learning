#include <bits/stdc++.h>
using namespace std;
vector<int> a;
long long cnt = 0;
void f(int l, int r)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	if (l == r)
		return;
	int m = l + (r - l) / 2;
	f(l, m);
	f(m + 1, r);
	vector<int> t;
	for (int i = m + 1; i <= r; i++)
		t.push_back(a[i]);
	sort(t.begin(), t.end());
	for (int i = l; i <= m; i++)
	{
		auto it = lower_bound(t.begin(), t.end(), a[i]);
		cnt += it - t.begin();
	}
}
int main()
{
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	f(0, n - 1);
	cout << cnt;
	return 0;
}
