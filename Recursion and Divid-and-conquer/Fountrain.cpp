#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int LG = 20;
int d[MAXN], c[MAXN];
int nxt[MAXN][LG], sum[MAXN][LG];
int n, q;
void prefix()
{
	stack<int> st;
	for (int i = 1; i <= n; i++)
	{
		while (!st.empty() && d[st.top()] < d[i])
		{
			nxt[st.top()][0] = i;
			sum[st.top()][0] = c[i];
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty())
	{
		nxt[st.top()][0] = 0;
		//		sum[st.top()][0]=INT_MAX;//������ײ�ˮ��
		st.pop();
	}
}
void build()
{
	for (int i = 1; (1 << i) <= n; i++)
	{
		for (int j = 1; j + (1 << i) <= n; j++)
		{
			nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
			sum[j][i] = sum[j][i - 1] + sum[nxt[j][i - 1]][i - 1];
		}
	}
}
int query(int r, int v)
{
	if (v <= c[r])
	{
		return r;
	}
	v -= c[r];
	for (int i = 18; i >= 0; i--)
	{
		if (nxt[r][i] != 0 && sum[r][i] < v)
		{
			v -= sum[r][i];
			r = nxt[r][i];
		}
	}
	return nxt[r][0];
}
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> d[i] >> c[i];
	prefix();
	build();
	while (q--)
	{
		int r, v;
		cin >> r >> v;
		cout << query(r, v) << "\n";
	}
	return 0;
}
