#include <bits/stdc++.h>
using namespace std;
vector<int> a;
void quicksort(vector<int> &a, int l, int r)
{
	if (l == r)
	{
		return;
	}
	int mid = (l + r) / 2;
	quicksort(a, l, mid);
	quicksort(a, mid + 1, r);
	int i = 0, j = 0, k = l;
	int n = mid - l + 1, m = r - mid;
	vector<int> b(n), c(m);
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i + l];
	}
	for (int i = 0; i < m; i++)
	{
		c[i] = a[i + mid + 1];
	}
	while (i < n && j < m)
	{
		if (b[i] <= c[j])
		{
			a[k++] = b[i++];
		}
		else
		{
			a[k++] = c[j++];
		}
	}
	while (i < n)
	{
		a[k++] = b[i++];
	}
	while (j < m)
	{
		a[k++] = c[j++];
	}
}
int main()
{
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	quicksort(a, 0, n - 1);
	for (int i : a)
		cout << i << " ";
	return 0;
}
